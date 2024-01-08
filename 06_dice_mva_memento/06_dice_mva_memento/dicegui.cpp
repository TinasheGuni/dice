#include "dicegui.h"

DiceGUI::DiceGUI(QWidget *parent)
    : QWidget{parent}, listView(new QListView),
      buttonRoll(new QPushButton("Roll dice 6 times")), pic1(new QLabel),
      pic2(new QLabel), pic3(new QLabel), pic4(new QLabel), pic5(new QLabel),
      pic6(new QLabel) {
  setupGUI();
  count = 0;

  //  listView->setFixedSize(170);
}

void DiceGUI::setPics(QList<qint32> nums) {
  QList<QPixmap> pixmaps;
  foreach (quint32 i, nums) {
    QString fName(":/images/");
    fName.append(QString::number(i, 10));
    fName.append(".png");
    QPixmap pixmap(fName);
    pixmaps.append(pixmap);
  }
  pic1->setPixmap(pixmaps[0]);
  pic1->setPixmap(pixmaps[1]);
  pic1->setPixmap(pixmaps[2]);
  pic1->setPixmap(pixmaps[3]);
  pic1->setPixmap(pixmaps[4]);
  pic1->setPixmap(pixmaps[5]);
}

void DiceGUI::setupGUI() {

  auto leftLayout = new QVBoxLayout;
  leftLayout->addWidget(listView);

  auto leftBox = new QGroupBox(tr("Roll history"));
  leftBox->setLayout(leftLayout);

  auto rightLayout = new QGridLayout;
  rightLayout->addWidget(pic1, 0, 0);
  rightLayout->addWidget(pic2, 0, 1);
  rightLayout->addWidget(pic3, 1, 0);
  rightLayout->addWidget(pic4, 1, 1);
  rightLayout->addWidget(pic5, 2, 0);
  rightLayout->addWidget(pic6, 2, 1);

  auto rightBox = new QGroupBox(tr("Dice"));
  rightBox->setLayout(rightLayout);

  auto mainLayout = new QGridLayout;
  mainLayout->setColumnMinimumWidth(0, 190);
  mainLayout->setColumnMinimumWidth(1, 190);
  mainLayout->addWidget(buttonRoll, 0, 0, 1, 2);
  mainLayout->addWidget(leftBox, 1, 0);
  mainLayout->addWidget(rightBox, 1, 1);
  setLayout(mainLayout);

  setWindowTitle(tr("Dice"));
  setWindowFlag(Qt::MSWindowsFixedSizeDialogHint);
  adjustSize();
}
