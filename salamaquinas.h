#ifndef SALAMAQUINAS_H
#define SALAMAQUINAS_H

#include "libraries.h"
#include "sala.h"

class SalaMaquinas : public Sala {

public:
	SalaMaquinas();
	virtual string getAsString() const;
	void FimTurno(vector <Sala *> salas);
	int setDiminuiEscudo(int dano) { return 0; };
	virtual int getEscudo()const { return 0; };
};

#endif