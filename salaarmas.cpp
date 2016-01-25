#include "sala.h"
#include "unidade.h"
#include "salaarmas.h"
#include "caracteristica.h"
#include "armado.h"
int flg = 0;

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
	//if (flg == 0)
	//{
	//	setDiminuiIntegridade(10);
	//}
	///*if (flg == 3)
	//{
	//	setBrecha();
	//}*/
	//flg++;
	vector<Unidade *> ocupantesTripulacao = getTripulacao();
	for (unsigned int i = 0; i < ocupantesTripulacao.size(); i++)
	{
		ocupantesTripulacao[i]->setCaracteriscaArmado();
	}

}
