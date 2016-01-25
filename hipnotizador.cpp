#include "hipnotizador.h"
#include "sala.h"
#include "tripulacao.h"

void Hipnotizador::InicioTurno(Unidade * unidade, Sala * sala)
{
	// Como é função virtual na classe base, tem de constar na classe derivada mesmo que nada faça
}

void Hipnotizador::FimTurno(Unidade * unidade, Sala * sala)
{
	vector<Unidade * > ocupantesTripulacao; //Cria um vector auxiliar para colocar os tripulantes

	int probEvento = rand() % 100 + 1;					//Gera um nº de 1 a 100
	if (probEvento <= pontos)							//Compara o nº gerado com a percentagem definida para a caracteristica
	{
		ocupantesTripulacao = sala->getTripulacao();						//preenche o vector auxiliar
		if (ocupantesTripulacao.size() > 0)
		{
			int idTripulante = rand() % ocupantesTripulacao.size();			//gera um nº de 0 até ao tamanho de elementos do vector, para depois poder escolher um dos tripulantes
			ocupantesTripulacao[idTripulante]->setCaracteristicaIndeciso();	//acrescenta a caracteristica ao triplante
		}
	}
}

 Hipnotizador::Hipnotizador(int p) : Caracteristica("Hipnotizador")
{
	pontos = p;
}

string Hipnotizador::getAsString() const
{
	ostringstream oss;
	oss << "\n   Pontos " << pontos << endl;
	return oss.str();
}
