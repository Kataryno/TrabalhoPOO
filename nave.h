#ifndef NAVE_H
#define NAVE_H

#include "libraries.h"
class Sala;
class Tripulacao;
class Inimigos;
class Consola;
class UniXenomorfo;
class Unidade;

class Nave {
	static int totalTripulantes;
	static int DistanciaPercorrida;
	int integridade;
	vector<Sala *> salas;
	vector<Tripulacao *> tripulantes;
	vector<Inimigos *> inimigos;
	vector<UniXenomorfo *> xenomorfos;
	
	int PosTripulacaoSalaX[11], PosTripulacaoSalaY[11];
	bool AposentoCapitao;
	bool OficinaRobot;
	
public:
	Nave();
	virtual ~Nave();

	string getAsString() const;

	//Test Functions
	void preencheNaveAuto();
	//Get Functions
	string getNomeSala(int pos) const;
	bool getAposentoCapitao();
	bool getOficinaRobot();
	int getDistanciaPercorrida();
	int getIntegridadeSala(int pos) const;
	int getEscudoSalaEscudo(int pos)const;
	int getO2Sala(int pos) const;
	
	vector<Sala *> getVectorSalas()const;
	//Set Functions
	void setAposentoCapitao(bool inf);
	void setOficinaRobot(bool inf);
	//Nave Related
	bool naveConfiguradaSalas() const;
	bool naveConfiguradaTripulantes() const;
	bool naveTripulantesCriados() const;
	void alteraNave(Sala * sala, int pos);
	void avancaNave();
	void resetDistanciaPercorrida();
	bool statusNave();
	void danificaNave(int sala,int dano);
	void FimTurno();
	
	void InicioTurno();

	//Sala Related
	void eliminaSala(int & pos);
	void atribuiSalaTripulante(int & pos, int idSala);
	void atribuiSalaInimigo(int & pos, int idSala);
	void atribuiSalaXenomorfo(int & pos, int idSala);
	int pesquisaSala(string & nome) const;
	void preencheSalasAdjacentes();
	void removeSalasAdjacentes();
	
	void mostraOxigenioSalas(Nave & nave, Consola & consola);
	void mostraIntegridadeSalas(Nave & nave, Consola & consola);
	void mostraEfeitosAmbientaisSalas(Nave & nave, Consola & consola);

	//Tripulação Related
	char getIdTripulante(int & pos) const;
	string mostraTripulantes(Consola & consola) const;
	int pesquisaTripulante(char identificacao) const;
	void mostraOcupanteSala(Consola & consola);
	//void criaTripulacao(const Nave & x);
	void criaTripulacao();
	bool eliminaTripulante(Unidade * unidade);
		
	//Inimigos Related
	void criaInimigos();
	int pesquisaInimigo(char identificacao) const;
	void mostraOcupanteSalaInimigos(Consola & consola);
	bool eliminaInimigo(Unidade * unidade);
	string mostraInimigos(Consola & consola) const;
	string mostraXenomorfos(Consola & consola) const;

	//Xenomorfos Related
	void criaXenomorfos();
	char criaCasulo(int idSala);
	int pesquisaXenomorfo(char identificacao) const;
	void mostraOcupanteSalaXenomorfos(Consola & consola);
	bool eliminaXenomorfo(Unidade * unidade);

	//PARA APAGAR
	void criaBlobs();
};



ostream & operator<<(ostream & saida, const Nave & x);

#endif