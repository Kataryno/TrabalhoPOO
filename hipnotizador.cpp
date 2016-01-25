#include "hipnotizador.h"
#include "sala.h"
#include "tripulacao.h"

void Hipnotizador::InicioTurno(Unidade * unidade, Sala * sala)
{
	// Como � fun��o virtual na classe base, tem de constar na classe derivada mesmo que nada fa�a
}

void Hipnotizador::FimTurno(Unidade * unidade, Sala * sala)
{
	vector<Unidade * > ocupantesTripulacao; //Cria um vector auxiliar para colocar os tripulantes

	int probEvento = rand() % 100 + 1;					//Gera um n� de 1 a 100
	if (probEvento <= pontos)							//Compara o n� gerado com a percentagem definida para a caracteristica
	{
		ocupantesTripulacao = sala->getTripulacao();						//preenche o vector auxiliar
		if (ocupantesTripulacao.size() > 0)
		{
			int idTripulante = rand() % ocupantesTripulacao.size();			//gera um n� de 0 at� ao tamanho de elementos do vector, para depois poder escolher um dos tripulantes
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
