#include "combatente.h"
#include "sala.h"

void Combatente::InicioTurno(Unidade * unidade, Sala * sala)
{
	// Como � fun��o virtual na classe base, tem de constar na classe derivada mesmo que nada fa�a
}

void Combatente::FimTurno(Unidade * unidade, Sala * sala)
{
	//Falta desenvolver ataque contra xenomorfo ou inimigo
}

 Combatente::Combatente(int p) : Caracteristica("Combatente")
{
	pontos = p;
}

string Combatente::getAsString() const
{
	ostringstream oss;
	oss << "\n   Pontos " << pontos << endl;
	return oss.str();
}
