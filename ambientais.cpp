#include "sala.h"
#include "unidade.h"
#include "tripulacao.h"
#include "inimigos.h"
#include "UniXenomorfo.h"
#include "ambientais.h"
#include <time.h>


//EfeitosAmbientais::EfeitosAmbientais()
//{
//}
//
//EfeitosAmbientais::~EfeitosAmbientais()
//{
//}
//
//void EfeitosAmbientais::FimTurno()
//{
//	
//}
//
//void EfeitosAmbientais::InicioTurno()
//{
//	
//}

void AmbientaisInicioTurno(vector<Sala*> salas)
{
	vector<Unidade *> ocupantesTripulacao;
	vector<Unidade *> ocupantesXenomorfos;
	vector<Unidade *> ocupantesInimigos;

	for (unsigned int i = 0; i < salas.size(); i++)
	{
		if (salas[i]->getFogo())
		{
			ocupantesTripulacao = salas[i]->getTripulacao();
			for (unsigned int j = 0; j < ocupantesTripulacao.size(); j++)
			{
				ocupantesTripulacao[j]->levaDano(2);
			}
			ocupantesInimigos = salas[i]->getInimigos();
			for (unsigned int j = 0; j < ocupantesInimigos.size(); j++)
			{
				ocupantesInimigos[j]->levaDano(2);
			}
			ocupantesXenomorfos = salas[i]->getXenomorfos();
			for (unsigned int j = 0; j < ocupantesXenomorfos.size(); j++)
			{
				ocupantesXenomorfos[j]->levaDano(2);
			}
		}
	}

}

void AmbientaisFimTurno(vector<Sala*> salas)
{
	srand((unsigned)time(NULL));
	vector<Unidade *> ocupantesTripulacao;
	vector<Unidade *> ocupantesXenomorfos;
	vector<Unidade *> ocupantesInimigos;
	int n_ocupantes;
	for (unsigned int i = 0; i < salas.size(); i++)
	{
		if (salas[i]->getCC())
		{
			ocupantesTripulacao = salas[i]->getTripulacao();
			ocupantesXenomorfos = salas[i]->getXenomorfos();
			ocupantesInimigos = salas[i]->getInimigos();
			n_ocupantes = ocupantesTripulacao.size() + ocupantesXenomorfos.size() + ocupantesInimigos.size();
			if (rand() % 101<=25)
			{
				for (unsigned int j = 0; i < ocupantesTripulacao.size(); j++)
				{
					ocupantesTripulacao[j]->levaDano(n_ocupantes);
				}
				for (unsigned int j = 0; i < ocupantesInimigos.size(); j++)
				{
					ocupantesInimigos[j]->levaDano(n_ocupantes);
				}
				for (unsigned int j = 0; i < ocupantesXenomorfos.size(); j++)
				{
					ocupantesXenomorfos[j]->levaDano(n_ocupantes);
				}

			}

		}
	}


}
