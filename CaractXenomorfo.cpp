#include "CaractXenomorfo.h"
#include "sala.h"
#include "unidade.h"
#include <time.h>

void CaractXenomorfo::InicioTurno(Unidade * unidade, Sala * sala)
{
	// Como é função virtual na classe base, tem de constar na classe derivada mesmo que nada faça
}

void CaractXenomorfo::FimTurno(Unidade * unidade, Sala * sala)
{
	srand((unsigned)time(NULL));
	vector<Unidade *> ocupantesInimigos = sala->getInimigos();
	vector<Unidade *> ocupantesTripulacao = sala->getTripulacao();

	if (!ocupantesTripulacao.empty() && !ocupantesInimigos.empty())
	{
		int op = rand() % 2;
		if (op)
		{
			int idOcupante = rand() % (ocupantesTripulacao.size());
			ocupantesTripulacao[idOcupante]->levaDano(pontos);
		}
		else
		{
			int idOcupante = rand() % (ocupantesInimigos.size());
			ocupantesInimigos[idOcupante]->levaDano(pontos);
		}
	}
	else if (!ocupantesTripulacao.empty())
	{
		int idOcupante = rand() % (ocupantesTripulacao.size());
		ocupantesTripulacao[idOcupante]->levaDano(pontos);
	}
	else if (!ocupantesInimigos.empty())
	{
		int idOcupante = rand() % (ocupantesInimigos.size());
		ocupantesInimigos[idOcupante]->levaDano(pontos);
	}
}

 CaractXenomorfo::CaractXenomorfo(int p) : Caracteristica("CaractXenomorfo")
{
	pontos = p;
}

string CaractXenomorfo::getAsString() const
{
	ostringstream oss;
	oss << "\n   Pontos " << pontos << endl;
	return oss.str();
}
