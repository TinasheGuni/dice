#include "dicegui.h"

#include <QApplication>

int main(int argc, char *argv[]) {
  QApplication a(argc, argv);

  DiceGUI gui;
  gui.show();

  return a.exec();
}
