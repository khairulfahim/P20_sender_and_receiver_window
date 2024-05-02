#include "SendWindow.h"
#include <QPainter>

SendWindow::SendWindow(QWidget *parent) : QMainWindow(parent), drawing(false) {
    setWindowTitle("Send Window");
    image = QImage(size(), QImage::Format_ARGB32_Premultiplied);
    image.fill(Qt::white);
    paintColor = Qt::black;

    clearButton = new QPushButton("Clear", this);
    clearButton->move(10, 10);
    connect(clearButton, &QPushButton::clicked, this, &SendWindow::clearDrawing);
}

void SendWindow::mousePressEvent(QMouseEvent *event) {
    if (event->button() == Qt::LeftButton) {
        drawing = true;
        lastPos = event->pos();
    }
}

void SendWindow::mouseMoveEvent(QMouseEvent *event) {
    if ((event->buttons() & Qt::LeftButton) && drawing) {
        QPainter painter(&image);
        painter.setPen(QPen(paintColor, 2));
        painter.drawLine(lastPos, event->pos());
        lastPos = event->pos();
        update();
    }
}

void SendWindow::mouseReleaseEvent(QMouseEvent *event) {
    if (event->button() == Qt::LeftButton && drawing) {
        drawing = false;
        emit imageSent(image);
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
