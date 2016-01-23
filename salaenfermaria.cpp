#include "sala.h"
#include "unidade.h"
#include "tripulacao.h"
#include "capitaotrip.h"
#include "robottrip.h"
#include "salaenfermaria.h"

SalaEnfermaria::SalaEnfermaria()
{
	setNome("Enfermaria");
}

string SalaEnfermaria::getAsString() const
{
	ostringstream oss;
	oss << "Enfermaria: \n" << Sala::getAsString()
	<< "   Forca: " << endl;
	return oss.str();
}

void SalaEnfermaria::FimTurno(vector<Sala *> salas)
{
	vector<Unidade *> ocupantesTripulacao = getTripulacao();
	for (unsigned int i = 0; i < ocupantesTripulacao.size();i++)
	{
		if (ocupantesTripulacao[i]->getHp() <100 && getSaude()==100)
		{ 
			ocupantesTripulacao[i]->recebeVida(1);
		}
	}

}
