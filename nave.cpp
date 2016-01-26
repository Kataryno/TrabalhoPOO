#include "nave.h"
#include "sala.h"
#include "salapropulsor.h"
#include "salamaquinas.h"
#include "salacapitao.h"
#include "salaoficina.h"
#include "salamaquinas.h"
#include "salasuportevida.h"
#include "salaescudo.h"
#include "salaponte.h"
#include "unidade.h"
#include "membrotrip.h"
#include "capitaotrip.h"
#include "robottrip.h"
#include "tripulacao.h"
#include "consola.h"
#include "pirata.h"
#include "UniXenomorfo.h"
#include "salabeliche.h"
#include "salaenfermaria.h"
#include "salaarmas.h"
#include "salaraiolaser.h"
#include "salareparadora.h"
#include "salaseguranca.h"
#include "UniGeigermorfo.h"
#include "UniCasulo.h"
#include "UniBlob.h"
#include "UniMxyzypykwi.h"
#include "ambientais.h"

int Nave::totalTripulantes = 3;
int Nave::DistanciaPercorrida = 0;

Nave::Nave()
{
	int incremento = 12;
			
			salas.push_back(new SalaPropulsor());
			salas.push_back(nullptr);
			salas.push_back(nullptr);
			salas.push_back(nullptr);
			salas.push_back(new SalaMaquinas());
			salas.push_back(new SalaSuporteVida());
			salas.push_back(new SalaEscudo());
			salas.push_back(new SalaPonte());
			salas.push_back(new SalaPropulsor());
			salas.push_back(nullptr);
			salas.push_back(nullptr);
			salas.push_back(nullptr);

			AposentoCapitao = false;
			OficinaRobot = false;

			for (int i = 0; i < 4; i++) 
			{
				PosTripulacaoSalaX[i] = 2;
					PosTripulacaoSalaY[i] = 5;
			}

			salas[0]->setId(0);
			salas[4]->setId(4);
			salas[5]->setId(5);
			salas[6]->setId(6);
			salas[7]->setId(7);
			salas[8]->setId(8);
}

Nave::~Nave()
{
}

void Nave::criaTripulacao()
{
	//bool AposentoCapitao, OficinaRobot;
	//Percorrer as salas da nave e contar o n�mero de Salas de Beliche
	//Incrementar totalTripulantes se encontrar alguma
	for (unsigned int i = 0; i < salas.size(); i++)
	{
		if (salas[i]->getNome() == "Beliche")
			totalTripulantes++;
	}
	
	//True AposentoCapitao se houver 
	//True OficinaRobot se houver 

	//Ciclo de cria��o do vetor da tripula��o
	for (int i = 0; i < totalTripulantes; i++)
	{
		if (AposentoCapitao)
		{
			tripulantes.push_back(new CapitaoTrip(65 + i, this));
			setAposentoCapitao(false);
		}
		else if (OficinaRobot)
		{
			tripulantes.push_back(new RobotTrip(65 + i, this));
			setOficinaRobot(false);
		}
		else
		{
			tripulantes.push_back(new MembroTrip(65 + i, this));
		}
	}
}

void Nave::criaInimigos()
{
	int idSala;
	//Preenche o vector de inimigos quando o evento Ataque de inimigos coloca piratas na nave
		int nInimigos = rand() % (5 - 3 + 1) + 3; //aleatorio entre 3 e 5

		for (int i = 0; i < nInimigos && inimigos.size() < 26; i++)
		{
			idSala = rand() % 11;
			inimigos.push_back(new Pirata(65 + inimigos.size(), salas[idSala], this));
		}
}

void Nave::criaXenomorfos()
{

	//Preenche o vector de xenomorfos quando o evento Ataque de Xenomorfo coloca um xenomorfo na nave
	int idSala = rand() % 11;
	int tipoXenomorfo = rand() % 2;
	switch (tipoXenomorfo)
	{
	case 0: xenomorfos.push_back(new UniGeigermorfo(65 + xenomorfos.size(), salas[idSala], this));
		break;
	case 1: xenomorfos.push_back(new UniBlob(65 + xenomorfos.size(), salas[idSala], this));
		break;
	case 2: xenomorfos.push_back(new UniMxyzypykwi(65 + xenomorfos.size(), salas[idSala], this));
		break;
	default:
		break;
	}
}

