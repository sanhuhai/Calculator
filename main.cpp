#include "QTCalculator.h"
#include <QtWidgets/QApplication>
#include <QPushButton>
#include <QObject>
#include <QWidget>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QTCalculator w;
    w.show();
    return a.exec();
}
