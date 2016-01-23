#include "CaractInimigo.h"
#include "sala.h"

void Caractinimigo::InicioTurno(Unidade * unidade, Sala * sala)
{
	// Como � fun��o virtual na classe base, tem de constar na classe derivada mesmo que nada fa�a
}

void Caractinimigo::FimTurno(Unidade * unidade, Sala * sala)
{
	//Falta desenvolver ataque contra Caractinimigo ou inimigo
}

 Caractinimigo::Caractinimigo(int a, int b) : Caracteristica("Caractinimigo")
{
	x = a;
	y = b;
}

string Caractinimigo::getAsString() const
{
	ostringstream oss;
	oss << "\n   Pontos " << x << endl;
	return oss.str();
}
