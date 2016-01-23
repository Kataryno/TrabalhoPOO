#ifndef UNIXENOMORFO_H
#define UNIXENOMORFO_H

#include "libraries.h"
#include "unidade.h"

class UniXenomorfo : public Unidade {

public:
	UniXenomorfo(char identificacao);

	string getAsString() const;

};

#endif