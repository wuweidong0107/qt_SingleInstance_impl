#include "mainwindow.h"

#include <QApplication>
#include "singleinstance.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    
    SingleInstance si("My_APP");
    if (si.hasPreviousInstance()) {
        qDebug() << "Another one is running...";
        return EXIT_SUCCESS;
    }
    
    if (!si.start()) {
        qDebug() << si.getLastErrorString();
        return EXIT_FAILURE;
    }
    
    MainWindow w;
    w.show();
    return a.exec();
}
