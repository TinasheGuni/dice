#include "randomnumbergeneratormemento.h"

RandomNumberGeneratorMemento::RandomNumberGeneratorMemento() {}

void RandomNumberGeneratorMemento::setState(quint32 s) { seed = s; }

quint32 RandomNumberGeneratorMemento::getState() const { return seed; }