char Nave::criaCasulo(int idSala)
{
	//Preenche o vector de xenomorfos quando a caracter�stica casulo � esecutada

	xenomorfos.push_back(new UniCasulo(65 + xenomorfos.size(), salas[idSala], this));
	return 65 + xenomorfos.size();
}

string Nave::getAsString() const
{
		ostringstream oss;

		for (unsigned int i = 0; i < salas.size(); i++)
		{
			if (salas[i] != nullptr)
				oss << salas[i]->getAsString() << endl;
			else
				oss << "Vazia" << endl;
		}
		return oss.str();
}

ostream & operator<<(ostream & saida, const Nave & nave) {
	saida << nave.getAsString();
	return saida;
}

void Nave::alteraNave(Sala * sala, int pos) {
	if (sala != nullptr)
	{	
		if (salas[pos] != nullptr)
		{
			if (salas[pos]->getNome() == "Capitao")
				AposentoCapitao = false;
			if (salas[pos]->getNome() == "Oficina")
				OficinaRobot = false;
			delete salas[pos];
		}
		salas[pos] = sala;
		salas[pos]->setId(pos);
	}
}

int Nave::pesquisaSala(string & nome) const {
	for (unsigned int i = 0; i < salas.size(); i++)
		if (nome == salas[i]->getNome())
			return i;
	return -1;
}

void Nave::preencheNaveAuto()
{
	//Fun��o para efeitos de teste
	alteraNave(new SalaRaioLaser, 2 - 1);
	alteraNave(new SalaArmas, 3 - 1);
	alteraNave(new SalaReparadora, 4 - 1);
	alteraNave(new SalaCapitao, 10 - 1);
	alteraNave(new SalaSeguranca, 11 - 1);
	alteraNave(new SalaEnfermaria, 12 - 1);
	preencheSalasAdjacentes();
	criaInimigos();
	criaXenomorfos();
}

string Nave::getNomeSala(int pos) const
{
	if (salas[pos] == nullptr)
		return "Vazia";
	return salas[pos]->getNome();
}

bool Nave::naveConfiguradaSalas() const
{
	for (unsigned int i = 0; i < salas.size(); i++)
	{
		if (salas[i] == nullptr)
			return false;
	}
	return true;
}

bool Nave::naveConfiguradaTripulantes() const
{
	if (tripulantes.size() != 0)
		return false;

	for (unsigned int i = 0; i < tripulantes.size(); i++)
	{
		if (tripulantes[i]->getSala() == -1)
			return false;
	}
	return true;
}

bool Nave::naveTripulantesCriados() const
{
	if (tripulantes.size() == 0)
		return false;

	return true;
}

void Nave::setAposentoCapitao(bool inf)
{
	AposentoCapitao = inf;
}

void Nave::setOficinaRobot(bool inf)
{
	OficinaRobot = inf;
}

bool Nave::getAposentoCapitao()
{
	return AposentoCapitao;
}

bool Nave::getOficinaRobot()
{
	return OficinaRobot;
}

void Nave::eliminaSala(int & pos)
{
	if (!(salas[pos] == nullptr))
	{
		delete salas[pos];
		salas[pos] = nullptr;
	}
}

char Nave::getIdTripulante(int & pos) const
{
	if (tripulantes[pos] == nullptr)
		return 30;
	return tripulantes[pos]->getId();
}


string Nave::mostraTripulantes(Consola & consola) const
{
	ostringstream oss;
	
	for (unsigned int i = 0; i < tripulantes.size(); i++)
	{
		if (tripulantes[i] != nullptr)
		{
			consola.gotoxy(2, 38 + i);
			cout << tripulantes[i]->getAsString() << endl;
		}
		else
			oss << "Vazio" << endl;
	}
	return oss.str();
}

