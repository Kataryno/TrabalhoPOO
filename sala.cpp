#include "sala.h"
#include "unidade.h"
#include "tripulacao.h"
#include "salaescudo.h"

Sala::Sala()
{
	saude = integridade = o2 = 100;
	fogo = brecha = cc = false;
	nome = "Vazia";
	//operada = false;
}

Sala::~Sala()
{
	if (ocupantesTripulacao.size() > 0)
	{
		for (unsigned int i = 0; i < ocupantesTripulacao.size(); i++)
		{
			ocupantesTripulacao.erase(ocupantesTripulacao.begin() + i);
		}
	}
}

string Sala::getAsString() const
{
	ostringstream oss;
	oss << "   Nome " << nome  << "\n   Saude " << saude << "\n   Oxigenio "
		<< o2 << "\n   Integridade " << integridade << endl;
	return oss.str();
}


bool Sala::getOperada() const
{
	bool operada = false;

	//Verifica se a integridade est� a 100%, se est� algu�m da tripula��o na sala e se n�o est� nenhum inimigo ou xenomorfo na sala.
	//Basta que uma destas condi��es n�o se verifique para que a sala n�o esteja a ser operada.
	
	if (integridade == 100 && ocupantesTripulacao.size() != 0 && (ocupantesXenomorfos.size() == 0 || ocupantesInimigos.size() == 0))
		//Verifica se h� algu�m da triplu��o com a caracter�stica de Operador
		for (int i = 0; i < ocupantesTripulacao.size(); i++)
			if (operada = ocupantesTripulacao[i]->getOperador())
				break;

	//Contudo, existe uma excep��o que � no caso de a sala estar a 100% e ter um xenomorfo do tipo blob. O blob tem a caracter�stica de operador.
	//N�o pode existir tripula��o nem inimigos na sala, sen�o est�o em combate uns com os outros

	else if (integridade == 100 && ocupantesXenomorfos.size() != 0 && (ocupantesTripulacao.size() == 0 || ocupantesInimigos.size() == 0))
		//Verifica se h� algum xenomorfo com a caracter�stica de Operador
		for (int i = 0; i < ocupantesXenomorfos.size(); i++)
			if (operada = ocupantesXenomorfos[i]->getOperador())
				break;

	return operada;
}

int Sala::getSaude() const
{
	return saude;
}

int Sala::getIntegridade() const
{
	return integridade;
}

int Sala::getO2() const
{
	return o2;
}

ostream & operator<<(ostream & saida, const Sala & x) {
	saida << x.getAsString();
	return saida;
}

string Sala::getNome() const {
	return nome;
}

void Sala::setId(int idSala)
{
	id = idSala;
}

void Sala::setDiminuiIntegridade(int n)
{
	integridade -= n;
}

void Sala::setAumentaIntegridade(int n)
{
	integridade += n;
}

void Sala::setDiminuiOxigenio(int n)
{
	o2 -= n;
}

void Sala::setAumentaOxigenio(int n)
{
	if (brecha) return;
	o2 += n;
	if (o2 > 100)
	{
		o2 = 100;
	}
}

void Sala::setBrecha()
{
	brecha = true;
	o2 = 0;
}

int Sala::getId() const
{
	return id;
}

vector<Unidade*> Sala::getTripulacao()
{
	return ocupantesTripulacao;
}


bool Sala::apagaOcupanteTripulacao(Unidade * ocupante)
{
	int qual = pesquisaOcupanteTripulacao(ocupante->getId());
	if (qual == -1)
		return false;

	ocupantesTripulacao.erase(ocupantesTripulacao.begin() + qual);
	return true;
}

bool Sala::apagaOcupanteInimigo(Unidade * ocupante)
{
	int qual = pesquisaOcupanteInimigo(ocupante->getId());
	if (qual == -1)
		return false;

	ocupantesInimigos.erase(ocupantesInimigos.begin() + qual);
	return true;
}

bool Sala::apagaOcupanteXenomorfo(Unidade * ocupante)
{
	int qual = pesquisaOcupanteXenomorfo(ocupante->getId());
	if (qual == -1)
		return false;

	ocupantesXenomorfos.erase(ocupantesXenomorfos.begin() + qual);
	return true;
}

int Sala::pesquisaOcupanteTripulacao(char identificacao)
{
	for (unsigned int i = 0; i < ocupantesTripulacao.size(); i++)
	{
		if (ocupantesTripulacao[i]->getId() == identificacao)
		{
			return i; // posicao no vector
		}
	}
	return -1; // posicao impossivel, nao se encontra
}

int Sala::pesquisaOcupanteInimigo(char identificacao)
{
	for (unsigned int i = 0; i < ocupantesInimigos.size(); i++)
	{
		if (ocupantesInimigos[i]->getId() == identificacao)
		{
			return i; // posicao no vector
		}
	}
	return -1; // posicao impossivel, nao se encontra
}

int Sala::pesquisaOcupanteXenomorfo(char identificacao)
{
	for (unsigned int i = 0; i < ocupantesXenomorfos.size(); i++)
	{
		if (ocupantesXenomorfos[i]->getId() == identificacao)
		{
			return i; // posicao no vector
		}
	}
	return -1; // posicao impossivel, nao se encontra
}


bool Sala::adicionaOcupanteTripulacao(Unidade * ocupante)
{
	if (ocupante == nullptr)
		return false;
	
	if (pesquisaOcupanteTripulacao(ocupante->getId()) != -1)
		return false;
	
	Unidade * p = new Unidade(*ocupante);
	ocupantesTripulacao.push_back(p);
	return true;
}

bool Sala::adicionaOcupanteInimigo(Unidade * ocupante)
{
	if (ocupante == nullptr)
		return false;

	if (pesquisaOcupanteInimigo(ocupante->getId()) != -1)
		return false;

	Unidade * p = new Unidade(*ocupante);
	ocupantesInimigos.push_back(p);
	return true;
}

bool Sala::adicionaOcupanteXenomorfo(Unidade * ocupante)
{
	if (ocupante == nullptr)
		return false;

	if (pesquisaOcupanteXenomorfo(ocupante->getId()) != -1)
		return false;

	Unidade * p = new Unidade(*ocupante);
	ocupantesXenomorfos.push_back(p);
	return true;
}

void Sala::adicionaSalaAdjacente(Sala * sala)
{
	salasAdjacentes.push_back(sala);
}

void Sala::eliminaSalaAdjacente()
{
	salasAdjacentes.clear();
}