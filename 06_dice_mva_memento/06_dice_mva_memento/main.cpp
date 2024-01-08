#include "dicegui.h"
#include <QApplication>

int main(int argc, char *argv[]) {
  QApplication a(argc, argv);

  DiceGUI d;
  d.show();

  return a.exec();
}