void Nave::mostraOcupanteSala(Consola & consola)
{
	ostringstream oss0, oss1, oss2, oss3, oss4 , oss5, oss6, oss7, oss8, oss9, oss10, oss11;

	consola.setTextColor(consola.VERDE_CLARO);

	for (unsigned int j = 0; j < tripulantes.size(); j++)
	{
		if (tripulantes[j] != nullptr && !tripulantes[j]->getOculta())
		{
			switch (tripulantes[j]->getSala())
			{
			case 0: oss0 << tripulantes[j]->getId() << "-";
				break;
			case 1: oss1 << tripulantes[j]->getId() << "-";
				break;
			case 2: oss2 << tripulantes[j]->getId() << "-";
				break;
			case 3: oss3 << tripulantes[j]->getId() << "-";
				break;
			case 4: oss4 << tripulantes[j]->getId() << "-";
				break;
			case 5: oss5 << tripulantes[j]->getId() << "-";
				break;
			case 6: oss6 << tripulantes[j]->getId() << "-";
				break;
			case 7: oss7 << tripulantes[j]->getId() << "-";
				break;
			case 8: oss8 << tripulantes[j]->getId() << "-";
				break;
			case 9: oss9 << tripulantes[j]->getId() << "-";
				break;
			case 10: oss10 << tripulantes[j]->getId() << "-";
				break;
			case 11: oss11 << tripulantes[j]->getId() << "-";
				break;
			}
		}
	}
	consola.gotoxy(6, 3);
	cout << oss0.str();
	consola.gotoxy(18, 3);
	cout << oss1.str();
	consola.gotoxy(30, 3);
	cout << oss2.str();
	consola.gotoxy(42, 3);
	cout << oss3.str();
	consola.gotoxy(18, 15);
	cout << oss4.str();
	consola.gotoxy(30, 15);
	cout << oss5.str();
	consola.gotoxy(42, 15);
	cout << oss6.str();
	consola.gotoxy(54, 15);
	cout << oss7.str();
	consola.gotoxy(6, 27);
	cout << oss8.str();
	consola.gotoxy(18, 27);
	cout << oss9.str();
	consola.gotoxy(30, 27);
	cout << oss10.str();
	consola.gotoxy(42, 27);
	cout << oss11.str();

	consola.setTextColor(consola.BRANCO);
}


void Nave::mostraOcupanteSalaInimigos(Consola & consola)
{
	ostringstream oss0, oss1, oss2, oss3, oss4, oss5, oss6, oss7, oss8, oss9, oss10, oss11;

	consola.setTextColor(consola.VERMELHO);

	for (unsigned int j = 0; j < inimigos.size(); j++)
	{
		if (inimigos[j] != nullptr && !inimigos[j]->getOculta())
		{
			switch (inimigos[j]->getSala())
			{
			case 0: oss0 << inimigos[j]->getId() << "-";
				break;
			case 1: oss1 << inimigos[j]->getId() << "-";
				break;
			case 2: oss2 << inimigos[j]->getId() << "-";
				break;
			case 3: oss3 << inimigos[j]->getId() << "-";
				break;
			case 4: oss4 << inimigos[j]->getId() << "-";
				break;
			case 5: oss5 << inimigos[j]->getId() << "-";
				break;
			case 6: oss6 << inimigos[j]->getId() << "-";
				break;
			case 7: oss7 << inimigos[j]->getId() << "-";
				break;
			case 8: oss8 << inimigos[j]->getId() << "-";
				break;
			case 9: oss9 << inimigos[j]->getId() << "-";
				break;
			case 10: oss10 << inimigos[j]->getId() << "-";
				break;
			case 11: oss11 << inimigos[j]->getId() << "-";
				break;
			}
		}
	}
	consola.gotoxy(6, 4);
	cout << oss0.str();
	consola.gotoxy(18, 4);
	cout << oss1.str(); 
	consola.gotoxy(30, 4);
	cout << oss2.str(); 
	consola.gotoxy(42, 4);
	cout << oss3.str();
	consola.gotoxy(18, 16);
	cout << oss4.str(); 
	consola.gotoxy(30, 16);
	cout << oss5.str(); 
	consola.gotoxy(42, 16);
	cout << oss6.str(); 
	consola.gotoxy(54, 16);
	cout << oss7.str(); 
	consola.gotoxy(6, 28);
	cout << oss8.str(); 
	consola.gotoxy(18, 28);
	cout << oss9.str(); 
	consola.gotoxy(30, 28);
	cout << oss10.str(); 
	consola.gotoxy(42, 28);
	cout << oss11.str();
	
	consola.setTextColor(consola.BRANCO);
}

