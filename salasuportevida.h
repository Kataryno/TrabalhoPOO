#ifndef SALASUPORTEVIDA_H
#define SALASUPORTEVIDA_H

#include "libraries.h"
#include "sala.h"

class SalaSuporteVida : public Sala {

public:
	SalaSuporteVida();
	virtual string getAsString()const;
	void FimTurno(vector <Sala *> salas);
	int setDiminuiEscudo(int dano) { return 0; };
	virtual int getEscudo()const { return 0; };
};

#endif