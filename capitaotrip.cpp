#include "capitaotrip.h"
#include "respira.h"
#include "reparador.h"
#include "exoesqueleto.h"
#include "combatente.h"
#include "caractoperador.h"
#include "Caracttripulacao.h"

CapitaoTrip::CapitaoTrip(char identificacao, Nave * n) : Tripulacao(identificacao)
{
	setNave(n);
	setNome("Capitao");
	hp = 6;
	caracteristicas.push_back(new Respira());
	//caracteristicas.push_back(new Respira(1));
	caracteristicas.push_back(new Exoesqueleto(2));
	caracteristicas.push_back(new Reparador(1));
	caracteristicas.push_back(new Combatente(2));
	caracteristicas.push_back(new Operador());
	caracteristicas.push_back(new Caracttripulacao());
}