void Nave::mostraOcupanteSalaXenomorfos(Consola & consola)
{
	ostringstream oss0, oss1, oss2, oss3, oss4, oss5, oss6, oss7, oss8, oss9, oss10, oss11;

	consola.setTextColor(consola.AMARELO);

	for (unsigned int j = 0; j < xenomorfos.size(); j++)
	{
		if (xenomorfos[j] != nullptr && !xenomorfos[j]->getOculta()) ////ATEN��O
		{
			switch (xenomorfos[j]->getSala())
			{
			case 0: oss0 << xenomorfos[j]->getId() << "-";
				break;
			case 1: oss1 << xenomorfos[j]->getId() << "-";
				break;
			case 2: oss2 << xenomorfos[j]->getId() << "-";
				break;
			case 3: oss3 << xenomorfos[j]->getId() << "-";
				break;
			case 4: oss4 << xenomorfos[j]->getId() << "-";
				break;
			case 5: oss5 << xenomorfos[j]->getId() << "-";
				break;
			case 6: oss6 << xenomorfos[j]->getId() << "-";
				break;
			case 7: oss7 << xenomorfos[j]->getId() << "-";
				break;
			case 8: oss8 << xenomorfos[j]->getId() << "-";
				break;
			case 9: oss9 << xenomorfos[j]->getId() << "-";
				break;
			case 10: oss10 << xenomorfos[j]->getId() << "-";
				break;
			case 11: oss11 << xenomorfos[j]->getId() << "-";
				break;
			}
		}
	}
	consola.gotoxy(6, 5);
	cout << oss0.str();
	consola.gotoxy(18, 5);
	cout << oss1.str();
	consola.gotoxy(30, 5);
	cout << oss2.str();
	consola.gotoxy(42, 5);
	cout << oss3.str();
	consola.gotoxy(18, 17);
	cout << oss4.str();
	consola.gotoxy(30, 17);
	cout << oss5.str();
	consola.gotoxy(42, 17);
	cout << oss6.str();
	consola.gotoxy(54, 17);
	cout << oss7.str();
	consola.gotoxy(6, 29);
	cout << oss8.str();
	consola.gotoxy(18, 29);
	cout << oss9.str();
	consola.gotoxy(30, 29);
	cout << oss10.str();
	consola.gotoxy(42, 29);
	cout << oss11.str();

	consola.setTextColor(consola.BRANCO);
}


void Nave::avancaNave()
{
	if (salas[7]->getOperada() && salas[4]->getIntegridade() == 100) //Falta verificar se os tripulantes n�o est�o a combater
	{
		for (unsigned int i = 0; i < salas.size(); i++)
		{
			if (salas[i]->getNome() == "Propulsor")
			{
				DistanciaPercorrida += salas[i]->getIntegridade();
			}
		}
	}
}

void Nave::resetDistanciaPercorrida()
{
	DistanciaPercorrida = 0;
}

bool Nave::statusNave()
{
	for (unsigned int i = 0; i<salas.size(); i++)
	{
		if (salas[i]->getIntegridade() <= 0)
			return true;
	}
	return false;
	
}

void Nave::danificaNave(int sala,int dano)
{
	salas[sala]->setDiminuiIntegridade(dano);
}


void Nave::InicioTurno()
{
	//1� Efeitos Ambientais
	AmbientaisFimTurno(salas);
	
	//3� Ac��es dos xenomorfos
	for (unsigned int i = 0; i < xenomorfos.size(); i++)
		xenomorfos[i]->InicioTurno();
	//4� Ac��es dos inimigos
	for (unsigned int i = 0; i < inimigos.size(); i++)
		inimigos[i]->InicioTurno();
	//5� Ac��es dos tripulantes
	for (unsigned int i = 0; i < tripulantes.size(); i++)
		tripulantes[i]->InicioTurno();
}


