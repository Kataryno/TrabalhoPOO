#include "armado.h"
#include "unidade.h"
#include "sala.h"

void Armado::InicioTurno(Unidade * unidade, Sala * sala)
{
	// Como é função virtual na classe base, tem de constar na classe derivada mesmo que nada faça
}

void Armado::FimTurno(Unidade * unidade, Sala * sala)
{
	/*if (sala->getCombate)
	{
		vector<Unidade *> ocupantesXenomorfos = sala->getXenomorfos();
		vector<Unidade *> ocupantesInimigos = sala->getInimigos();

		if (ocupantesXenomorfos.size() != 0)
			for (unsigned int i = 0; i < ocupantesXenomorfos.size(); i++)
			{
				ocupantesXenomorfos[i]->levaDano(pontos);
			}

		if (ocupantesInimigos.size() != 0)
			for (unsigned int i = 0; i < ocupantesInimigos.size(); i++)
			{
				ocupantesInimigos[i]->levaDano(pontos);
			}
		
	}*/
}

 Armado::Armado(int p) : Caracteristica("Armado")
{
	pontos = p;
}

string Armado::getAsString() const
{
	ostringstream oss;
	oss << "\n   Pontos " << pontos << endl;
	return oss.str();
}
