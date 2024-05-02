#include <QApplication>
#include "SendWindow.h"
#include "ReceiveWindow.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    SendWindow sendWindow;
    ReceiveWindow receiveWindow;

    // Connect the clearSignal from SendWindow to the clearDrawing slot in ReceiveWindow
    QObject::connect(&sendWindow, &SendWindow::clearSignal, &receiveWindow, &ReceiveWindow::clearDrawing);

    // Connect the imageSent signal from SendWindow to the receiveImage slot in ReceiveWindow
    QObject::connect(&sendWindow, &SendWindow::imageSent, &receiveWindow, &ReceiveWindow::receiveImage);

    sendWindow.show();
    receiveWindow.show();

    return app.exec();
}
