#ifndef RECEIVEWINDOW_H
#define RECEIVEWINDOW_H

#include <QMainWindow>
#include <QImage>

class ReceiveWindow : public QMainWindow {
    Q_OBJECT

public:
    ReceiveWindow(QWidget *parent = nullptr);

public slots:
    void receiveImage(const QImage &image);
    void clearDrawing(); // New slot for clearing the drawing

protected:
    void paintEvent(QPaintEvent *event) override;

private:
    QImage receivedImage;
};

#endif // RECEIVEWINDOW_H
