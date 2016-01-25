#include "mover.h"
#include "unidade.h"
#include "sala.h"

void Mover::InicioTurno(Unidade * unidade, Sala * sala)
{
	vector<Sala * > s; //Cria um vector auxiliar para colocar as salas adjacentes

	int probEvento = rand() % 100 + 1;			//Gera um n� de 1 a 100
	if (probEvento <= pontos)					//Compara o n� gerado com a percentagem definida para a unidade
	{
		s = sala->getSalaAdjacentes();			//preenche o vector auxiliar
		int idSala = rand() % s.size();			//gera um n� de 0 at� ao tamanho de elementos do vector, para depois poder escolher uma das salas adjacentes
		unidade->setSalaUnidade(s[idSala]);		//faz a altera��o da sala
	}
}

void Mover::FimTurno(Unidade * unidade, Sala * sala)
{
	// Como � fun��o virtual na classe base, tem de constar na classe derivada mesmo que nada fa�a
}

 Mover::Mover(int p) : Caracteristica("Mover")
{
	pontos = p;
}

string Mover::getAsString() const
{
	ostringstream oss;
	oss << "\n   Pontos " << pontos << endl;
	return oss.str();
}
