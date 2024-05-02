#ifndef SENDWINDOW_H
#define SENDWINDOW_H

#include <QMainWindow>
#include <QImage>
#include <QMouseEvent>
#include <QPushButton>

class SendWindow : public QMainWindow {
    Q_OBJECT

public:
    SendWindow(QWidget *parent = nullptr);

signals:
    void imageSent(const QImage &image);
    void clearSignal(); // New signal for clearing the drawing

protected:
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
    void paintEvent(QPaintEvent *event) override;

public slots:
    void clearDrawing();

private:
    bool drawing;
    QPoint lastPos;
    QImage image;
    QColor paintColor;
    QPushButton *clearButton;
};

#endif // SENDWINDOW_H
