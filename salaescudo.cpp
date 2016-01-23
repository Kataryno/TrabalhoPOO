#include "sala.h"
#include "salaescudo.h"

SalaEscudo::SalaEscudo()
{
	setNome("Escudo");
	forca = 100;
}

string SalaEscudo::getAsString() const
{
	ostringstream oss;
	oss << "Sala Escudo: \n" << Sala::getAsString()
	<< "   Forca: " << forca << endl;
	return oss.str();
}

void SalaEscudo::FimTurno(vector<Sala *> salas)
{
	//para testar
	//forca = 50;
	//

	if (getOperada())
	{
		if (forca < 100)
			forca += 5;
	}
}

int SalaEscudo::setDiminuiEscudo(int dano)
{
	int resto=0;
	forca -= dano;
	if (forca < 0)
	{
		resto = abs(forca);
		forca = 0;
	}
	return resto;
}

int SalaEscudo::getEscudo()const
{
	return forca;
}
