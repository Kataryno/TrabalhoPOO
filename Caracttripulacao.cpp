#include "caracttripulacao.h"
#include "sala.h"

void Caracttripulacao::InicioTurno(Unidade * unidade, Sala * sala)
{
	// Como � fun��o virtual na classe base, tem de constar na classe derivada mesmo que nada fa�a
}

void Caracttripulacao::FimTurno(Unidade * unidade, Sala * sala)
{
	// Como � fun��o virtual na classe base, tem de constar na classe derivada mesmo que nada fa�a
}
 
Caracttripulacao::Caracttripulacao() : Caracteristica("Tripulacao")
{
}

string Caracttripulacao::getAsString() const
{
	ostringstream oss;
	oss << "\n  N�o tem Pontos " << endl;
	return oss.str();
}
