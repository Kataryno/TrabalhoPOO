#include "regenerador.h"
#include "unidade.h"
#include "sala.h"

void Regenerador::InicioTurno(Unidade * unidade, Sala * sala)
{
	if (unidade->getHp() == unidade->getMaxHP())
		return;
	else if (unidade->getHp() + pontos > unidade->getMaxHP())
		unidade->setHp(unidade->getMaxHP());
	else
		unidade->setHp(pontos);
}

void Regenerador::FimTurno(Unidade * unidade, Sala * sala)
{
	// Como é função virtual na classe base, tem de constar na classe derivada mesmo que nada faça
}

 Regenerador::Regenerador(int p) : Caracteristica("Regenerador")
{
	pontos = p;
}

string Regenerador::getAsString() const
{
	ostringstream oss;
	oss << "\n   Pontos " << pontos << endl;
	return oss.str();
}
