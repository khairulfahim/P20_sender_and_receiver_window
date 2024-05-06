#include "SendWindow.h"
#include <QPainter>
#include <QDebug>
#include <QColorDialog>

SendWindow::SendWindow(QWidget *parent) : QMainWindow(parent), drawing(false) {
    setWindowTitle("Send Window");
    image = QImage(size(), QImage::Format_ARGB32_Premultiplied);
    image.fill(Qt::white);
    //paintColor = Qt::black;

    clearButton = new QPushButton("Clear", this);
    clearButton->move(10, 10);
    connect(clearButton, &QPushButton::clicked, this, &SendWindow::clearDrawing);
}

void SendWindow::drawLine(const QPoint& startPos, const QPoint& endPos, const QColor& color) {
    QPainter painter(&image);
    painter.setPen(QPen(color, 2));
    painter.drawLine(startPos, endPos);
    update();
}

void SendWindow::serializeImage(){
    QByteArray imageData;
    QDataStream stream(&imageData, QIODevice::WriteOnly);
    stream << this->image;
    emit imageSent(imageData);
}

void SendWindow::mousePressEvent(QMouseEvent *event) {
    if (event->button() == Qt::LeftButton) { //left click to draw
        drawing = true;
        lastPos = event->pos();
        startPos = lastPos; // Update the start position of the line
    }
}

void SendWindow::mouseMoveEvent(QMouseEvent *event) {
    if ((event->buttons() & Qt::LeftButton) && drawing) {
        //draw the last position of the line as the mouse moving
        drawLine(lastPos, event->pos(), Qt::blue);
        lastPos = event->pos();
        //data serialization
        serializeImage();
    }
}

void SendWindow::mouseReleaseEvent(QMouseEvent *event) {
    if (event->button() == Qt::LeftButton && drawing) { //release left click to stop drawing
        drawing = false;
    }
}

void SendWindow::paintEvent(QPaintEvent *event) {
    QMainWindow::paintEvent(event);
    QPainter painter(this);
    painter.drawImage(0, 0, image);
}

void SendWindow::clearDrawing() {
    image.fill(Qt::white);
    update();
    emit clearSignal(); // Emit the clearSignal when drawing is cleared
}
