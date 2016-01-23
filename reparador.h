#ifndef REPARADOR_H
#define REPARADOR_H

#include "libraries.h"
#include "caracteristica.h"

class Unidade;

class Reparador : public Caracteristica {
	int pontos;

public:
	Reparador(int p);
	virtual string getAsString() const;
	void InicioTurno(Unidade * unidade, Sala * sala);
	void FimTurno(Unidade * unidade, Sala * sala);

};
#endif