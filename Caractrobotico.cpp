#include "caractrobotico.h"
#include "sala.h"

void Caractrobotico::InicioTurno(Unidade * unidade, Sala * sala)
{
	// Como é função virtual na classe base, tem de constar na classe derivada mesmo que nada faça
}

void Caractrobotico::FimTurno(Unidade * unidade, Sala * sala)
{
	// Como é função virtual na classe base, tem de constar na classe derivada mesmo que nada faça
}
 
Caractrobotico::Caractrobotico() : Caracteristica("Robotico")
{
}

string Caractrobotico::getAsString() const
{
	ostringstream oss;
	oss << "\n  Não tem Pontos " << endl;
	return oss.str();
}
