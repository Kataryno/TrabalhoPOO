#ifndef REGENERADOR_H
#define REGENERADOR_H

#include "libraries.h"
#include "caracteristica.h"

class Unidade;

class Regenerador : public Caracteristica {
	int pontos;

public:
	Regenerador(int p);
	virtual string getAsString() const;
	void InicioTurno(Unidade * unidade, Sala * sala);
	void FimTurno(Unidade * unidade, Sala * sala);
};
#endif