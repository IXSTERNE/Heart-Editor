#include <QApplication>
#include "MainWindow.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    app.setWindowIcon(QIcon(":/resources/assets/heart.png"));
    QCoreApplication::setApplicationName("Text Editor");
    MainWindow mainWindow;
    mainWindow.show();
    return app.exec();
}
