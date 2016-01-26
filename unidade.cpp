#include "unidade.h"
#include "caracteristica.h"
#include "armado.h"
#include "nave.h"
#include "indeciso.h"
#include <algorithm>

Unidade::Unidade()
{
	sala = nullptr;
	nave = nullptr;
	oculta = false;
}

Unidade::~Unidade()
{
	sala = nullptr;
}

void Unidade::setCaracteriscaArmado()
{
	for (unsigned int i=0; i<caracteristicas.size(); i++)
	{
		 if(caracteristicas.back()->getNome() != "Armado")
			 caracteristicas.push_back(new Armado(1));
	}
	
}

void Unidade::setCaracteristicaIndeciso()
{
	caracteristicas.push_back(new Indeciso());
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

bool Unidade::getOculta() const
{
	return oculta;
}

void Unidade::setOculta(bool o)
{
	oculta = o;
}

void Unidade::levaDano(int d)
{

	if (getExoesqueleto() > 0)
	{
		int resto = d - getExoesqueleto();
		if (resto > 0)
		{
			hp -= resto;
			setExoesqueleto(0);
		}
		else
			setExoesqueleto(abs(resto));
	}
	else
		hp -= d;

	if (hp <= 0)
		eliminaUnidade();
}


void Unidade::eliminaUnidade()
{
}

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

void Unidade::setSalaUnidade(Sala * idsala)
{
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

void Unidade::setHp(int pontos)
{
	hp = pontos;
}

int Unidade::getMaxHP() const
{
	return maxHP;
}


vector<Caracteristica*> Unidade::getCaracteristicas() const
{
	return caracteristicas;
}

void Unidade::FimTurno()
{
	if (sala->getIntegridade() > 0 && sala->getIntegridade() <= 100)
		for (unsigned int i = 0; i < caracteristicas.size(); i++)
			caracteristicas[i]->FimTurno(this, sala);
}

void Unidade::InicioTurno()
{
	for (unsigned int i = 0; i < caracteristicas.size(); i++)
		caracteristicas[i]->InicioTurno(this, sala);
}

//Percorre o vector das características para verificar se tem a característica Operador. Se encontrou essa característica retorna true, senão false.
bool Unidade::getOperador() const
{
	for (int i = 0; i < caracteristicas.size(); i++)
		if (caracteristicas[i]->getNome() == "Operador")
			return true;
	return false;
}

//Percorre o vector das características para verificar se tem a característica Tóxico. Se encontrou essa característica retorna true, senão false.
bool Unidade::getToxico() const
{
	for (int i = 0; i < caracteristicas.size(); i++)
		if (caracteristicas[i]->getNome() == "Toxico")
			return true;
	return false;
}

//Percorre o vector das características para verificar se tem a característica Tóxico. Se encontrou essa característica retorna true, senão false.
int Unidade::getExoesqueleto() const
{
	for (int i = 0; i < caracteristicas.size(); i++)
		if (caracteristicas[i]->getNome() == "Exoesqueleto")
			return caracteristicas[i]->getPontos();
	return 0;
}

void Unidade::setExoesqueleto(int pontos)
{
	for (int i = 0; i < caracteristicas.size(); i++)
		if (caracteristicas[i]->getNome() == "Exoesqueleto")
			caracteristicas[i]->setPontos(pontos);
}

void Unidade::setSala(Sala * s)
{
	sala = s;
}

void Unidade::setNave(Nave * n)
{
	nave = n;
}

Nave * Unidade::getNave() const
{
	return nave;
}

vector<Sala*> Unidade::getSalasNave() const
{
	return nave->getVectorSalas();
}