#include "libraries.h"
#include "unidade.h"
#include "caracteristica.h"
#include "UniXenomorfo.h"
#include "UniMxyzypykwi.h"
#include "CaractXenomorfo.h"
#include "hipnotizador.h"
#include "mover.h"
#include "mutatismutantis.h"
#include "respira.h"


UniMxyzypykwi::UniMxyzypykwi(char identificacao, Sala * sala, Nave * n) : UniXenomorfo(identificacao)
{
	setNave(n);
	setNome("Mxyzypykwi");
	hp = 8;
	caracteristicas.push_back(new CaractXenomorfo(0));
	caracteristicas.push_back(new Hipnotizador(15));
	caracteristicas.push_back(new Mover(30));
	caracteristicas.push_back(new Mutatismutantis(10));
	caracteristicas.push_back(new Respira());
	//caracteristicas.push_back(new Respira(1));
	setSalaXenomorfo(sala);
}


string UniMxyzypykwi::getAsString() const
{
	ostringstream oss;
	for (unsigned int i = 0; i < caracteristicas.size(); i++)
	{
		oss << "   Nome " << caracteristicas[i]->getAsString() << endl;
	}
	return oss.str();
}