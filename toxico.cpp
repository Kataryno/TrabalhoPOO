#include "toxico.h"
#include "sala.h"

void Toxico::InicioTurno(Unidade * unidade, Sala * sala)
{
	sala->gasesToxicos(pontos); //Chama a função da sala que vai verificar quem vai ser afectado pelos gases tóxicos. Passa-lhe o valor a descontar na vida das unidades.
}

void Toxico::FimTurno(Unidade * unidade, Sala * sala)
{
	// Como é função virtual na classe base, tem de constar na classe derivada mesmo que nada faça
}


Toxico::Toxico(int p) : Caracteristica("Toxico")
{
	pontos = p;
}

string Toxico::getAsString() const
{
	ostringstream oss;
	oss << "\n   Pontos " << pontos << endl;
	return oss.str();
}
