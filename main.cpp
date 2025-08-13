#include "mainclient.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainClient client;
    client.show();
    return a.exec();
}
