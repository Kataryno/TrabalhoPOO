#include "caractrobotico.h"
#include "sala.h"

void Caractrobotico::InicioTurno(Unidade * unidade, Sala * sala)
{
	// Como � fun��o virtual na classe base, tem de constar na classe derivada mesmo que nada fa�a
}

void Caractrobotico::FimTurno(Unidade * unidade, Sala * sala)
{
	// Como � fun��o virtual na classe base, tem de constar na classe derivada mesmo que nada fa�a
}
 
Caractrobotico::Caractrobotico() : Caracteristica("Robotico")
{
}

string Caractrobotico::getAsString() const
{
	ostringstream oss;
	oss << "\n  N�o tem Pontos " << endl;
	return oss.str();
}
