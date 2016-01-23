#include "caractoperador.h"
#include "sala.h"


Operador::Operador() : Caracteristica("Operador")
{
}

void Operador::InicioTurno(Unidade * unidade, Sala * sala)
{
	// Como é função virtual na classe base, tem de constar na classe derivada mesmo que nada faça
}

void Operador::FimTurno(Unidade * unidade, Sala * sala)
{
	// Como é função virtual na classe base, tem de constar na classe derivada mesmo que nada faça
}


//string Operador::getAsString() const
//{
//	ostringstream oss;
//	oss << "\n   Pontos " << pontos << endl;
//	return oss.str();
//}
