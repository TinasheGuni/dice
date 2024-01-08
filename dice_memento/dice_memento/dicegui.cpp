#include "dicegui.h"

DiceGUI::DiceGUI(QWidget *parent)
    : QWidget{parent}, listView(new QListView),
      buttonRoll(new QPushButton(tr("Roll the dice 6 times"))),
      pic1(new QLabel), pic2(new QLabel), pic3(new QLabel), pic4(new QLabel),
      pic5(new QLabel), pic6(new QLabel) {
  setupGUI();

  count = 0;
  generator.setMiniMax(1, 6);
  model.setStringList(rolls);
  listView->setModel(&model);
  listView->setFixedWidth(170);

  connect(buttonRoll, &QPushButton::clicked, this, &DiceGUI::buttonClicked);
  connect(listView, SIGNAL(clicked(QModelIndex)), this,
          SLOT(getMemento(QModelIndex)));
}

void DiceGUI::buttonClicked() {
  count++;
  QList<quint32> nums = generator.getRandomNumber(6);

  rolls.append(stringRollNums(nums));
  model.setStringList(rolls);
  caretaker.addAMemento(generator.createMemento());
  setPics(nums);
}

void DiceGUI::getMemento(QModelIndex index) {
  QString data = (model.data(index, 0)).toString();
  generator.setMemento(caretaker.getAMemento(modelToindex(data) - 1));
  setPics(generator.getRandomNumber(6));
}

void DiceGUI::setPics(QList<quint32> nums) {
  QList<QPixmap> pixmaps;
  foreach (quint32 i, nums) {
    QString fName(":/pics/images/");
    fName.append(QString::number(i, 10));
    fName.append(".png");
    QPixmap pixmap(fName);
    pixmaps.append(pixmap);
  }
  pic1->setPixmap(pixmaps[0]);
  pic2->setPixmap(pixmaps[1]);
  pic3->setPixmap(pixmaps[2]);
  pic4->setPixmap(pixmaps[3]);
  pic5->setPixmap(pixmaps[4]);
  pic6->setPixmap(pixmaps[5]);
}

QString DiceGUI::stringRollNums(QList<quint32> nums) const {
  QStringList numstrings;
  foreach (quint32 n, nums) {
    numstrings.append(QString::number(n, 10));
  }
  return QString("%1 : %2").arg(count).arg(numstrings.join(","));
}

int DiceGUI::modelToindex(QString s) const {
  QStringList tempList = s.split(":");
  QString tempS = tempList[0].trimmed();
  return tempS.toInt();
}

void DiceGUI::setupGUI() {
  setWindowTitle(tr("Dice"));

  auto boxLeft = new QGroupBox(tr("Roll history"));

  auto boxRight = new QGroupBox(tr("Dice"));

  auto layoutRight = new QGridLayout;
  boxRight->setLayout(layoutRight);
  layoutRight->addWidget(pic1, 0, 0);
  layoutRight->addWidget(pic2, 0, 1);
  layoutRight->addWidget(pic3, 1, 0);
  layoutRight->addWidget(pic4, 1, 1);
  layoutRight->addWidget(pic5, 2, 0);
  layoutRight->addWidget(pic6, 2, 1);

  auto layoutLeft = new QVBoxLayout;
  layoutLeft->addWidget(listView);
  boxLeft->setLayout(layoutLeft);

  auto mainLayout = new QGridLayout;
  mainLayout->setColumnMinimumWidth(0, 190);
  mainLayout->setColumnMinimumWidth(1, 190);
  mainLayout->addWidget(buttonRoll, 0, 0, 1, 2);
  mainLayout->addWidget(boxLeft, 1, 0);
  mainLayout->addWidget(boxRight, 1, 1);
  setLayout(mainLayout);

  this->setWindowFlag(Qt::MSWindowsFixedSizeDialogHint);
  this->adjustSize();
}
