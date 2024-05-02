#include "ReceiveWindow.h"
#include <QPainter>

ReceiveWindow::ReceiveWindow(QWidget *parent) : QMainWindow(parent) {
    setWindowTitle("Receive Window");
}

void ReceiveWindow::receiveImage(const QImage &image) {
    receivedImage = image;
    update();
}

void ReceiveWindow::paintEvent(QPaintEvent *event) {
    QMainWindow::paintEvent(event);
    QPainter painter(this);
    painter.drawImage(0, 0, receivedImage);
}

void ReceiveWindow::clearDrawing() {
    receivedImage.fill(Qt::white);
    update();
}
