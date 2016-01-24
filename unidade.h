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
	int maxHP;

protected:
	vector <Caracteristica *> caracteristicas;
	
	int hp;
	

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
	int getMaxHP()const;

	void setMaxHP(int p);
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