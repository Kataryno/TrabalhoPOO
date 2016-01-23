#include "sala.h"
#include "salaoficina.h"

SalaOficina::SalaOficina()
{
	setNome("Oficina");
}

string SalaOficina::getAsString() const
{
	ostringstream oss;
	oss << "Oficina Robotica: \n" << Sala::getAsString() << endl;
	return oss.str();
}

void SalaOficina::FimTurno(vector<Sala*> salas)
{
}
