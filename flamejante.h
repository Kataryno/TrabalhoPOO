#ifndef FLAMEJANTE_H
#define FLAMEJANTE_H

#include "libraries.h"
#include "caracteristica.h"

class Unidade;

class Flamejante : public Caracteristica {
	int pontos;

public:
	Flamejante(int p);
	virtual string getAsString() const;
	void InicioTurno(Unidade * unidade, Sala * sala);
	void FimTurno(Unidade * unidade, Sala * sala);
};
#endif