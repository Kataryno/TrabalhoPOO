#include "indeciso.h"
#include "sala.h"

void Indeciso::InicioTurno(Unidade * unidade, Sala * sala)
{
	// Como � fun��o virtual na classe base, tem de constar na classe derivada mesmo que nada fa�a
}

void Indeciso::FimTurno(Unidade * unidade, Sala * sala)
{
	//Falta desenvolver ataque contra hipnotizador ou inimigo
}

 Indeciso::Indeciso(int p) : Caracteristica("Indeciso")
{
	pontos = p;
}

string Indeciso::getAsString() const
{
	ostringstream oss;
	oss << "\n   Pontos " << pontos << endl;
	return oss.str();
}
