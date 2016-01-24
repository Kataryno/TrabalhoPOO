#ifndef UNIXENOMORFO_H
#define UNIXENOMORFO_H

#include "libraries.h"
#include "unidade.h"

class UniXenomorfo : public Unidade {

public:
	UniXenomorfo(char identificacao);

	UniXenomorfo(char identificacao, Nave * n);

	string getAsString() const;

	void eliminaUnidade();

};

#endif