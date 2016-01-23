#ifndef SALACAPITAO_H
#define SALACAPITAO_H

#include "libraries.h"
#include "sala.h"

class SalaCapitao : public Sala {

public:
	SalaCapitao();
	virtual string getAsString() const;
	void FimTurno(vector <Sala *> salas);
	int setDiminuiEscudo(int dano) { return 0; };
	virtual int getEscudo()const { return 0; };

};

#endif