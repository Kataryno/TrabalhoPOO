#ifndef UNIGEIGERMORFO_H
#define UNIGEIGERMORFO_H

#include "libraries.h"
#include "unidade.h"
#include "UniXenomorfo.h"

class UniGeigermorfo : public UniXenomorfo {

public:
	UniGeigermorfo(char identificacao, Sala * sala, Nave *);

	string getAsString() const;

};

#endif