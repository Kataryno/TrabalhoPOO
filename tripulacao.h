 #ifndef TRIPULACAO_H
#define TRIPULACAO_H

#include "libraries.h"
#include "unidade.h"

class Tripulacao : public Unidade {
	//char id;
	//int sala;
	//string nome;

public:
	//Tripulacao();
	Tripulacao(char identificacao);

	//void setId(char & identificacao);
	//void setNome(string n);
	//void setSala(int idSala);
	//char getId() const;
	//int getSalaId() const;
	
	string getAsString() const;

};

#endif