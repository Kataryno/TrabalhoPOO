#include "toxico.h"
#include "sala.h"

void Toxico::InicioTurno(Unidade * unidade, Sala * sala)
{
	// Como é função virtual na classe base, tem de constar na classe derivada mesmo que nada faça
}

void Toxico::FimTurno(Unidade * unidade, Sala * sala)
{
	//Falta desenvolver ataque contra toxico ou inimigo
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