void Nave::FimTurno()
{
	//1� Efeitos Ambientais
	AmbientaisInicioTurno(salas);
	
	//2� Salas
	for (unsigned int i = 0; i < salas.size(); i++)
		salas[i]->FimTurno(salas);
	//3� Ac��es dos xenomorfos
	for (unsigned int i = 0; i < xenomorfos.size(); i++)
		xenomorfos[i]->FimTurno();
	//4� Ac��es dos inimigos
	for (unsigned int i = 0; i < inimigos.size(); i++)
		inimigos[i]->FimTurno();
	//5� Ac��es dos tripulantes
	for (unsigned int i = 0; i < tripulantes.size(); i++)
		tripulantes[i]->FimTurno();
}

bool Nave::eliminaTripulante(Unidade * unidade)
{
	int pos = pesquisaTripulante(unidade->getId());
	if (pos == -1)
		return false;

	delete tripulantes[pos];
	tripulantes.erase(tripulantes.begin() + pos);
	return true;
}

bool Nave::eliminaInimigo(Unidade * unidade)
{
	int pos = pesquisaInimigo(unidade->getId());
	if (pos == -1)
		return false;

	delete inimigos[pos];
	inimigos.erase(inimigos.begin() + pos);
	return true;
}

string Nave::mostraInimigos(Consola & consola) const
{
	ostringstream oss;
	consola.setTextColor(consola.VERMELHO);
	for (unsigned int i = 0; i < inimigos.size(); i++)
	{
		if (inimigos[i] != nullptr)
		{
			consola.gotoxy(2, 47 + i);
			cout << inimigos[i]->getAsString() << endl;
		}
		else
			oss << "Vazio" << endl;
	}
	consola.setTextColor(consola.BRANCO);
	return oss.str();
}

string Nave::mostraXenomorfos(Consola & consola) const
{
	ostringstream oss;
	consola.setTextColor(consola.AMARELO);
	for (unsigned int i = 0; i < xenomorfos.size(); i++)
	{
		if (xenomorfos[i] != nullptr)
		{
			consola.gotoxy(28, 47 + i);
			cout << xenomorfos[i]->getAsString() << endl;
		}
		else
			oss << "Vazio" << endl;
	}
	consola.setTextColor(consola.BRANCO);
	return oss.str();
}

bool Nave::eliminaXenomorfo(Unidade * unidade)
{
	int pos = pesquisaXenomorfo(unidade->getId());
	if (pos == -1)
		return false;

	delete xenomorfos[pos];
	xenomorfos.erase(xenomorfos.begin() + pos);
	return true;
}

int Nave::pesquisaTripulante(char identificacao) const
{
	for (unsigned int i = 0; i < tripulantes.size(); i++)
		if (identificacao == tripulantes[i]->getId())
			return i;
	return -1;
}

int Nave::pesquisaInimigo(char identificacao) const
{
	for (unsigned int i = 0; i < inimigos.size(); i++)
		if (identificacao == inimigos[i]->getId())
			return i;
	return -1;
}

int Nave::pesquisaXenomorfo(char identificacao) const
{
	for (unsigned int i = 0; i < xenomorfos.size(); i++)
		if (identificacao == xenomorfos[i]->getId())
			return i;
	return -1;
}

void Nave::atribuiSalaTripulante(int & pos, int idSala)
{
	tripulantes[pos]->setSalaTripulacao(salas[idSala]);
}

void Nave::atribuiSalaInimigo(int & pos, int idSala)
{
	inimigos[pos]->setSalaInimigo(salas[idSala]);
}

void Nave::atribuiSalaXenomorfo(int & pos, int idSala)
{
	xenomorfos[pos]->setSalaXenomorfo(salas[idSala]);
}

int Nave::getDistanciaPercorrida()
{
	return DistanciaPercorrida;
}

int Nave::getIntegridadeSala(int pos) const
{
	if (salas[pos] == nullptr)
		return -1;
	return salas[pos]->getIntegridade();
}

int Nave::getEscudoSalaEscudo(int pos) const
{
	return salas[pos]->getEscudo();
}



