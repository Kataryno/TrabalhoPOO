
#include "unidade.h"
#include "inimigos.h"
#include "libraries.h"


Inimigos::Inimigos(char identificacao)
{
	setId(identificacao);
}

//void Inimigos::setId(char & identificacao)
//{
//	id = identificacao;
//}

//void Inimigos::setNome(string n)
//{
//	nome = n;
//}

//void Inimigos::setSala(int idSala)
//{
//	sala = idSala;
//}

//char Inimigos::getId() const
//{
//	return id;
//}

//int Inimigos::getSalaId() const
//{
//	return sala->
//}

string Inimigos::getAsString() const
{
	ostringstream oss;
	oss << getId() << "-" << getNome() << "-" << getSala();
	return oss.str();
}
