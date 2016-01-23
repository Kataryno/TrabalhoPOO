#include "sala.h"
#include "salacapitao.h"

SalaCapitao::SalaCapitao()
{
	setNome("Capitao");
}

string SalaCapitao::getAsString() const
{
	ostringstream oss;
	oss << "Sala Capitao: \n" << Sala::getAsString() << endl;
	return oss.str();
}

void SalaCapitao::FimTurno(vector<Sala*> salas)
{
}
