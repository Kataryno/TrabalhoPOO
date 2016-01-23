#ifndef SALAPONTE_H
#define SALAPONTE_H

#include "libraries.h"
#include "sala.h"

class SalaPonte : public Sala{

public:
	SalaPonte();
	virtual string getAsString()const;
	void FimTurno(vector <Sala *> salas);
	int setDiminuiEscudo(int dano) { return 0; };
	virtual int getEscudo()const { return 0; };
};

#endif