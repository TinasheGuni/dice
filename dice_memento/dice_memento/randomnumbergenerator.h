#ifndef RANDOMNUMBERGENERATOR_H
#define RANDOMNUMBERGENERATOR_H

#include <QList>
#include <QRandomGenerator>

class RandomNumberGeneratorMemento;

class RandomNumberGenerator {
public:
  RandomNumberGenerator();
  void setMiniMax(quint32 min, quint32 max);
  QList<quint32> getRandomNumber(int n);
  RandomNumberGeneratorMemento *createMemento() const;
  void setMemento(RandomNumberGeneratorMemento *m);

private:
  QRandomGenerator randomNumber;
  quint32 seed;
  quint32 minimum;
  quint32 maximum;
  void setSeed();
  bool flag;
  QList<quint32> generateNumbers(int n);
};

#endif // RANDOMNUMBERGENERATOR_H
