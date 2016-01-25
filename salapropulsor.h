#ifndef SALAPROPULSOR_H
#define SALAPROPULSOR_H

#include "libraries.h"
#include "sala.h"

class Sala;

class SalaPropulsor : public Sala {
	int propulsao;

public:
	SalaPropulsor();
	virtual string getAsString()const;
	void FimTurno(vector <Sala *> salas);
	int setDiminuiEscudo(int dano) { return 0; };
	virtual int getEscudo()const { return 0; };
};

#endif