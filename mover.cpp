#include "mover.h"
#include "sala.h"

void Mover::InicioTurno(Unidade * unidade, Sala * sala)
{
	// Como é função virtual na classe base, tem de constar na classe derivada mesmo que nada faça
}

void Mover::FimTurno(Unidade * unidade, Sala * sala)
{
	//Falta desenvolver ataque contra xenomorfo ou inimigo
}

 Mover::Mover(int p) : Caracteristica("Mover")
{
	pontos = p;
}

string Mover::getAsString() const
{
	ostringstream oss;
	oss << "\n   Pontos " << pontos << endl;
	return oss.str();
}
