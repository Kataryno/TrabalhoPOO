#include "caracttripulacao.h"
#include "sala.h"

void Caracttripulacao::InicioTurno(Unidade * unidade, Sala * sala)
{
	// Como é função virtual na classe base, tem de constar na classe derivada mesmo que nada faça
}

void Caracttripulacao::FimTurno(Unidade * unidade, Sala * sala)
{
	// Como é função virtual na classe base, tem de constar na classe derivada mesmo que nada faça
}
 
Caracttripulacao::Caracttripulacao() : Caracteristica("Tripulacao")
{
}

string Caracttripulacao::getAsString() const
{
	ostringstream oss;
	oss << "\n  Não tem Pontos " << endl;
	return oss.str();
}
