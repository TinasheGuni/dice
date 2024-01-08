#ifndef RANDOMNUMBERGENERATORMEMENTO_H
#define RANDOMNUMBERGENERATORMEMENTO_H

#include "randomnumbergenerator.h"

class RandomNumberGeneratorMemento {
private:
  RandomNumberGeneratorMemento();
  friend class RandomNumberGenerator;
  void setState(quint32 s);
  quint32 getState() const;
  quint32 seed;
};

#endif // RANDOMNUMBERGENERATORMEMENTO_H
