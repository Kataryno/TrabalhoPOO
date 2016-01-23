#ifndef SALASEGURANCA_H
#define SALASEGURANCA_H

#include "libraries.h"
#include "sala.h"

class SalaSeguranca : public Sala {
	

public:
	SalaSeguranca();
	
	virtual string getAsString()const;
	void FimTurno(vector <Sala *> salas);
	int setDiminuiEscudo(int dano) { return 0; };
	virtual int getEscudo()const { return 0; };
};

#endif