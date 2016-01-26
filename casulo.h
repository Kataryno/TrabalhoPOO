#ifndef CASULO_H
#define CASULO_H

#include "libraries.h"
#include "caracteristica.h"

class Unidade;

class Casulo : public Caracteristica {
	int pontos;
	//int tipoUnidade;	//0 para tripulante, 1 para inimigo
	//bool casuloColocado;
	//int contador;
	//char idCasulo;
public:
	Casulo(int p);
	virtual string getAsString() const;
	void InicioTurno(Unidade * unidade, Sala * sala);
	void FimTurno(Unidade * unidade, Sala * sala);
};
#endif