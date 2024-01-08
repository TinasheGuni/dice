#include "randomnumbergenerator.h"
#include "randomnumbergeneratormemento.h"
#include <QTime>

RandomNumberGenerator::RandomNumberGenerator()
    : seed(999), minimum(0), maximum(0), flag(false) {}

void RandomNumberGenerator::setMiniMax(quint32 min, quint32 max) {
  minimum = min;
  maximum = max;
}

QList<quint32> RandomNumberGenerator::getRandomNumber(int n) {
  if (flag) {
    flag = false;
  } else
    setSeed();
  return generateNumbers(n);
}

RandomNumberGeneratorMemento *RandomNumberGenerator::createMemento() const {
  RandomNumberGeneratorMemento *m = new RandomNumberGeneratorMemento();
  m->setState(seed);
  return m;
}

void RandomNumberGenerator::setMemento(RandomNumberGeneratorMemento *m) {
  seed = m->getState();
  randomNumber.seed(seed);
  flag = true;
}

void RandomNumberGenerator::setSeed() {
  seed = static_cast<quint32>(QTime::currentTime().msec());
  randomNumber.seed(seed);
}

QList<quint32> RandomNumberGenerator::generateNumbers(int n) {
  QList<quint32> result;
  for (int i = 0; i < n; i++) {
    result.append(randomNumber.generate() % (maximum) + (minimum));
  }
  return result;
}
