#include "unidade.h"
#include "caracteristica.h"
#include "respira.h"
#include "CaractInimigo.h"
#include "mover.h"
#include "UniXenomorfo.h"
#include "UniBlob.h"
#include "CaractXenomorfo.h"
#include "mover.h"
#include "regenerador.h"
#include "flamejante.h"
#include "toxico.h"
#include "reparador.h"
#include "caractoperador.h"


UniBlob::UniBlob(char identificacao, Sala * sala) : UniXenomorfo(identificacao)
{
	setNome("Blob");
	hp = 8;
	caracteristicas.push_back(new CaractXenomorfo(0));
	caracteristicas.push_back(new Regenerador(2));
	caracteristicas.push_back(new Flamejante(5));
	caracteristicas.push_back(new Toxico(1));
	caracteristicas.push_back(new Reparador(6));
	caracteristicas.push_back(new Operador());
	caracteristicas.push_back(new Mover(15));
	setSalaXenomorfo(sala);
}


string UniBlob::getAsString() const
{
	ostringstream oss;
	for (unsigned int i = 0; i < caracteristicas.size(); i++)
	{
		oss << "   Nome " << caracteristicas[i]->getAsString() << endl;
	}
	return oss.str();
}