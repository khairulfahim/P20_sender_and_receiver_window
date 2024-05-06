#ifndef SENDWINDOW_H
#define SENDWINDOW_H

#include <QMainWindow>
#include <QImage>
#include <QMouseEvent>
#include <QPushButton>
#include <QDataStream>
#include <QColorDialog>

class SendWindow : public QMainWindow {
    Q_OBJECT

public:
    SendWindow(QWidget *parent = nullptr);

signals:
    void imageSent(const QByteArray &imageData);
    void clearSignal(); // New signal for clearing the drawing

public slots:
    void clearDrawing();
    void drawLine(const QPoint& startPos, const QPoint& endPos, const QColor& color);

protected:
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
    void paintEvent(QPaintEvent *event) override;
    void serializeImage();

private:
    bool drawing;
    QPoint lastPos;
    QPoint startPos; // Store the start position of the line
    QImage image;
    QColor paintColor;
    QPushButton *clearButton;
};

#endif // SENDWINDOW_H
