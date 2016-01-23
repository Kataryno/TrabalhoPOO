#include "unidade.h"
#include "caracteristica.h"
#include "UniXenomorfo.h"
#include "UniCasulo.h"
#include "CaractXenomorfo.h"
#include "exoesqueleto.h"


UniCasulo::UniCasulo(char identificacao, Sala * sala) : UniXenomorfo(identificacao)
{
	setNome("Casulo");
	hp = 6;
	caracteristicas.push_back(new CaractXenomorfo(0));
	caracteristicas.push_back(new Exoesqueleto(2));
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