#ifndef ARMADO_H
#define ARMADO_H

#include "libraries.h"
#include "caracteristica.h"

class Unidade;

class Armado : public Caracteristica {
	int pontos;

public:
	Armado(int p);
	virtual string getAsString() const;
	void InicioTurno(Unidade * unidade, Sala * sala);
	void FimTurno(Unidade * unidade, Sala * sala);
};
#endif