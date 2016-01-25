#include "sala.h"
#include "unidade.h"
#include "tripulacao.h"
#include "salaescudo.h"

Sala::Sala()
{
	integridade = o2 = 100;
	fogo = brecha = curtocircuito = fogoVizinho = false;
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
	oss << "   Nome " << nome  << "\n   Oxigenio "
		<< o2 << "\n   Integridade " << integridade << endl;
	return oss.str();
}


bool Sala::getOperada() const
{
	bool operada = false;

	//Verifica se a integridade está a 100%, se está alguém da tripulação na sala e se não está nenhum inimigo ou xenomorfo na sala.
	//Basta que uma destas condições não se verifique para que a sala não esteja a ser operada.
	
	if (integridade == 100 && ocupantesTripulacao.size() != 0 && (ocupantesXenomorfos.size() == 0 && ocupantesInimigos.size() == 0))
	{	
		//Verifica se há alguém da triplução com a característica de Operador
		for (int i = 0; i < ocupantesTripulacao.size(); i++)
			if (operada = ocupantesTripulacao[i]->getOperador())
				break;

		//Contudo, existe uma excepção que é no caso de a sala estar a 100% e ter um xenomorfo do tipo blob. O blob tem a característica de operador.
		//Não pode existir tripulação nem inimigos na sala, senão estão em combate uns com os outros
	}
	else if (integridade == 100 && ocupantesXenomorfos.size() != 0 && (ocupantesTripulacao.size() == 0 && ocupantesInimigos.size() == 0))
	{
		//Verifica se há algum xenomorfo com a característica de Operador
		for (int i = 0; i < ocupantesXenomorfos.size(); i++)
			if (operada = ocupantesXenomorfos[i]->getOperador())
				break;
	}
	return operada;
}

bool Sala::getCombate() const
{
	if (ocupantesTripulacao.empty() && (ocupantesInimigos.empty() || ocupantesXenomorfos.empty()) || (ocupantesInimigos.empty() && ocupantesXenomorfos.empty()) || (ocupantesTripulacao.empty() && ocupantesXenomorfos.empty()))
		return false;
	else
		return true;
}

int Sala::getIntegridade() const
{
	return integridade;
}

int Sala::getO2() const
{
	return o2;
}

bool Sala::getBrecha() const
{
	return brecha;
}

bool Sala::getFogo() const
{
	return fogo;
}

bool Sala::getFogoVizinho() const
{
	return fogoVizinho;
}

bool Sala::getCC() const
{
	return curtocircuito;
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
	if(integridade<0)
	{ 
		integridade = 0;
	}
}

void Sala::setAumentaIntegridade(int n)
{
	integridade += n;
	if (integridade >= 100)
	{
		integridade = 100;
		brecha = fogo = curtocircuito = false;
	}
}

void Sala::setDiminuiOxigenio(int n)
{
	o2 -= n;
	if (o2 <= 0)
	{
		o2 = 0;
	}
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
	fogo = false;
	o2 = 0;
}

void Sala::setFogo()
{
	if (o2 > 0)
	{
		fogo = true;
	}
}

void Sala::setFogoVizinho(bool f)
{
	fogoVizinho = f;
}

void Sala::setCC()
{
	curtocircuito = true;

}

int Sala::getId() const
{
	return id;
}

vector<Unidade*> Sala::getInimigos() const
{
	return ocupantesInimigos;
}

vector<Unidade*> Sala::getXenomorfos() const
{
	return ocupantesXenomorfos;
}

vector<Sala*> Sala::getSalaAdjacentes() const
{
	return salasAdjacentes;
}

vector<Unidade*> Sala::getTripulacao() const
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
	
	ocupantesTripulacao.push_back(ocupante);
	return true;
}



bool Sala::adicionaOcupanteInimigo(Unidade * ocupante)
{
	if (ocupante == nullptr)
		return false;

	if (pesquisaOcupanteInimigo(ocupante->getId()) != -1)
		return false;

	ocupantesInimigos.push_back(ocupante);
	return true;
}

bool Sala::adicionaOcupanteXenomorfo(Unidade * ocupante)
{
	if (ocupante == nullptr)
		return false;

	if (pesquisaOcupanteXenomorfo(ocupante->getId()) != -1)
		return false;

	ocupantesXenomorfos.push_back(ocupante);
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

void Sala::gasesToxicos(int pontos)
{
	vector<Unidade *> aux;
	
	//Cria-se um vector auxiliar para poder percorrer todo o vector, sem existir a possibilidade de deixar algum elemento por verificar, devido ao vector ter sido mudificado.
	aux = ocupantesTripulacao; 
	
	//Percorre o vector da tripulação
	for (int i = 0; i < aux.size(); i++)
		if (!aux[i]->getToxico())
			aux[i]->levaDano(pontos);

	//Percorre o vector de inimigos
	aux = ocupantesInimigos;
	for (int i = 0; i < aux.size(); i++)
		if (!aux[i]->getToxico())
			aux[i]->levaDano(pontos);

	//Percorre o vector de xenomorfos
	aux = ocupantesXenomorfos;
	for (int i = 0; i < aux.size(); i++)
		if (!aux[i]->getToxico())
			aux[i]->levaDano(pontos);
}

//Para apagar. A função fazia uma cópia do tripulante em vez de ficar a apontar para a lista

//bool Sala::adicionaOcupanteTripulacao(Unidade * ocupante)
//{
//	if (ocupante == nullptr)
//		return false;
//
//	if (pesquisaOcupanteTripulacao(ocupante->getId()) != -1)
//		return false;
//
//	Unidade * p = new Unidade(*ocupante);
//	ocupantesTripulacao.push_back(p);
//	return true;
//}
