#ifndef ROBOTTRIP_H
#define ROBOTTRIP_H

#include "libraries.h"
#include "tripulacao.h"


class RobotTrip : public Tripulacao {

public:
	RobotTrip(char identificacao, Nave * n);

	//Unidade * duplica() const { return new RobotTrip(*this); }
};
#endif