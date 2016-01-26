#ifndef INDECISO_H
#define INDECISO_H

#include "libraries.h"
#include "caracteristica.h"

class Unidade;
class Nave;

class Indeciso : public Caracteristica {
	int salaAnterior;
	int salaActual;

public:
	Indeciso();

	virtual string getAsString() const;
	void InicioTurno(Unidade * unidade, Sala * sala);
	void FimTurno(Unidade * unidade, Sala * sala);
};
#endif