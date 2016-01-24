#ifndef CARACTTRIPULACAO_H
#define CARACTTRIPULACAO_H

#include "libraries.h"
#include "caracteristica.h"

class Unidade;

class Caractrobotico : public Caracteristica {

public:
	Caractrobotico();
	virtual string getAsString() const;
	void InicioTurno(Unidade * unidade, Sala * sala);
	void FimTurno(Unidade * unidade, Sala * sala);
};
#endif