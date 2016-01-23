#include "unidade.h"
#include "libraries.h"
#include "UniXenomorfo.h"


UniXenomorfo::UniXenomorfo(char identificacao)
{
	setId(identificacao);
}

string UniXenomorfo::getAsString() const
{
	ostringstream oss;
	oss << getId() << "-" << getNome() << "-" << getSala();
	return oss.str();
}
