#ifndef CARCTXENOMORFO_H
#define CARCTXENOMORFO_H

#include "libraries.h"
#include "caracteristica.h"

class Unidade;

class CaractXenomorfo : public Caracteristica {
	int pontos;

public:
	CaractXenomorfo(int p);
	virtual string getAsString() const;
	void InicioTurno(Unidade * unidade, Sala * sala);
	void FimTurno(Unidade * unidade, Sala * sala);
};
#endif