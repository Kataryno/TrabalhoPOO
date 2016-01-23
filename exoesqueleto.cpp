#include "exoesqueleto.h"
#include "sala.h"

void Exoesqueleto::FimTurno(Unidade * unidade, Sala * sala)
{
	
}

Exoesqueleto::Exoesqueleto(int p) : Caracteristica("Exoesqueleto")
{
	pontos = p;
}

string Exoesqueleto::getAsString() const
{
	ostringstream oss;
	oss << "\n   Pontos " << pontos << endl;
	return oss.str();
}

void Exoesqueleto::InicioTurno(Unidade * unidade, Sala * sala)
{
	//Como é função virtual na classe base, tem de constar na classe derivada mesmo que nada faça
}
