#ifndef UNIDADE_H
#define UNIDADE_H

#include "libraries.h"
#include "sala.h"

class Sala;
class Caracteristica;
class Nave;

class Unidade {
	char id;
	string nome;
	Sala * sala;
	Nave * nave;

protected:
	vector <Caracteristica *> caracteristicas;
	
	int hp;
	//bool respira, reparador, combatente, flamenjante, toxico, misterioso, indeciso, regenerador, exoesqueleto, robotico, xenomorfo, casulo, mutandis, hipnotizador, operador, tripulacao, inimigo, move, armado;

public:
	Unidade();
	~Unidade();

	void FimTurno();
	void InicioTurno();

	bool getOperador();
	bool getToxico();

	char getId() const;
	int getSala() const;
	int getHp()const;

	void setNave(Nave * n);
	void setId(char & identificacao);
	void setSalaTripulacao(Sala * idsala);
	void setSalaInimigo(Sala * idsala);
	void setSalaXenomorfo(Sala * idsala);
	void levaDano(int d);
	void recebeVida(int v);
	void setNome(string n);
	string getNome() const;

	virtual void eliminaUnidade();
	void eliminaTripulante();
	void eliminaInimigo();
	void eliminaXenomorfo();
};

#endif