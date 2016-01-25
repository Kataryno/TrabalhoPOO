#include "libraries.h"
#include "nave.h"
#include "eventos.h"
#include "sala.h"
#include "ambientais.h"
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
		/*int probEvento = rand() % 100 + 1;
		if (probEvento < 25)
			eventoPoCosmico(nave);
		else if (probEvento >= 25 && probEvento < 50)
			eventoAtaquePirata;
		else if (probEvento >= 50 && probEvento < 75)
			eventoAtaqueXenomorfo(nave);
		else
		eventoChuvaMeteoritos(nave);*/
		
		turnoEvento = nturnos;
		turnoAleatorio = rand() % (10 - 5 + 1) + 5;
	}
	
}

void eventoChuvaMeteoritos(Nave & nave)
{
	srand((unsigned)time(NULL));
	vector<Sala *> salas = nave.getVectorSalas();
	bool PonteOperada = salas[7]->getOperada();
	bool LaserOperado = false; 
	int PosicaoEscudo;
	int ataques; int restoDano;
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
	if (PonteOperada)
	{
		ataques = rand() % (8-4+1)+4;
		if (LaserOperado)
		{
			for (unsigned int i = 0; i < ataques; i++)
			{
				if (rand() % (50 - 1 + 1) + 1 <= 50)
				{
					if (salas[6]->getEscudo() != 0)
					{
						restoDano=salas[6]->setDiminuiEscudo(10);
						if (restoDano != 0)
						{
							int s = rand() % 12;
							salas[s]->setDiminuiIntegridade(restoDano);
							salas[s]->setBrecha();
						}
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
				if (salas[6]->getEscudo() != 0)
				{
					restoDano = salas[6]->setDiminuiEscudo(10);
					if (restoDano != 0)
					{
						int s = rand() % 12;
						salas[s]->setDiminuiIntegridade(restoDano);
						salas[s]->setBrecha();
					}
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
					if (salas[6]->getEscudo() != 0)
					{
						restoDano = salas[6]->setDiminuiEscudo(10);
						if (restoDano != 0)
						{
							int s = rand() % 12;
							salas[s]->setDiminuiIntegridade(restoDano);
							salas[s]->setBrecha();
						}
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
				if (salas[6]->getEscudo() != 0)
				{
					restoDano = salas[6]->setDiminuiEscudo(10);
					if (restoDano != 0)
					{
						int s = rand() % 12;
						salas[s]->setDiminuiIntegridade(restoDano);
						salas[s]->setBrecha();
					}
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
	int restoDano, efeito,s;
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
	if(salas[6]->getEscudo()==0)//se o escudo estiver a 0, ataca logo uma sala aleatoria
	{ 
		s = rand() % 12;
		salas[s]->setDiminuiIntegridade(dano);
		efeito=rand() % 4;
		switch (efeito)
		{
		case 1:
			salas[s]->setBrecha();
		case 2:
			salas[s]->setFogo();
		case 3:
			salas[s]->setCC();
		}

	}
	else//escudo ainda tem força
	{
		restoDano = salas[6]->setDiminuiEscudo(dano);//dá dano no escudo
		if (restoDano != 0)//se ainda sobrou dano, escolhemos sala aleatoria para receber esse resto
		{
			s = rand() % 12;
			salas[s]->setDiminuiIntegridade(dano);
			efeito = rand() % 4;
			switch (efeito)
			{
			case 1:
				salas[s]->setBrecha();
			case 2:
				salas[s]->setFogo();
			case 3:
				salas[s]->setCC();
			}
		}
	}
		
	if (!LaserOperado)
	{
		nave.criaInimigos();
	}
	
}

void eventoAtaqueXenomorfo(Nave & nave)
{
	nave.criaXenomorfos();
}
