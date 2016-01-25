#include "sala.h"
#include "unidade.h"
#include "salaseguranca.h"

SalaSeguranca::SalaSeguranca()
{
	setNome("Seguranca Interna");
}

string SalaSeguranca::getAsString() const
{
	ostringstream oss;
	oss << "Sala Seguranca Interna: \n" << Sala::getAsString()
	<< "   Forca: " << endl;
	return oss.str();
}

void SalaSeguranca::FimTurno(vector<Sala*> salas)
{
	vector<Unidade *> ocupantesTripulacao = getTripulacao();
	vector<Unidade *> ocupantesXenomorfos = getXenomorfos();
	vector<Unidade *> ocupantesInimigos = getInimigos();
	vector<Sala*> salasAdjacentes = getSalaAdjacentes();
	if (getIntegridade() == 100)
	{
		if (getCombate())
		{
			if (ocupantesXenomorfos.size() != 0)
				for (unsigned int i = 0; i < ocupantesXenomorfos.size(); i++)
				{
					ocupantesXenomorfos[i]->levaDano(1);
				}

			if (ocupantesInimigos.size() != 0)
				for (unsigned int i = 0; i < ocupantesInimigos.size(); i++)
				{
					ocupantesInimigos[i]->levaDano(1);
				}

		}

		for (unsigned int i = 0; i < salasAdjacentes.size(); i++)
		{
			ocupantesTripulacao = salasAdjacentes[i]->getTripulacao();
			ocupantesXenomorfos = salasAdjacentes[i]->getXenomorfos();
			ocupantesInimigos = salasAdjacentes[i]->getInimigos();
			if (salasAdjacentes[i]->getCombate())
			{
				if (ocupantesXenomorfos.size() != 0)
				{
					for (unsigned int j = 0; j < ocupantesXenomorfos.size(); j++)
					{
						ocupantesXenomorfos[j]->levaDano(1);
					}
				}
				if (ocupantesInimigos.size() != 0)
				{
					for (unsigned int j = 0; j < ocupantesInimigos.size(); j++)
					{
						ocupantesInimigos[j]->levaDano(1);
					}
				}
			}
		}
	}
}
