#ifndef UNICASULO_H
#define UNICASULO_H

#include "libraries.h"
#include "unidade.h"
#include "UniXenomorfo.h"

class UniCasulo : public UniXenomorfo {

public:
	UniCasulo(char identificacao, Sala * sala, Nave * n);

	string getAsString() const;

};

#endif