#include "Tests/AutoTest.h"
#include <QApplication>

int main(int argc, char *argv[])
{
   QApplication a(argc, argv);

   AutoTest::run(argc, argv);

    return 0;
}
