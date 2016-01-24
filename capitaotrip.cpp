#include "capitaotrip.h"
#include "respira.h"
#include "reparador.h"
#include "exoesqueleto.h"
#include "combatente.h"
#include "caractoperador.h"

CapitaoTrip::CapitaoTrip(char identificacao):Tripulacao(identificacao)
{
	setNome("Capitao");
	hp = 6;
	caracteristicas.push_back(new Respira());
	//caracteristicas.push_back(new Respira(1));
	caracteristicas.push_back(new Exoesqueleto(2));
	caracteristicas.push_back(new Reparador(1));
	caracteristicas.push_back(new Combatente(2));
	caracteristicas.push_back(new Operador());
}
