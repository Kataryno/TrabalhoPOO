#include "respira.h"
#include "sala.h"
#include "unidade.h"

void Respira::InicioTurno(Unidade * unidade, Sala * sala)
{
	if (sala->getO2() > 0)
		sala->setDiminuiOxigenio(1); //Respira decrementa 1 ponto de vida
		//sala->setDiminuiOxigenio(pontos);
	else
		unidade->levaDano(1);
}

void Respira::FimTurno(Unidade * unidade, Sala * sala)
{
	// Como é função virtual na classe base, tem de constar na classe derivada mesmo que nada faça
}

Respira::Respira() : Caracteristica("Respira")
{
	//pontos = p;
}

//Respira::Respira(int p) : Caracteristica("Respira")
//{
//	pontos = p;
//}

string Respira::getAsString() const
{
	ostringstream oss;
	oss << "\n   Pontos " << 1 << endl;
	//oss << "\n   Pontos " << pontos << endl;
	return oss.str();
}
