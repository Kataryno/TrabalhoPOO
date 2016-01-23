#include "flamejante.h"
#include "sala.h"

void Flamejante::InicioTurno(Unidade * unidade, Sala * sala)
{
	// Como � fun��o virtual na classe base, tem de constar na classe derivada mesmo que nada fa�a
}

void Flamejante::FimTurno(Unidade * unidade, Sala * sala)
{
	//Falta desenvolver ataque contra flamejante ou inimigo
}

 Flamejante::Flamejante(int p) : Caracteristica("Flamejante")
{
	pontos = p;
}

string Flamejante::getAsString() const
{
	ostringstream oss;
	oss << "\n   Pontos " << pontos << endl;
	return oss.str();
}
