#ifndef RESPIRA_H
#define RESPIRA_H

#include "libraries.h"
#include "caracteristica.h"

class Unidade;

class Respira : public Caracteristica {
	int pontos;

public:
	Respira(int p);
	virtual string getAsString() const;
	void InicioTurno(Unidade * unidade, Sala * sala);
	void FimTurno(Unidade * unidade, Sala * sala);
};
#endif