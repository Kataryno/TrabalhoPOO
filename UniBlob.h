#ifndef UNIBLOB_H
#define UNIBLOB_H

#include "libraries.h"
#include "unidade.h"
#include "UniXenomorfo.h"

class UniBlob : public UniXenomorfo {

public:
	UniBlob(char identificacao, Sala * sala);

	string getAsString() const;

};

#endif