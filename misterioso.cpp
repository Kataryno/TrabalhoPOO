#include "misterioso.h"
#include "sala.h"

void Misterioso::InicioTurno(Unidade * unidade, Sala * sala)
{
	// Como � fun��o virtual na classe base, tem de constar na classe derivada mesmo que nada fa�a
}

void Misterioso::FimTurno(Unidade * unidade, Sala * sala)
{
	//Falta desenvolver ataque contra hipnotizador ou inimigo
}
 
Misterioso::Misterioso() : Caracteristica("Misterioso")
//Misterioso::Misterioso(int p) : Caracteristica("Misterioso")
{
	//pontos = p;
}

string Misterioso::getAsString() const
{
	ostringstream oss;
	oss << "\n  N�o tem Pontos " << endl;
	//oss << "\n   Pontos " << pontos << endl;
	return oss.str();
}
