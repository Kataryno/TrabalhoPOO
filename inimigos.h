#ifndef INIMIGOS_H
#define INIMIGOS_H

#include "libraries.h"
#include "unidade.h"

class Inimigos : public Unidade {
	//char id;
	//int sala;
	//string nome;

public:
	//Inimigos();
	Inimigos(char identificacao);

	Inimigos(char identificacao, Nave * n);

	//void setId(char & identificacao);
	//void setNome(string n);
	//void setSala(int idSala);
	//char getId() const;
	//int getSalaId() const;
	
	string getAsString() const;

	void eliminaUnidade();

};

#endif