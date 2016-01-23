#include "sala.h"
#include "salaponte.h"


SalaPonte::SalaPonte()
{
	setNome("Ponte");
}

string SalaPonte::getAsString() const
{
	ostringstream oss;
	oss << "Sala Ponte: \n" << Sala::getAsString() << endl;
	return oss.str();
}

void SalaPonte::FimTurno(vector<Sala*> salas)
{
}
