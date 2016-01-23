#ifndef SALAREPARADORA_H
#define SALAREPARADORA_H

#include "libraries.h"
#include "sala.h"

class SalaReparadora : public Sala {
	

public:
	SalaReparadora();
	
	virtual string getAsString()const;
	void FimTurno(vector <Sala *> salas);
	int setDiminuiEscudo(int dano) { return 0; };
	virtual int getEscudo()const { return 0; };
	
};

#endif