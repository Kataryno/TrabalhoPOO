 #ifndef TRIPULACAO_H
#define TRIPULACAO_H

#include "libraries.h"
#include "unidade.h"

class Tripulacao : public Unidade {

public:
	Tripulacao(char identificacao);
		
	string getAsString() const;

	void eliminaUnidade();


};

#endif