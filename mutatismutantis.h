#ifndef MUTATISMUTANTIS_H
#define MUTATISMUTANTIS_H

#include "libraries.h"
#include "caracteristica.h"
#include "sala.h"

class Unidade;
class Sala;
class nave;

class Mutatismutantis : public Caracteristica {
	int pontos;

public:
	Mutatismutantis(int p);
	virtual string getAsString() const;
	void InicioTurno(Unidade * unidade, Sala * sala);
	void FimTurno(Unidade * unidade, Sala * sala);
};
#endif