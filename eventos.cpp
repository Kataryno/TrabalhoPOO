#include "libraries.h"
#include "nave.h"
#include "eventos.h"
#include "sala.h"
#include <time.h>

#define N 5
//rand()%(max-min + 1) + min;
int turnoEvento = 0;
int turnoAleatorio = 0;

void eventoPoCosmico(Nave & nave)
{
	srand((unsigned)time(NULL));
	int j = 0, flg = 0;
	int vectorSalasAfectadas[N] = { 99,99,99,99,99 };
	int NsalasAfectadas = rand() % (5 - 3 + 1) + 3;//Gera aleatoriamente o número de salas que serão afetadas, entre 3 e 5
	while (NsalasAfectadas != 0)
	{
		int salaAfectada= rand() % 12; //aleatorio entre 0 e 11
		for (int i = 0; i < N; i++)
		{
			if (vectorSalasAfectadas[i] == salaAfectada)
				flg=1;
		}
		if (flg)
			continue;
		vectorSalasAfectadas[j] = salaAfectada;
		nave.danificaNave(salaAfectada,10);
		j++;
		NsalasAfectadas--;
	}
}

void eventos(Nave & nave, int nturnos)
{
	
	if (turnoEvento + turnoAleatorio <= nturnos || nturnos == 1)
	{
		srand((unsigned)time(NULL));
		int probEvento = rand() % 100 + 1;
		if (probEvento < 25)
			eventoPoCosmico(nave);
		else if (probEvento >= 25 && probEvento < 50)
			;
		else if (probEvento >= 50 && probEvento < 75)
			;
		else;
		turnoEvento = nturnos;
		turnoAleatorio = rand() % (10 - 5 + 1) + 5;
	}
	
}

void eventoChuvaMeteoritos(Nave & nave)
{
	srand((unsigned)time(NULL));
	vector<Sala *> salas = nave.getVectorSalas();
	bool PonteOperada = salas[7]->getOperada();
	bool LaserOperado = false; bool ExisteEscudo = false;
	int PosicaoEscudo;
	int ataques;
	for (unsigned int i = 0; i < salas.size(); i++)
	{
		if (salas[i]->getNome() == "RaioLaser")
		{
			if (salas[i]->getOperada())
			{
				LaserOperado = true;
			}
		}
		if (salas[i]->getNome() == "Escudo")
		{
			ExisteEscudo = true;
			PosicaoEscudo = i;
		}
	}
	if (PonteOperada)
	{
		ataques = rand() % (8-4+1)+4;
		if (LaserOperado)
		{
			for (unsigned int i = 0; i < ataques; i++)
			{
				if (rand() % (50 - 1 + 1) + 1 <= 50)
				{
					if (ExisteEscudo)
					{
						salas[PosicaoEscudo]->setDiminuiEscudo(10);
					}
					else
					{
						int s = rand() % 12;
						salas[s]->setDiminuiIntegridade(10);
						salas[s]->setBrecha();
					}
				}

			}
		}
		else
		{
			for (unsigned int i = 0; i < ataques; i++)
			{
					if (ExisteEscudo)
					{
						salas[PosicaoEscudo]->setDiminuiEscudo(10);
					}
					else
					{
						int s = rand() % 12;
						salas[s]->setDiminuiIntegridade(10);
						salas[s]->setBrecha();
					}	

			}

		}
	}
	else
	{
		ataques = rand() % (12 - 6 + 1) + 6;
		if (LaserOperado)
		{
			for (unsigned int i = 0; i < ataques; i++)
			{
				if (rand() % (50 - 1 + 1) + 1 <= 50)
				{
					if (ExisteEscudo)
					{
						salas[PosicaoEscudo]->setDiminuiEscudo(10);
					}
					else
					{
						int s = rand() % 12;
						salas[s]->setDiminuiIntegridade(10);
						salas[s]->setBrecha();
					}
				}

			}
		}
		else
		{
			for (unsigned int i = 0; i < ataques; i++)
			{
				if (ExisteEscudo)
				{
					salas[PosicaoEscudo]->setDiminuiEscudo(10);
				}
				else
				{
					int s = rand() % 12;
					salas[s]->setDiminuiIntegridade(10);
					salas[s]->setBrecha();
				}

			}

		}

	}
}

void eventoAtaquePirata(Nave & nave)
{
	srand((unsigned)time(NULL));
	vector<Sala *> salas = nave.getVectorSalas();
	bool LaserOperado = false; 
	int restoDano;
	int dano = rand() % (60 - 30 + 1) + 30;
	for (unsigned int i = 0; i < salas.size(); i++)
	{
		if (salas[i]->getNome() == "RaioLaser")
		{
			if (salas[i]->getOperada())
			{
				LaserOperado = true;
			}
		}

	}
	if(salas[6]->getEscudo()==0)
	{ 
		salas[6]->setDiminuiIntegridade(dano);
		//falta tratar parte danos ambientais
	
	}
	else
	{
		restoDano = salas[6]->setDiminuiEscudo(dano);
		if (restoDano != 0)
		{
			salas[6]->setDiminuiIntegridade(restoDano);
			//falta tratar a parte dos danos ambientais, 
		}
	}
		
	if (!LaserOperado)
	{
		nave.criaInimigos();
	}
	
}
