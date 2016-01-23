#ifndef CASULO_H
#define CASULO_H

#include "libraries.h"
#include "caracteristica.h"

class Unidade;

class Casulo : public Caracteristica {
	int pontos;

public:
	Casulo(int p);
	virtual string getAsString() const;
	void InicioTurno(Unidade * unidade, Sala * sala);
	void FimTurno(Unidade * unidade, Sala * sala);
};
#endif