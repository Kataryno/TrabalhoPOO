#ifndef SALAESCUDO_H
#define SALAESCUDO_H

#include "libraries.h"
#include "sala.h"

class SalaEscudo : public Sala {
	int forca;

public:
	SalaEscudo();
	
	virtual string getAsString()const;
	void FimTurno(vector <Sala *> salas);
	int setDiminuiEscudo(int dano);
	int getEscudo()const;
};

#endif