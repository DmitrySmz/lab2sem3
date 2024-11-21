#include "mainwindow.h"
#include <QLabel>
#include <QApplication>
#include "dinamicArray.h"
#include "sorter.h"
#include "timeTests.h"

int main(int argc, char *argv[])
{

    // testBubbleSorter();
    //testBinaryInsertionSorter();
    testQuickSorter();
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
