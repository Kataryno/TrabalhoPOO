#include "libraries.h"
#include "unidade.h"
#include "caracteristica.h"
#include "respira.h"
#include "CaractInimigo.h"
#include "mover.h"
#include "UniXenomorfo.h"
#include "UniGeigermorfo.h"
#include "CaractXenomorfo.h"
#include "Misterioso.h"
#include "mover.h"


UniGeigermorfo::UniGeigermorfo(char identificacao, Sala * sala, Nave * n) : UniXenomorfo(identificacao)
{
	setNave(n);
	setNome("Geigermorfo");
	hp = 4;
	setMaxHP(hp);
	caracteristicas.push_back(new CaractXenomorfo(3));
	caracteristicas.push_back(new Misterioso());
	caracteristicas.push_back(new Mover(50));
	setSalaXenomorfo(sala);
}


string UniGeigermorfo::getAsString() const
{
	ostringstream oss;
	for (unsigned int i = 0; i < caracteristicas.size(); i++)
	{
		oss << "   Nome " << caracteristicas[i]->getAsString() << endl;
	}
	return oss.str();
}