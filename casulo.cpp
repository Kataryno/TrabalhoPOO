#include "casulo.h"
#include "sala.h"
#include "unidade.h"
#include <time.h>
#include "nave.h"

void Casulo::InicioTurno(Unidade * unidade, Sala * sala)
{
	// Como é função virtual na classe base, tem de constar na classe derivada mesmo que nada faça
}

void Casulo::FimTurno(Unidade * unidade, Sala * sala)
{
	//srand((unsigned)time(NULL));
	//Nave * nave = unidade->getNave();

	//if (!casuloColocado)
	//{
	//	int probEvento = rand() % 100 + 1;					//Gera um nº de 1 a 100
	//	//if (probEvento <= pontos)							//Compara o nº gerado com a percentagem definida para a caracteristica
	//	if (probEvento <= 100)							//Compara o nº gerado com a percentagem definida para a caracteristica
	//	{
	//		//Cria vectores de ocupantes inimigos e tripulação
	//		vector<Unidade *> ocupantesInimigos = sala->getInimigos();
	//		vector<Unidade *> ocupantesTripulacao = sala->getTripulacao();
	//		Unidade * prisioneiro = nullptr;

	//		if (!ocupantesTripulacao.empty() && !ocupantesInimigos.empty())
	//		{
	//			int op = rand() % 2;
	//			if (op)
	//			{
	//				int idOcupante = rand() % (ocupantesTripulacao.size());
	//				prisioneiro = ocupantesTripulacao[idOcupante];
	//				tipoUnidade = 0;
	//			}
	//			else
	//			{
	//				int idOcupante = rand() % (ocupantesInimigos.size());
	//				prisioneiro = ocupantesInimigos[idOcupante];
	//				tipoUnidade = 1;
	//			}
	//		}
	//		else if (!ocupantesTripulacao.empty())
	//		{
	//			int idOcupante = rand() % (ocupantesTripulacao.size());
	//			prisioneiro = ocupantesTripulacao[idOcupante];
	//			tipoUnidade = 0;
	//		}
	//		else if (!ocupantesInimigos.empty())
	//		{
	//			int idOcupante = rand() % (ocupantesInimigos.size());
	//			prisioneiro = ocupantesInimigos[idOcupante];
	//			tipoUnidade = 1;
	//		}
	//		else
	//			return;

	//		//Cria unidade casulo
	//		idCasulo = nave->criaCasulo(prisioneiro->getSala());

	//		//Elimina a unidade aprisionada do respectivo vector
	//		if (tipoUnidade)
	//			nave->eliminaInimigo(prisioneiro);
	//		else
	//			nave->eliminaTripulante(prisioneiro);
	//		
	//		casuloColocado = true;
	//	}
	//}
	//else
	//{
	//	contador++;
	//	if (nave->pesquisaXenomorfo(idCasulo));
	//	if (contador ==3)
	//}
}

 Casulo::Casulo(int p) : Caracteristica("Casulo")
{
	pontos = p;
	//casuloColocado = false;
	//contador = 0;
	//
}

string Casulo::getAsString() const
{
	ostringstream oss;
	oss << "\n   Pontos " << pontos << endl;
	return oss.str();
}
