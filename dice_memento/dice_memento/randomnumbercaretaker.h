#ifndef RANDOMNUMBERCARETAKER_H
#define RANDOMNUMBERCARETAKER_H

#include "randomnumbergeneratormemento.h"

class RandomNumberCaretaker {
public:
  RandomNumberCaretaker();
  ~RandomNumberCaretaker();
  void addAMemento(RandomNumberGeneratorMemento *m);
  RandomNumberGeneratorMemento *getAMemento(int n) const;

private:
  QList<RandomNumberGeneratorMemento *> mementos;
};

#endif // RANDOMNUMBERCARETAKER_H
