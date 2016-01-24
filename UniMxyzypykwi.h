#ifndef UNIMXYZYPYKWI_H
#define UNIMXYZYPYKWI_H

#include "libraries.h"
#include "unidade.h"
#include "UniXenomorfo.h"

class UniMxyzypykwi : public UniXenomorfo {

public:
	UniMxyzypykwi(char identificacao, Sala * sala, Nave * n);

	string getAsString() const;

};

#endif