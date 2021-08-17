#include <QtWidgets>
#include <stdlib.h>

#include "./golfield.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    GolField *field = new GolField;
    field->show();
    field->start();

    return app.exec();
}
