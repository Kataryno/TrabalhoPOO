#include "unidade.h"
#include "caracteristica.h"
#include "nave.h"

Unidade::Unidade()
{
	sala = nullptr;
	nave = nullptr;
}

Unidade::~Unidade()
{
	sala = nullptr;
}

void Unidade::setMaxHP(int p)
{
	maxHP = p;
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
	if (hp == 0)
		eliminaUnidade();
}

void Unidade::eliminaUnidade()
{
}
//void Unidade::eliminaUnidade()
//{
//	sala->apagaOcupanteTripulacao(this);
//	sala = nullptr;
//	nave->eliminaTripulante(this);
//}

void Unidade::eliminaTripulante()
{
	sala->apagaOcupanteTripulacao(this);
	sala = nullptr;
	nave->eliminaTripulante(this);
}

void Unidade::eliminaInimigo()
{
	sala->apagaOcupanteInimigo(this);
	sala = nullptr;
	nave->eliminaInimigo(this);
}

void Unidade::eliminaXenomorfo()
{
	sala->apagaOcupanteXenomorfo(this);
	sala = nullptr;
	nave->eliminaXenomorfo(this);
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

int Unidade::getMaxHP() const
{
	return maxHP;
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

//Percorre o vector das características para verificar se tem a característica Operador. Se encontrou essa característica retorna true, senão false.
bool Unidade::getOperador()
{
	for (int i = 0; i < caracteristicas.size(); i++)
		if (caracteristicas[i]->getNome() == "Operador")
			return true;
	return false;
}

//Percorre o vector das características para verificar se tem a característica Tóxico. Se encontrou essa característica retorna true, senão false.
bool Unidade::getToxico()
{
	for (int i = 0; i < caracteristicas.size(); i++)
		if (caracteristicas[i]->getNome() == "Toxico")
			return true;
	return false;
}

void Unidade::setNave(Nave * n)
{
	nave = n;
}
