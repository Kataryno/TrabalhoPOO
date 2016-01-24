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
	//teste de dano
	int flg = 0;
	if (flg == 0)
	{
		setDiminuiIntegridade(2);
		flg = 1;
		setBrecha();
	}
}
