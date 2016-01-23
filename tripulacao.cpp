#include "libraries.h"
#include "unidade.h"
#include "tripulacao.h"
#include "membrotrip.h"
#include "capitaotrip.h"
#include "robottrip.h"


Tripulacao::Tripulacao(char identificacao)
{
	setId(identificacao);
}

string Tripulacao::getAsString() const
{
	ostringstream oss;
	oss << getId() << "-" << getNome() << "-" << getSala();
	return oss.str();
}
