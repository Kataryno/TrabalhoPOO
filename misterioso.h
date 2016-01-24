#ifndef MISTERIOSO_H
#define MISTERIOSO_H

#include "libraries.h"
#include "caracteristica.h"

class Unidade;

class Misterioso : public Caracteristica {
	//int pontos;

public:
	Misterioso();
	//Misterioso(int p);
	virtual string getAsString() const;
	void InicioTurno(Unidade * unidade, Sala * sala);
	void FimTurno(Unidade * unidade, Sala * sala);
};
#endif