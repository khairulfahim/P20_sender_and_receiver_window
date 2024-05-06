#include "ReceiveWindow.h"
#include <QPainter>

ReceiveWindow::ReceiveWindow(QWidget *parent) : QMainWindow(parent) {
    setWindowTitle("Receive Window");
}

void ReceiveWindow::receiveImage(const QByteArray &imageData) {
    //data deserialization
    QDataStream stream(imageData);
    stream >> receivedImage;
    update();
}

void ReceiveWindow::paintEvent(QPaintEvent *event) {
    QMainWindow::paintEvent(event);
    QPainter painter(this);
    //draw start from (0, 0)
    painter.drawImage(0, 0, receivedImage);
}

void ReceiveWindow::clearDrawing() {
    receivedImage = QImage(receivedImage.size(), receivedImage.format());
    receivedImage.fill(Qt::white);
    update();
}
