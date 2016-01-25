#include "combatente.h"
#include "unidade.h"
#include "caracteristica.h"
#include "sala.h"
#include <time.h>

void Combatente::InicioTurno(Unidade * unidade, Sala * sala)
{
	// Como é função virtual na classe base, tem de constar na classe derivada mesmo que nada faça
}

void Combatente::FimTurno(Unidade * unidade, Sala * sala)
{
	srand((unsigned)time(NULL));
	int extraDano = 0;
	vector<Unidade *> ocupantesXenomorfos = sala->getXenomorfos();
	vector<Unidade *> ocupantesInimigos = sala->getInimigos();
	if (sala->getCombate())
	{
		int op = rand() % 2;
		if (op && ocupantesXenomorfos.size()!=0)
		{
			
			int i = rand() % (ocupantesXenomorfos.size());
			vector<Caracteristica *> caracteristicas = unidade->getCaracteristicas();
			for (unsigned int j=0; j < caracteristicas.size(); j++)
			{
				if (caracteristicas[j]->getNome() == "Armado")
				{
					extraDano = 1;
				}
			}
			ocupantesXenomorfos[i]->levaDano(pontos+extraDano);
		}
		else if (ocupantesInimigos.size() != 0)
		{
			int i = rand() % (ocupantesInimigos.size());
			vector<Caracteristica *> caracteristicas = unidade->getCaracteristicas();
			for (unsigned int j=0; j < caracteristicas.size(); j++)
			{
				if (caracteristicas[j]->getNome() == "Armado")
				{
					extraDano = 1;
				}
			}
			ocupantesInimigos[i]->levaDano(pontos + extraDano);
		}
	}
}

 Combatente::Combatente(int p) : Caracteristica("Combatente")
{
	pontos = p;
}

string Combatente::getAsString() const
{
	ostringstream oss;
	oss << "\n   Pontos " << pontos << endl;
	return oss.str();
}
