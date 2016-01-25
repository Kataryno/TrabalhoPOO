#ifndef CAPITAOTRIP_H
#define CAPITAOTRIP_H

#include "libraries.h"
#include "tripulacao.h"

class CapitaoTrip : public Tripulacao{

public:
	CapitaoTrip(char identificacao, Nave * n);

	//Unidade * duplica() const { return new CapitaoTrip(*this); }
};
#endif