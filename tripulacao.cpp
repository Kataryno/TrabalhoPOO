
#include "unidade.h"
#include "tripulacao.h"
#include "membrotrip.h"
#include "capitaotrip.h"
#include "robottrip.h"
#include "libraries.h"



//Tripulacao::Tripulacao()
//{
//}

Tripulacao::Tripulacao(char identificacao)
{
	setId(identificacao);
}

//void Tripulacao::setId(char & identificacao)
//{
//	id = identificacao;
//}

//void Tripulacao::setNome(string n)
//{
//	nome = n;
//}

//void Tripulacao::setSala(int idSala)
//{
//	sala = idSala;
//}

//char Tripulacao::getId() const
//{
//	return id;
//}

//int Tripulacao::getSalaId() const
//{
//	return sala->
//}

string Tripulacao::getAsString() const
{
	ostringstream oss;
	oss << getId() << "-" << getNome() << "-" << getSala();
	return oss.str();
}
