#include "libraries.h"
#include "unidade.h"
#include "tripulacao.h"
#include "membrotrip.h"
#include "capitaotrip.h"
#include "robottrip.h"
#include "sala.h"

Tripulacao::Tripulacao(char identificacao)
{
	setId(identificacao);
}

string Tripulacao::getAsString() const
{
	ostringstream oss;
	if (getSala() == -1)
		oss << getId() << " - " << getNome() << " - PV: " << getHp() << " Sala: Sem sala atribuida";
	else
		oss << getId() << " - " << getNome() << " - PV: " << getHp() << " Sala: " << getSala() + 1;
	return oss.str();
}

void Tripulacao::eliminaUnidade()
{
	eliminaTripulante();
}

void Tripulacao::setSalaUnidade(Sala * idsala)
{
	setSalaTripulacao(idsala);
}