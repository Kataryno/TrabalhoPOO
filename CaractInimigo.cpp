#include "CaractInimigo.h"
#include "unidade.h"
#include "sala.h"
#include <time.h>

void Caractinimigo::InicioTurno(Unidade * unidade, Sala * sala)
{
	// Como é função virtual na classe base, tem de constar na classe derivada mesmo que nada faça
}

void Caractinimigo::FimTurno(Unidade * unidade, Sala * sala)
{
	srand((unsigned)time(NULL));
	vector<Unidade *> ocupantesXenomorfos = sala->getXenomorfos();
	vector<Unidade *> ocupantesTripulacao = sala->getTripulacao();

	if (!ocupantesTripulacao.empty() && !ocupantesXenomorfos.empty())
	{
		int op = rand() % 2;
		if (op)
		{
			int idOcupante = rand() % (ocupantesTripulacao.size());
			ocupantesTripulacao[idOcupante]->levaDano(x);
		}
		else
		{
			int idOcupante = rand() % (ocupantesXenomorfos.size());
			ocupantesXenomorfos[idOcupante]->levaDano(x);
		}
	}
	else if (!ocupantesTripulacao.empty())
	{
		int idOcupante = rand() % (ocupantesTripulacao.size());
		ocupantesTripulacao[idOcupante]->levaDano(x);
	}
	else if (!ocupantesXenomorfos.empty())
	{
		int idOcupante = rand() % (ocupantesXenomorfos.size());
		ocupantesXenomorfos[idOcupante]->levaDano(x);
	}
	else
	{
		sala->setDiminuiIntegridade(y);
	}
}

 Caractinimigo::Caractinimigo(int a, int b) : Caracteristica("Caractinimigo")
{
	x = a;
	y = b;
}

string Caractinimigo::getAsString() const
{
	ostringstream oss;
	oss << "\n   Pontos " << x << endl;
	return oss.str();
}
