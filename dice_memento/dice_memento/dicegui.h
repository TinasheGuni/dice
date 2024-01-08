#ifndef DICEGUI_H
#define DICEGUI_H

#include "randomnumbercaretaker.h"
#include <QStringListModel>
#include <QtWidgets>

class DiceGUI : public QWidget {
  Q_OBJECT
public:
  explicit DiceGUI(QWidget *parent = nullptr);

private slots:
  void buttonClicked();
  void getMemento(QModelIndex index);

private:
  int count;
  RandomNumberCaretaker caretaker;
  RandomNumberGenerator generator;
  QStringList rolls;
  QStringListModel model;
  void setPics(QList<quint32> nums);
  QString stringRollNums(QList<quint32> nums) const;
  int modelToindex(QString s) const;

  void setupGUI();
  QListView *listView = nullptr;
  QPushButton *buttonRoll = nullptr;
  QLabel *pic1 = nullptr;
  QLabel *pic2 = nullptr;
  QLabel *pic3 = nullptr;
  QLabel *pic4 = nullptr;
  QLabel *pic5 = nullptr;
  QLabel *pic6 = nullptr;
};

#endif // DICEGUI_H
