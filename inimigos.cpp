
#include "unidade.h"
#include "inimigos.h"
#include "libraries.h"


Inimigos::Inimigos(char identificacao)
{
	setId(identificacao);
}

Inimigos::Inimigos(char identificacao, Nave * n)
{
	setId(identificacao);
	setNave(n);
}

string Inimigos::getAsString() const
{
	ostringstream oss;
	oss << getId() << "-" << getNome() << " - PV: " << getHp();// << "-" << getSala();
	return oss.str();
}

void Inimigos::eliminaUnidade()
{
	eliminaInimigo();
}