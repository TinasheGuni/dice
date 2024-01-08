#include "randomnumbercaretaker.h"

RandomNumberCaretaker::RandomNumberCaretaker() {}

RandomNumberCaretaker::~RandomNumberCaretaker() { qDeleteAll(mementos); }

void RandomNumberCaretaker::addAMemento(RandomNumberGeneratorMemento *m) {
  mementos.append(m);
}

RandomNumberGeneratorMemento *RandomNumberCaretaker::getAMemento(int n) const {
  if (n < mementos.size())
    return mementos.at(n);
  else
    return nullptr;
}
