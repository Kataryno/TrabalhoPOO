#include "misterioso.h"
#include "sala.h"
#include "unidade.h"

void Misterioso::InicioTurno(Unidade * unidade, Sala * sala)
{
	// Como � fun��o virtual na classe base, tem de constar na classe derivada mesmo que nada fa�a
}

void Misterioso::FimTurno(Unidade * unidade, Sala * sala)
{
	if (unidade->getOculta())
	{
		vector<Sala *> s;
		s = unidade->getSalasNave();
		unidade->setOculta(false);
		int idSala = rand() % 11;
		unidade->setSalaUnidade(s[idSala]);
	}
	else
	{
		int probEvento = rand() % 100 + 1;
		if (probEvento <= 25)					//Compara o n� gerado com a percentagem definida
			unidade->setOculta(true);
	}
}
 
Misterioso::Misterioso() : Caracteristica("Misterioso")
//Misterioso::Misterioso(int p) : Caracteristica("Misterioso")
{
	//pontos = p;
}

string Misterioso::getAsString() const
{
	ostringstream oss;
	oss << "\n  N�o tem Pontos " << endl;
	//oss << "\n   Pontos " << pontos << endl;
	return oss.str();
}
