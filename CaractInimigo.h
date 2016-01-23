#ifndef CARACTINIMIGO_H
#define CARACTINIMIGO_H

#include "libraries.h"
#include "caracteristica.h"

class Unidade;

class Caractinimigo : public Caracteristica {
	int x,y;

public:
	Caractinimigo(int a, int b);
	virtual string getAsString() const;
	void InicioTurno(Unidade * unidade, Sala * sala);
	void FimTurno(Unidade * unidade, Sala * sala);
};
#endif