#include "indeciso.h"
#include "sala.h"

void Indeciso::InicioTurno(Unidade * unidade, Sala * sala)
{
	// Como é função virtual na classe base, tem de constar na classe derivada mesmo que nada faça
}

void Indeciso::FimTurno(Unidade * unidade, Sala * sala)
{
	//Falta desenvolver ataque contra hipnotizador ou inimigo
}

Indeciso::Indeciso() : Caracteristica("Indeciso")
//Indeciso::Indeciso(int p) : Caracteristica("Indeciso")
{
	//pontos = p;
}

string Indeciso::getAsString() const
{
	ostringstream oss;
	oss << "\n   Não tem Pontos " << endl;
	//oss << "\n   Pontos " << pontos << endl;
	return oss.str();
}
