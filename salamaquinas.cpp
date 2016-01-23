#include "sala.h"
#include "salamaquinas.h"

SalaMaquinas::SalaMaquinas()
{
	setNome("Maquinas");
}

string SalaMaquinas::getAsString() const
{
	ostringstream oss;
	oss << "Sala Maquinas: \n" << Sala::getAsString() << endl;
	return oss.str();
}

void SalaMaquinas::FimTurno(vector<Sala*> salas)
{
}
