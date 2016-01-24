#include "flamejante.h"
#include "sala.h"

void Flamejante::InicioTurno(Unidade * unidade, Sala * sala)
{
	if (sala->getO2() > 0)
		sala->setDiminuiOxigenio(5); //Decrementa 5 ponto de oxigénio à sala
}

void Flamejante::FimTurno(Unidade * unidade, Sala * sala)
{
	//Falta desenvolver ataque contra flamejante ou inimigo
}

 Flamejante::Flamejante() : Caracteristica("Flamejante")
//Flamejante::Flamejante(int p) : Caracteristica("Flamejante")
{
	// pontos = p;
}


string Flamejante::getAsString() const
{
	ostringstream oss;
	oss << "\n   Pontos " << 5 << endl;
	//oss << "\n   Pontos " << pontos << endl;
	return oss.str();
}
