#include <QApplication>
#include "deviceui.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    DeviceUI mainWindow;
    mainWindow.resize(600, 400);
    mainWindow.show();

    return app.exec();
}
