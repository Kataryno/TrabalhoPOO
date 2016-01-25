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
	int maxHP;
	Nave * nave;
	bool oculta;

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
	bool getOculta() const;
	void setOculta(bool o);
	int getSala() const;
	int getHp()const;
	void setHp(int pontos);
	int getMaxHP()const;
	
	vector <Caracteristica *> getCaracteristicas()const;

	void setCaracteriscaArmado();
	void setMaxHP(int p);
	void setNave(Nave * n);
	vector<Sala*> getSalasNave();
	void setId(char & identificacao);

	virtual void setSalaUnidade(Sala * idsala);
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