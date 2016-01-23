class Caracteristica {

public:
	virtual void iniciaTurno(Unnidade * uni) = 0;
	virtual void terminaTurno(Unidade * uni) = 0;
	//eventualmente outras funções correspondentes a ouros momentos do turno
	virtual Caracteristica * duplica() const = 0;

};


class Reparador::public Caracteristica{
	int n;
public:
	Caracteristica * duplica() const { return new Reparador(*this); }
	Reparador(int nn) :n(nn) {}
	void iniciaTurno(Unidade * uni) {}
	void terminaTurno(Unidade * uni) {
		if (uni->getEmCombate()) return;
		uni->getSala()->repara(n);
	}
};

coisas
boas
class Unidade {
	//...etc
	Sala * sala;
	vector<Caractristica *> caracteristicas;
public:
	Unidade (Sala * s) : sala(s){}
	Unidade(const Unidade & ob) {

	}
	virtual ~Unidade() {
		for (int i = 0; i < caracteristicas.size(); i++)
			delete caracteristicas[i];
	}
	Unidade & operator=(const Unidade & ob) {
		if (this == ob)
			return *this;
		for (int i = 0; i < caracteristicas.size(); i++)
			delete caracteristicas[i];
		caracteristicas.clear();
		for (int i = 0; i < ob.caracteristicas.size(); i++)
			caracteristicas.pushback(ob.caracteristicas[i]->duplica());
		sala = ob.sala;
		return *this;
	}

	addCaracteristica(Caracteristica * c){}
	void iniciaTurno(-.....)
	{
		for (int i = 0; i < caracteristicas.size(); i++)
			caracteristicas[i]->iniciaTurno(this);
	}
	void terminaTurno(...) {
		for (..............)
			caracteristicas[i]->terminaTurno(this);
	}
	//etc...
};


class Nave {
	vector<Sala *> salas;
	vector<Xenomorfo *> xenomorfos;
	vector<Inimigos *> inimigos;
	vector<Tripulacao *> tripulacao;

public:
	void iniciaTurno() {
		for (int i = 0; i < sala.size(); i++)
			salas[i]->iniciaTurno();
		for (int i = 0 .............)
			xenomorfos[i]->iniciaTurno();
		for (....................)
			tripulacao[i]->iniciaTurno();
	}

};