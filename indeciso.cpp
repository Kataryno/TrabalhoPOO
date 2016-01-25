#include "indeciso.h"
#include "sala.h"
#include "unidade.h"
#include "nave.h"

void Indeciso::InicioTurno(Unidade * unidade, Sala * sala)
{
	salaAnterior = sala->getId();
}

void Indeciso::FimTurno(Unidade * unidade, Sala * sala)
{
	if (salaAnterior >= 0)
	{
		salaActual = sala->getId();
		int probEvento = rand() % 100 + 1;					//Gera um nº de 1 a 100
		if (probEvento <= 50)								//Verifica se está dentro da probabilidade
		{
			Nave * nave = unidade->getNave();				//Cria um ponteiro para a nave
			vector<Sala *> salas = nave->getVectorSalas();	//Cria um vector de ponteiros para a salas da nave

			int tripulanteNoVector = nave->pesquisaTripulante(unidade->getId()); //Pesquisa o tripulante para saber a sua posição no vector de tripulantes

			nave->atribuiSalaTripulante(tripulanteNoVector, salaAnterior);	//Atribui a sala anterior ao tripulante
		}
	}
}

Indeciso::Indeciso() : Caracteristica("Indeciso")
{
	salaAnterior = -1;
	salaActual = -1;
}

string Indeciso::getAsString() const
{
	ostringstream oss;
	oss << "\n   Não tem Pontos " << endl;
	//oss << "\n   Pontos " << pontos << endl;
	return oss.str();
}
