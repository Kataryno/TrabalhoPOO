#ifndef SALARAIOLASER_H
#define SALARAIOLASER_H

#include "libraries.h"
#include "sala.h"

class SalaRaioLaser : public Sala {
	

public:
	SalaRaioLaser();
	
	virtual string getAsString()const;
	void FimTurno(vector <Sala *> salas);
	int setDiminuiEscudo(int dano) { return 0; };
	virtual int getEscudo()const { return 0; };
};

#endif