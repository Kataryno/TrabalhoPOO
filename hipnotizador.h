#ifndef HIPNOTIZADOR_H
#define HIPNOTIZADOR_H

#include "libraries.h"
#include "caracteristica.h"

class Unidade;

class Hipnotizador : public Caracteristica {
	int pontos;

public:
	Hipnotizador(int p);
	virtual string getAsString() const;
	void InicioTurno(Unidade * unidade, Sala * sala);
	void FimTurno(Unidade * unidade, Sala * sala);
};
#endif