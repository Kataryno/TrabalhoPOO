#include "mutatismutantis.h"
#include "sala.h"
#include "unidade.h"
#include "salapropulsor.h"
#include "nave.h"
#include "salabeliche.h"
#include "salaraiolaser.h"
#include "salareparadora.h"
#include "salaseguranca.h"
#include "salaenfermaria.h"
#include "salaarmas.h"
#include "salacapitao.h"
#include "salaoficina.h"

void Mutatismutantis::InicioTurno(Unidade * unidade, Sala * sala)
{
	// Como é função virtual na classe base, tem de constar na classe derivada mesmo que nada faça
}

void Mutatismutantis::FimTurno(Unidade * unidade, Sala * sala)
{
	int probEvento = rand() % 100 + 1;					//Gera um nº de 1 a 100
	if (probEvento <= pontos)
	{
		int idSala = unidade->getSala();
		if ((idSala >= 1 && idSala <= 3) || (idSala >= 9 && idSala <= 11))
		{
			int probSala = rand() % 9;					 //Escolhe aleatóriamente um nº para gerar uma nova sala
			Sala * novaSala = nullptr;
			switch (probSala)
			{
			case 0: novaSala = new SalaPropulsor;
				break;
			case 1:	novaSala = new SalaBeliche;
				break;
			case 2:	novaSala = new SalaRaioLaser;
				break;
			case 3:	novaSala = new SalaReparadora;
				break;
			case 4:	novaSala = new SalaSeguranca;
				break;
			case 5:	novaSala = new SalaEnfermaria;
				break;
			case 6:	novaSala = new SalaArmas;
				break;
			case 7:	novaSala = new SalaCapitao;
				break;
			case 8:	novaSala = new SalaOficina;
				break;
			}

			//Fas uma cópia de cada vector de ocupantes, mas antes altera a sala, de cada um dos ocupantes, para a nova sala

			vector<Unidade *> ocupantesTripulacao = sala->getTripulacao();
			for (int i = 0; i < ocupantesTripulacao.size(); i++)
			{
				ocupantesTripulacao[i]->setSala(novaSala);
				novaSala->adicionaOcupanteTripulacao(ocupantesTripulacao[i]);

			}

			vector<Unidade *> ocupantesInimigos = sala->getInimigos();
			for (int i = 0; i < ocupantesInimigos.size(); i++)
			{
				ocupantesInimigos[i]->setSala(novaSala);
				novaSala->adicionaOcupanteInimigo(ocupantesInimigos[i]);
			}

			vector<Unidade *> ocupantesXenomorfos = sala->getXenomorfos();
			for (int i = 0; i < ocupantesXenomorfos.size(); i++)
			{
				ocupantesXenomorfos[i]->setSala(novaSala);
				novaSala->adicionaOcupanteXenomorfo(ocupantesXenomorfos[i]);
			}


			//Atribui à nave a nova sala e neste processo a antiga é destruída
			Nave * nave = unidade->getNave();
			nave->alteraNave(novaSala, idSala);

			//Regenera o vector de salas adjacentes
			nave->removeSalasAdjacentes();
			nave->preencheSalasAdjacentes();

			//Atribuì à unidade a nova sala
			unidade->setSala(novaSala);
		}
	}
}

 Mutatismutantis::Mutatismutantis(int p) : Caracteristica("Mutatismutantis")
{
	pontos = p;
}

string Mutatismutantis::getAsString() const
{
	ostringstream oss;
	oss << "\n   Pontos " << pontos << endl;
	return oss.str();
}
