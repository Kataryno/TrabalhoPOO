#ifndef SALAOFICINA_H
#define SALAOFICINA_H

#include "libraries.h"
#include "sala.h"

class SalaOficina : public Sala {

public:
	SalaOficina();
	virtual string getAsString() const;
	void FimTurno(vector <Sala *> salas);
	int setDiminuiEscudo(int dano) { return 0; };
	virtual int getEscudo()const { return 0; };
};

#endif