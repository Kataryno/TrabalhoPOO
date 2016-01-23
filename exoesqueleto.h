#ifndef EXOESQUELETO_H
#define EXOESQUELETO_H

#include "libraries.h"
#include "caracteristica.h"

class Unidade;

class Exoesqueleto : public Caracteristica {
	int pontos;

public:
	Exoesqueleto(int p);
	virtual string getAsString() const;
	void InicioTurno(Unidade * unidade, Sala * sala);
	void FimTurno(Unidade * unidade, Sala * sala);

};
#endif