#ifndef SALABELICHE_H
#define SALABELICHE_H

#include "libraries.h"
#include "sala.h"

class SalaBeliche : public Sala {
	

public:
	SalaBeliche();
	virtual string getAsString()const;
	void FimTurno(vector <Sala *> salas);
	int setDiminuiEscudo(int dano) { return 0; };
	virtual int getEscudo()const { return 0; };
};

#endif