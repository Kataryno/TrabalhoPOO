#include "robottrip.h"
#include "exoesqueleto.h"
#include "combatente.h"
#include "Caracttripulacao.h"

RobotTrip::RobotTrip(char identificacao, Nave * n) : Tripulacao(identificacao)
{
	setNave(n);
	setNome("Robot");
	hp = 8;
	caracteristicas.push_back(new Exoesqueleto(2));
	caracteristicas.push_back(new Combatente(3));
	caracteristicas.push_back(new Caracttripulacao());
}
