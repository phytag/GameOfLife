#include <QtWidgets>
#include "./golmain.h"

int main(int argc, char *argv[])
{
    //new change
    QApplication app(argc, argv);
    GolMain mainWindow;
    mainWindow.show();

    return app.exec();
}
