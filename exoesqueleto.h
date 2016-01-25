#ifndef EXOESQUELETO_H
#define EXOESQUELETO_H

#include "libraries.h"
#include "caracteristica.h"

class Unidade;

class Exoesqueleto : public Caracteristica {
	int pontos;
	int contador;

public:
	Exoesqueleto(int p);
	virtual string getAsString() const;
	void InicioTurno(Unidade * unidade, Sala * sala);
	int getPontos() const;
	void setPontos(int p);
	void FimTurno(Unidade * unidade, Sala * sala);

};
#endif