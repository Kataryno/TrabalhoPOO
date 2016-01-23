#include "reparador.h"
#include "sala.h"

void Reparador::FimTurno(Unidade * unidade, Sala * sala)
{
	if (sala->getNome() != "Propulsor")
		sala->setAumentaIntegridade(pontos);
}

Reparador::Reparador(int p) : Caracteristica("Reparador")
{
	pontos = p;
}

string Reparador::getAsString() const
{
	ostringstream oss;
	oss << "\n   Pontos " << pontos << endl;
	return oss.str();
}

void Reparador::InicioTurno(Unidade * unidade, Sala * sala)
{
	//Como é função virtual na classe base, tem de constar na classe derivada mesmo que nada faça
}
