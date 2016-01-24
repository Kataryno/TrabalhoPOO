#ifndef SALA_H
#define SALA_H

#include "libraries.h"

class Unidade;
class Tripulacao;


class Sala {
	string nome;
	int id;
	bool brecha, fogo, curtocircuito;
	vector<Unidade *> ocupantesTripulacao;
	vector<Unidade *> ocupantesXenomorfos;
	vector<Unidade *> ocupantesInimigos;
	vector<Sala *> salasAdjacentes;

protected:
	int saude;
	int o2;
	int integridade;
	
	

	void setNome(string n) {
		nome = n;
	}
public:
	Sala();
	~Sala();
	virtual string getAsString()const;
	virtual void FimTurno(vector <Sala *> salas) = 0;
	virtual int setDiminuiEscudo(int dano) = 0;

	//get Fuctions
	bool getOperada() const;
	int getSaude() const;
	int getIntegridade() const;
	int getO2()const;
	bool getBrecha()const;
	bool getFogo()const;
	bool getCC()const;
	string getNome() const;
	int getId() const;
	virtual int getEscudo()const = 0;
	vector <Unidade *> getTripulacao()const;
	vector <Unidade *> getInimigos()const;
	vector <Unidade *> getXenomorfos()const;
	//set Functions
	void setId(int idSala);
	void setDiminuiIntegridade(int n);
	void setAumentaIntegridade(int n);
	void setDiminuiOxigenio(int n);
	void setAumentaOxigenio(int n);
	void setBrecha();
	void setFogo();
	void setCC();
	//ocupantes Related
	bool apagaOcupanteTripulacao(Unidade * ocupante);
	bool apagaOcupanteInimigo(Unidade * ocupante);
	bool apagaOcupanteXenomorfo(Unidade * ocupante);
	bool adicionaOcupanteTripulacao(Unidade * ocupante);
	bool adicionaOcupanteInimigo(Unidade * ocupante);
	bool adicionaOcupanteXenomorfo(Unidade * ocupante);
	void adicionaSalaAdjacente(Sala * sala);
	void eliminaSalaAdjacente();
	int pesquisaOcupanteTripulacao(char identificacao);
	int pesquisaOcupanteInimigo(char identificacao);
	int pesquisaOcupanteXenomorfo(char identificacao);

};

ostream & operator<<(ostream & saida, const Sala & x);

#endif