#ifndef INDECISO_H
#define INDECISO_H

#include "libraries.h"
#include "caracteristica.h"

class Unidade;

class Indeciso : public Caracteristica {
	int pontos;

public:
	Indeciso();
	//Indeciso(int p);
	virtual string getAsString() const;
	void InicioTurno(Unidade * unidade, Sala * sala);
	void FimTurno(Unidade * unidade, Sala * sala);
};
#endif