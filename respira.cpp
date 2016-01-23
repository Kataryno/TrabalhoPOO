#include "respira.h"
#include "sala.h"
#include "unidade.h"

void Respira::InicioTurno(Unidade * unidade, Sala * sala)
{
	if (sala->getO2() > 0)
		sala->setDiminuiOxigenio(pontos);
	else
		unidade->levaDano(1);
}

void Respira::FimTurno(Unidade * unidade, Sala * sala)
{
	// Como � fun��o virtual na classe base, tem de constar na classe derivada mesmo que nada fa�a
}

 Respira::Respira(int p) : Caracteristica("Respira")
{
	pontos = p;
}

string Respira::getAsString() const
{
	ostringstream oss;
	oss << "\n   Pontos " << pontos << endl;
	return oss.str();
}
