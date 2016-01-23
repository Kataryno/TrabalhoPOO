#ifndef SALAENFERMARIA_H
#define SALAENFERMARIA_H

#include "libraries.h"
#include "sala.h"

class SalaEnfermaria : public Sala {
	

public:
	SalaEnfermaria();
	
	virtual string getAsString()const;
	void FimTurno(vector <Sala *> salas);
	int setDiminuiEscudo(int dano) { return 0; };
	virtual int getEscudo()const { return 0; };

};

#endif