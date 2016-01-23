#include "sala.h"
#include "salaraiolaser.h"

SalaRaioLaser::SalaRaioLaser()
{
	setNome("RaioLaser");
}

string SalaRaioLaser::getAsString() const
{
	ostringstream oss;
	oss << "Sala Raio Laser: \n" << Sala::getAsString()
	<< "   Forca: " << endl;
	return oss.str();
}

void SalaRaioLaser::FimTurno(vector<Sala*> salas)
{
}
