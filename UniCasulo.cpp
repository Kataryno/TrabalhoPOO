#include "libraries.h"
#include "unidade.h"
#include "caracteristica.h"
#include "UniXenomorfo.h"
#include "UniCasulo.h"
#include "CaractXenomorfo.h"
#include "exoesqueleto.h"


UniCasulo::UniCasulo(char identificacao, Sala * sala, Nave * n) : UniXenomorfo(identificacao)
{
	setNave(n);
	setNome("Casulo");
	hp = 6;
	setMaxHP(hp);
	caracteristicas.push_back(new CaractXenomorfo(0));
	caracteristicas.push_back(new Exoesqueleto(1));
	setSalaXenomorfo(sala);
}


string UniCasulo::getAsString() const
{
	ostringstream oss;
	for (unsigned int i = 0; i < caracteristicas.size(); i++)
	{
		oss << "   Nome " << caracteristicas[i]->getAsString() << endl;
	}
	return oss.str();
}