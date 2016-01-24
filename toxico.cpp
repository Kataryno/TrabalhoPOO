#include "toxico.h"
#include "sala.h"

void Toxico::InicioTurno(Unidade * unidade, Sala * sala)
{
	sala->gasesToxicos(pontos); //Chama a fun��o da sala que vai verificar quem vai ser afectado pelos gases t�xicos. Passa-lhe o valor a descontar na vida das unidades.
}

void Toxico::FimTurno(Unidade * unidade, Sala * sala)
{
	// Como � fun��o virtual na classe base, tem de constar na classe derivada mesmo que nada fa�a
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