void Nave::mostraIntegridadeSalas(Nave & nave, Consola & consola)
{
	consola.setTextColor(consola.CYAN);
	consola.gotoxy(6, 12);
	cout << "Int: " << nave.getIntegridadeSala(0) << "%";
	consola.gotoxy(18, 12);
	cout << "Int: " << nave.getIntegridadeSala(1) << "%";
	consola.gotoxy(30, 12);
	cout << "Int: " << nave.getIntegridadeSala(2) << "%";
	consola.gotoxy(42, 12);
	cout << "Int: " << nave.getIntegridadeSala(3) << "%";
	consola.gotoxy(18, 24);
	cout << "Int: " << nave.getIntegridadeSala(4) << "%";
	consola.gotoxy(30, 24);
	cout << "Int: " << nave.getIntegridadeSala(5) << "%";
	consola.gotoxy(42, 24);
	cout << "Int: " << nave.getIntegridadeSala(6) << "%";
	consola.gotoxy(54, 24);
	cout << "Int: " << nave.getIntegridadeSala(7) << "%";
	consola.gotoxy(6, 36);
	cout << "Int: " << nave.getIntegridadeSala(8) << "%";
	consola.gotoxy(18, 36);
	cout << "Int: " << nave.getIntegridadeSala(9) << "%";
	consola.gotoxy(30, 36);
	cout << "Int: " << nave.getIntegridadeSala(10) << "%";
	consola.gotoxy(42, 36);
	cout << "Int: " << nave.getIntegridadeSala(11) << "%";
	consola.setTextColor(consola.BRANCO);
}

void Nave::mostraEfeitosAmbientaisSalas(Nave & nave, Consola & consola)
{
	consola.setTextColor(consola.ROXO);
	consola.gotoxy(6, 8);
	if (salas[0]->getBrecha()) cout << "B "; if (salas[0]->getFogo()) cout << " F "; if (salas[0]->getCC()) cout << " CC ";
	consola.gotoxy(18, 8);
	if (salas[1]->getBrecha()) cout << "B "; if (salas[1]->getFogo()) cout << " F "; if (salas[1]->getCC()) cout << " CC ";
	consola.gotoxy(30, 8);
	if (salas[2]->getBrecha()) cout << "B "; if (salas[2]->getFogo()) cout << " F "; if (salas[2]->getCC()) cout << " CC ";
	consola.gotoxy(42, 8);
	if (salas[3]->getBrecha()) cout << "B "; if (salas[3]->getFogo()) cout << " F "; if (salas[3]->getCC()) cout << " CC ";
	consola.gotoxy(18, 20);
	if (salas[4]->getBrecha()) cout << "B "; if (salas[4]->getFogo()) cout << " F "; if (salas[4]->getCC()) cout << " CC ";
	consola.gotoxy(30, 20);
	if (salas[5]->getBrecha()) cout << "B "; if (salas[5]->getFogo()) cout << " F "; if (salas[5]->getCC()) cout << " CC ";
	consola.gotoxy(42, 20);
	if (salas[6]->getBrecha()) cout << "B "; if (salas[6]->getFogo()) cout << " F "; if (salas[6]->getCC()) cout << " CC ";
	consola.gotoxy(54, 20);
	if (salas[7]->getBrecha()) cout << "B "; if (salas[7]->getFogo()) cout << " F "; if (salas[7]->getCC()) cout << " CC ";
	consola.gotoxy(6, 32);
	if (salas[8]->getBrecha()) cout << "B "; if (salas[8]->getFogo()) cout << " F "; if (salas[8]->getCC()) cout << " CC ";
	consola.gotoxy(18, 32);
	if (salas[9]->getBrecha()) cout << "B "; if (salas[9]->getFogo()) cout << " F "; if (salas[9]->getCC()) cout << " CC ";
	consola.gotoxy(30, 32);
	if (salas[10]->getBrecha()) cout << "B "; if (salas[10]->getFogo()) cout << " F "; if (salas[10]->getCC()) cout << " CC ";
	consola.gotoxy(42, 32);
	if (salas[11]->getBrecha()) cout << "B "; if (salas[11]->getFogo()) cout << " F "; if (salas[11]->getCC()) cout << " CC ";
	consola.setTextColor(consola.BRANCO);
}

