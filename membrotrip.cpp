#include "unidade.h"
#include "tripulacao.h"
#include "membrotrip.h"
#include "combatente.h"
#include "respira.h"
#include "reparador.h"
#include "caractoperador.h"
#include "caracteristica.h"
#include "Caracttripulacao.h"

MembroTrip::MembroTrip(char identificacao, Nave * n) : Tripulacao(identificacao)
{
	setNave(n);
	setNome("Membro Tripulacao");
	hp = 5;
	setMaxHP(hp);
	caracteristicas.push_back(new Respira());
	//caracteristicas.push_back(new Respira(1));
	caracteristicas.push_back(new Reparador(1));
	caracteristicas.push_back(new Combatente(1));
	caracteristicas.push_back(new Operador());
	caracteristicas.push_back(new Caracttripulacao());
}


string MembroTrip::getAsString() const
{
	ostringstream oss;
	for (unsigned int i = 0; i < caracteristicas.size(); i++)
	{
		oss << "   Nome " << caracteristicas[i]->getAsString() << endl;
	}
	return oss.str();
}