#ifndef CARACTOPERADOR_H
#define CARACTOPERADOR_H

#include "libraries.h"
#include "caracteristica.h"

class Unidade;

class Operador : public Caracteristica {

public:
	Operador();
	//virtual string getAsString() const;
	void InicioTurno(Unidade * unidade, Sala * sala);
	void FimTurno(Unidade * unidade, Sala * sala);
};
#endif