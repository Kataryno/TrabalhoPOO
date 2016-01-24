#ifndef PIRATA_H
#define PIRATA_H

#include "libraries.h"
#include "inimigos.h"
#include "caracteristica.h"

class Pirata : public Inimigos{

public:
	Pirata(char identificacao, Sala * sala, Nave * n);
	virtual string getAsString() const;
	
};
#endif