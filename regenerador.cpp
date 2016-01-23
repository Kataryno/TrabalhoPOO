#include "regenerador.h"
#include "sala.h"

void Regenerador::InicioTurno(Unidade * unidade, Sala * sala)
{
	// Como é função virtual na classe base, tem de constar na classe derivada mesmo que nada faça
}

void Regenerador::FimTurno(Unidade * unidade, Sala * sala)
{
	//Falta desenvolver ataque contra xenomorfo ou inimigo
}

 Regenerador::Regenerador(int p) : Caracteristica("Regenerador")
{
	pontos = p;
}

string Regenerador::getAsString() const
{
	ostringstream oss;
	oss << "\n   Pontos " << pontos << endl;
	return oss.str();
}
