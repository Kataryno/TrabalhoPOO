#ifndef PIRATA_H
#define PIRATA_H

#include "libraries.h"
#include "inimigos.h"
#include "caracteristica.h"

class Pirata : public Inimigos{

public:
	Pirata::Pirata(char identificacao, Sala * sala);
	virtual string getAsString() const;
	
};
#endif