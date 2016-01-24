#include "sala.h"
#include "unidade.h"
#include "tripulacao.h"
#include "inimigos.h"
#include "UniXenomorfo.h"
#include "ambientais.h"


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
}
