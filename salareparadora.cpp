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
}
