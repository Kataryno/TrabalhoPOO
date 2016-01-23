#ifndef UNIDADE_H
#define UNIDADE_H

#include "libraries.h"
#include "sala.h"

class Sala;
class Caracteristica;

class Unidade {
	char id;
	string nome;
	Sala * sala;

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
	
	char getId() const;
	int getSala() const;
	int getHp()const;

	void setId(char & identificacao);
	void setSalaTripulacao(Sala * idsala);
	void setSalaInimigo(Sala * idsala);
	void setSalaXenomorfo(Sala * idsala);
	void levaDano(int d);
	void recebeVida(int v);
	void setNome(string n);
	string getNome() const;
};

#endif