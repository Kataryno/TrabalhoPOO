#ifndef COMBATENTE_H
#define COMBATENTE_H

#include "libraries.h"
#include "caracteristica.h"

class Unidade;

class Combatente : public Caracteristica {
	int pontos;

public:
	Combatente(int p);
	virtual string getAsString() const;
	void InicioTurno(Unidade * unidade, Sala * sala);
	void FimTurno(Unidade * unidade, Sala * sala);
};
#endif