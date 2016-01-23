#ifndef CARACTERISTICA_H
#define CARACTERISTICA_H

#include "libraries.h"
class Unidade;
class Sala;

class Caracteristica {
	string nome;

public:
	Caracteristica(string n);
	string getAsString() const;
	string getNome() const;
	virtual void InicioTurno(Unidade * unidade, Sala * sala) = 0;
	virtual void FimTurno(Unidade * unidade, Sala * sala) = 0;
	
};

#endif