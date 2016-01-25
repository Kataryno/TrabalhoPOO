#ifndef MEMBROTRIP_H
#define MEMBROTRIP_H

#include "libraries.h"
#include "tripulacao.h"
#include "caracteristica.h"

class MembroTrip : public Tripulacao{

public:
	MembroTrip(char identificacao, Nave * n);
	virtual string getAsString() const;

	//Unidade * duplica() const { return new MembroTrip(*this); }
	
};
#endif