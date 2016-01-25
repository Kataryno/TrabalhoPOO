#include "libraries.h"
#include "sala.h"
#include "salapropulsor.h"

SalaPropulsor::SalaPropulsor()
{
	setNome("Propulsor");
	propulsao=100;
}

string SalaPropulsor::getAsString() const
{
	ostringstream oss;
	oss << "Sala Propulsor: \n" << Sala::getAsString()
		<< "   Propulsao " << propulsao << endl;
	return oss.str();
}

void SalaPropulsor::FimTurno(vector<Sala*> salas)
{
	
}