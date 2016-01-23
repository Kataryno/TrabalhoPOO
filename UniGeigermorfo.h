#ifndef UNIGEIGERMORFO_H
#define UNIGEIGERMORFO_H

#include "libraries.h"
#include "unidade.h"
#include "UniXenomorfo.h"

class UniGeigermorfo : public UniXenomorfo {

public:
	UniGeigermorfo::UniGeigermorfo(char identificacao, Sala * sala);

	string getAsString() const;

};

#endif