#include "sala.h"
#include "salareparadora.h"

SalaReparadora::SalaReparadora()
{
	setNome("Auto-Reparacao");
}

string SalaReparadora::getAsString() const
{
	ostringstream oss;
	oss << "Sala Auto Reparacao: \n" << Sala::getAsString()
	<< "   Forca: " << endl;
	return oss.str();
}

void SalaReparadora::FimTurno(vector<Sala*> salas)
{
	vector<Sala*> salasAdjacentes = getSalaAdjacentes();
	if (getIntegridade() == 100)
	{
		for (unsigned int j = 0; j < salasAdjacentes.size(); j++)
		{
			salasAdjacentes[j]->setAumentaIntegridade(5);
		}
	}
	
}
