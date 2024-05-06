#include <QApplication>
#include "SendWindow.h"
#include "ReceiveWindow.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    //Objects
    SendWindow sendWindow;
    ReceiveWindow receiveWindow;

    // Connect the imageSent signal from SendWindow to the receiveImage slot in ReceiveWindow
    //connect(Object1, Signal1, Object2, Slot1)
    QObject::connect(&sendWindow, &SendWindow::imageSent, &receiveWindow, &ReceiveWindow::receiveImage);

    // Connect the clearSignal from SendWindow to the clearDrawing slot in ReceiveWindow
    QObject::connect(&sendWindow, &SendWindow::clearSignal, &receiveWindow, &ReceiveWindow::clearDrawing);

    sendWindow.resize(800, 800);
    receiveWindow.resize(800, 800);

    sendWindow.show();
    receiveWindow.show();

    return app.exec();
}
