#include "sala.h"
#include "salasuportevida.h"

SalaSuporteVida::SalaSuporteVida()
{
	setNome("Suporte Vida");
}

string SalaSuporteVida::getAsString() const
{
	ostringstream oss;
	oss << "Sala Suporte Vida: \n" << Sala::getAsString() << endl;
	return oss.str();
}

void SalaSuporteVida::FimTurno(vector <Sala *> salas)
{
	for (unsigned int i = 0; i < salas.size(); i++)
	{
		if (salas[i]->getO2() < 100)
		{
			salas[i]->setAumentaOxigenio(2);
		}
	}
}


