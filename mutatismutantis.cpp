#include "mutatismutantis.h"
#include "sala.h"

void Mutatismutantis::InicioTurno(Unidade * unidade, Sala * sala)
{
	// Como � fun��o virtual na classe base, tem de constar na classe derivada mesmo que nada fa�a
}

void Mutatismutantis::FimTurno(Unidade * unidade, Sala * sala)
{
	//Falta desenvolver ataque contra hipnotizador ou inimigo
}

 Mutatismutantis::Mutatismutantis(int p) : Caracteristica("Mutatismutantis")
{
	pontos = p;
}

string Mutatismutantis::getAsString() const
{
	ostringstream oss;
	oss << "\n   Pontos " << pontos << endl;
	return oss.str();
}
