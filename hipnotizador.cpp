#include "hipnotizador.h"
#include "sala.h"

void Hipnotizador::InicioTurno(Unidade * unidade, Sala * sala)
{
	// Como � fun��o virtual na classe base, tem de constar na classe derivada mesmo que nada fa�a
}

void Hipnotizador::FimTurno(Unidade * unidade, Sala * sala)
{
	//Falta desenvolver ataque contra hipnotizador ou inimigo
}

 Hipnotizador::Hipnotizador(int p) : Caracteristica("Hipnotizador")
{
	pontos = p;
}

string Hipnotizador::getAsString() const
{
	ostringstream oss;
	oss << "\n   Pontos " << pontos << endl;
	return oss.str();
}
