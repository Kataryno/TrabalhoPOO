#include "casulo.h"
#include "sala.h"

void Casulo::InicioTurno(Unidade * unidade, Sala * sala)
{
	// Como � fun��o virtual na classe base, tem de constar na classe derivada mesmo que nada fa�a
}

void Casulo::FimTurno(Unidade * unidade, Sala * sala)
{
	//Falta desenvolver ataque contra hipnotizador ou inimigo
}

 Casulo::Casulo(int p) : Caracteristica("Casulo")
{
	pontos = p;
}

string Casulo::getAsString() const
{
	ostringstream oss;
	oss << "\n   Pontos " << pontos << endl;
	return oss.str();
}
