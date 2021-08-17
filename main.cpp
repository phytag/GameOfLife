#include <QtWidgets>
#include "./golmain.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    GolMain mainWindow;
    mainWindow.show();

    return app.exec();
}
