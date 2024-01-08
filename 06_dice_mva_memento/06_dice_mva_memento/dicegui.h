#ifndef DICEGUI_H
#define DICEGUI_H

#include <QStringListModel>
#include <QtWidgets>

class DiceGUI : public QWidget {
  Q_OBJECT
public:
  explicit DiceGUI(QWidget *parent = nullptr);

public slots:

private:
  int count;
  void setPics(QList<qint32> nums);

  void setupGUI();
  QListView *listView;
  QPushButton *buttonRoll;
  QLabel *pic1 = nullptr;
  QLabel *pic2 = nullptr;
  QLabel *pic3 = nullptr;
  QLabel *pic4 = nullptr;
  QLabel *pic5 = nullptr;
  QLabel *pic6 = nullptr;
};

#endif // DICEGUI_H
