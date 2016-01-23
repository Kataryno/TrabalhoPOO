#include "CaractXenomorfo.h"
#include "sala.h"

void CaractXenomorfo::InicioTurno(Unidade * unidade, Sala * sala)
{
	// Como � fun��o virtual na classe base, tem de constar na classe derivada mesmo que nada fa�a
}

void CaractXenomorfo::FimTurno(Unidade * unidade, Sala * sala)
{
	//Falta desenvolver ataque contra CaractXenomorfo ou inimigo
}

 CaractXenomorfo::CaractXenomorfo(int p) : Caracteristica("CaractXenomorfo")
{
	pontos = p;
}

string CaractXenomorfo::getAsString() const
{
	ostringstream oss;
	oss << "\n   Pontos " << pontos << endl;
	return oss.str();
}
