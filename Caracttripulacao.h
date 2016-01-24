#ifndef CARACTTRIPULACAO_H
#define CARACTTRIPULACAO_H

#include "libraries.h"
#include "caracteristica.h"

class Unidade;

class Caracttripulacao : public Caracteristica {

public:
	Caracttripulacao();
	virtual string getAsString() const;
	void InicioTurno(Unidade * unidade, Sala * sala);
	void FimTurno(Unidade * unidade, Sala * sala);
};
#endif