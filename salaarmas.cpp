#include "sala.h"
#include "salaarmas.h"

SalaArmas::SalaArmas()
{
	setNome("Sala Armas");
}

string SalaArmas::getAsString() const
{
	ostringstream oss;
	oss << "Sala Armas: \n" << Sala::getAsString()
	<< "   Forca: " << endl;
	return oss.str();
}

void SalaArmas::FimTurno(vector<Sala*> salas)
{
}
