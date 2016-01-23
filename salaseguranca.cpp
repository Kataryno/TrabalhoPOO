#include "sala.h"
#include "salaseguranca.h"

SalaSeguranca::SalaSeguranca()
{
	setNome("Seguranca Interna");
}

string SalaSeguranca::getAsString() const
{
	ostringstream oss;
	oss << "Sala Seguranca Interna: \n" << Sala::getAsString()
	<< "   Forca: " << endl;
	return oss.str();
}

void SalaSeguranca::FimTurno(vector<Sala*> salas)
{
}
