#include "unidade.h"
#include "inimigos.h"
#include "pirata.h"
#include "caracteristica.h"
#include "respira.h"
#include "CaractInimigo.h"
#include "mover.h"


Pirata::Pirata(char identificacao, Sala * sala, Nave * n) : Inimigos(identificacao)
{
	setNave(n);
	setNome("Pirata");
	hp = 4;
	setMaxHP(hp);
	caracteristicas.push_back(new Respira());
	caracteristicas.push_back(new Caractinimigo(1, 2));
	caracteristicas.push_back(new Mover(15));
	setSalaInimigo(sala);
}


string Pirata::getAsString() const
{
	ostringstream oss;
	for (unsigned int i = 0; i < caracteristicas.size(); i++)
	{
		oss << "   Nome " << caracteristicas[i]->getAsString() << endl;
	}
	return oss.str();
}