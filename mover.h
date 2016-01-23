#ifndef MOVER_H
#define MOVER_H

#include "libraries.h"
#include "caracteristica.h"

class Unidade;

class Mover : public Caracteristica {
	int pontos;

public:
	Mover(int p);
	virtual string getAsString() const;
	void InicioTurno(Unidade * unidade, Sala * sala);
	void FimTurno(Unidade * unidade, Sala * sala);
};
#endif