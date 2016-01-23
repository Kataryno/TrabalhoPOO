#ifndef SALAARMAS_H
#define SALAARMAs_H

#include "libraries.h"
#include "sala.h"

class SalaArmas : public Sala {
	

public:
	SalaArmas();
	
	virtual string getAsString()const;
	void FimTurno(vector <Sala *> salas);
	int setDiminuiEscudo(int dano) { return 0; };
	virtual int getEscudo()const { return 0; };
};

#endif