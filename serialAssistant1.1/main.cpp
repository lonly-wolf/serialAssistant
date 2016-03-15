#include "mainwindow.h"
#include <QApplication>
#include<QTextCodec>




int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setOrganizationName("focus-ebeam");   //设置QSettings存储
    a.setOrganizationDomain("focus-ebeam.com");
    a.setApplicationName("QtDebugAssistant");
    MainWindow w;
    w.show();
    return a.exec();
}
