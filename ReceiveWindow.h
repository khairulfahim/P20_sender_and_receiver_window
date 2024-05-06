#ifndef RECEIVEWINDOW_H
#define RECEIVEWINDOW_H

#include <QMainWindow>
#include <QImage>
#include <QByteArray>
#include <QDataStream>

class ReceiveWindow : public QMainWindow {
    Q_OBJECT

public:
    ReceiveWindow(QWidget *parent = nullptr);

public slots:
    void receiveImage(const QByteArray &imageData);
    void clearDrawing();

protected:
    void paintEvent(QPaintEvent *event) override;
    void deserializeImage(const QByteArray &imageData);

private:
    QImage receivedImage;
};

#endif // RECEIVEWINDOW_H
