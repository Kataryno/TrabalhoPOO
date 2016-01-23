#include "unidade.h"
#include "caracteristica.h"

Unidade::Unidade()
{
	sala = nullptr;
}

Unidade::~Unidade()
{
	sala = nullptr;
}

void Unidade::setId(char & identificacao)
{
	id = identificacao;
}

char Unidade::getId() const
{
	return id;
}

void Unidade::levaDano(int d)
{
	hp -= d;
}

void Unidade::recebeVida(int v)
{
	hp += v;
}

void Unidade::setNome(string n)
{
	nome = n;
}

string Unidade::getNome() const
{
	return nome;
}


void Unidade::setSalaTripulacao(Sala * idsala)
{
	if (sala != nullptr) //Se a sala já está preenchdia, tem de apagar a unidade do vector de ocupantes da sala
		sala->apagaOcupanteTripulacao(this);

	sala = idsala;
	sala->adicionaOcupanteTripulacao(this);
}

void Unidade::setSalaInimigo(Sala * idsala)
{
	if (sala != nullptr) //Se a sala já está preenchdia, tem de apagar a unidade do vector de ocupantes da sala
		sala->apagaOcupanteInimigo(this);

	sala = idsala;
	sala->adicionaOcupanteInimigo(this);
}

void Unidade::setSalaXenomorfo(Sala * idsala)
{
	if (sala != nullptr) //Se a sala já está preenchdia, tem de apagar a unidade do vector de ocupantes da sala
		sala->apagaOcupanteXenomorfo(this);

	sala = idsala;
	sala->adicionaOcupanteXenomorfo(this);
}

int Unidade::getSala() const
{
	if (sala == nullptr)
		return -1;
	return sala->getId();
}

int Unidade::getHp() const
{
	return hp;
}

void Unidade::FimTurno()
{
	if (sala->getIntegridade() > 0 && sala->getIntegridade() < 100)
		for (unsigned int i = 0; i < caracteristicas.size(); i++)
			caracteristicas[i]->FimTurno(this, sala);
}

void Unidade::InicioTurno()
{
	for (unsigned int i = 0; i < caracteristicas.size(); i++)
		caracteristicas[i]->InicioTurno(this, sala);
}

//Percorre o vector das características para verificar se é Operador. Se encontrou essa característica retorna true, senão false.
bool Unidade::getOperador()
{
	for (int i = 0; i < caracteristicas.size(); i++)
		if (caracteristicas[i]->getNome() == "Operador")
			return true;
	return false;
}
