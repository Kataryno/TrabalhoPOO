#ifndef TOXICO_H
#define TOXICO_H

#include "libraries.h"
#include "caracteristica.h"

class Unidade;

class Toxico : public Caracteristica {
	int pontos;

public:
	Toxico(int p);
	virtual string getAsString() const;
	void InicioTurno(Unidade * unidade, Sala * sala);
	void FimTurno(Unidade * unidade, Sala * sala);
};
#endif