void Nave::mostraOxigenioSalas(Nave & nave, Consola & consola)
{
	consola.setTextColor(consola.CYAN);
	consola.gotoxy(6, 10);
	cout << "Int: " << nave.getO2Sala(0) << "%";
	consola.gotoxy(18, 10);
	cout << "O2: " << nave.getO2Sala(1) << "%";
	consola.gotoxy(30, 10);
	cout << "O2: " << nave.getO2Sala(2) << "%";
	consola.gotoxy(42, 10);
	cout << "O2: " << nave.getO2Sala(3) << "%";
	consola.gotoxy(18, 22);
	cout << "O2: " << nave.getO2Sala(4) << "%";
	consola.gotoxy(30, 22);
	cout << "O2: " << nave.getO2Sala(5) << "%";
	consola.gotoxy(55, 2);
	cout << "Escudo: " << nave.getEscudoSalaEscudo(6) << "%";
	consola.gotoxy(42, 22);
	cout << "O2: " << nave.getO2Sala(6) << "%";
	consola.gotoxy(54, 22);
	cout << "O2: " << nave.getO2Sala(7) << "%";
	consola.gotoxy(6, 34);
	cout << "O2: " << nave.getO2Sala(8) << "%";
	consola.gotoxy(18, 34);
	cout << "O2: " << nave.getO2Sala(9) << "%";
	consola.gotoxy(30, 34);
	cout << "O2: " << nave.getO2Sala(10) << "%";
	consola.gotoxy(42, 34);
	cout << "O2: " << nave.getO2Sala(11) << "%";
	consola.setTextColor(consola.BRANCO);
}

int Nave::getO2Sala(int pos) const
{
	if (salas[pos] == nullptr)
		return -1;
	return salas[pos]->getO2();
}

vector<Sala*> Nave::getVectorSalas() const
{
	return salas;
}


void Nave::preencheSalasAdjacentes()
{
	//Sala 0 (1 - Propulsor)
	salas[0]->adicionaSalaAdjacente(salas[1]);
	
	//Sala 1 (2)
	salas[1]->adicionaSalaAdjacente(salas[0]);
	salas[1]->adicionaSalaAdjacente(salas[2]);
	salas[1]->adicionaSalaAdjacente(salas[4]);

	//Sala 2 (3)
	salas[2]->adicionaSalaAdjacente(salas[1]);
	salas[2]->adicionaSalaAdjacente(salas[3]);
	salas[2]->adicionaSalaAdjacente(salas[5]);

	//Sala 3 (4)
	salas[3]->adicionaSalaAdjacente(salas[2]);
	salas[3]->adicionaSalaAdjacente(salas[6]);
	
	//Sala 4 (5 - Sala m�quinas)
	salas[4]->adicionaSalaAdjacente(salas[1]);
	salas[4]->adicionaSalaAdjacente(salas[5]);
	salas[4]->adicionaSalaAdjacente(salas[9]);
	
	//Sala 5 (6 - Suporte de vida - liga-se a todas as salas por causa de distribuir o oxig�nio)
	for (unsigned int i = 0; i < salas.size(); i++)
		salas[5]->adicionaSalaAdjacente(salas[i]);
	
	//Sala 6 (7 - Controlo de escudo)
	salas[6]->adicionaSalaAdjacente(salas[5]);
	salas[6]->adicionaSalaAdjacente(salas[3]);
	salas[6]->adicionaSalaAdjacente(salas[7]);
	salas[6]->adicionaSalaAdjacente(salas[11]);

	//Sala 7 (8 - Ponte)
	salas[7]->adicionaSalaAdjacente(salas[6]);

	//Sala 8 (9 - Propulsor)
	salas[8]->adicionaSalaAdjacente(salas[9]);

	//Sala 9 (10)
	salas[9]->adicionaSalaAdjacente(salas[8]);
	salas[9]->adicionaSalaAdjacente(salas[4]);
	salas[9]->adicionaSalaAdjacente(salas[10]);
	
	//Sala 10 (11)
	salas[10]->adicionaSalaAdjacente(salas[9]);
	salas[10]->adicionaSalaAdjacente(salas[5]);
	salas[10]->adicionaSalaAdjacente(salas[11]);
	
	//Sala 11 (12)
	salas[11]->adicionaSalaAdjacente(salas[10]);
	salas[11]->adicionaSalaAdjacente(salas[6]);
}

void Nave::removeSalasAdjacentes()
{
	for (unsigned int i = 0; i < salas.size(); i++)
		if(salas[i]!= nullptr)
			salas[i]->eliminaSalaAdjacente();
}

