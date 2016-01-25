#include "libraries.h"
#include "unidade.h"
#include "UniXenomorfo.h"


UniXenomorfo::UniXenomorfo(char identificacao)
{
	setId(identificacao);
}

UniXenomorfo::UniXenomorfo(char identificacao, Nave * n)
{
	setId(identificacao);
	setNave(n);
}

string UniXenomorfo::getAsString() const
{
	ostringstream oss;
	oss << getId() << "-" << getNome() << "-" << getSala();
	return oss.str();
}

void UniXenomorfo::eliminaUnidade()
{
	eliminaXenomorfo();
}

void UniXenomorfo::setSalaUnidade(Sala * idsala)
{
	setSalaXenomorfo(idsala);
}