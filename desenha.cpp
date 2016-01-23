#include "desenha.h"
#include "consola.h"
#include "nave.h"

void desenhaLinha()
{
	for (int i = 0; i < 11; i++)
	{
		cout << (char)196;
	}
}

void desenhaMoldura(Consola & consola)
{
	consola.gotoxy(0, 0);
	cout << (char)201;
	for (int i = 0; i < 68; i++)
	{
		cout << (char)205;
	}
	cout << (char)187 << (char)186;
	for (int i = 1; i < 58; i++)
	{
		consola.gotoxy(69, i);
		cout << (char)186 << (char)186;
	}
	consola.gotoxy(0, 58);
	cout << (char)200;
	for (int i = 0; i < 68; i++)
	{
		cout << (char)205;
	}
	cout << (char)188;
	consola.gotoxy(1, 1);
}

void mostraOcupanteSala(Nave & nave, Consola & consola)
{
	
}

void desenhaNave(Nave & nave, Consola & consola)
{
	//1ª FILA DE SALAS
	//Desenha linha de cima da 1ª fila de salas
	consola.gotoxy(5, 1);
	cout << (char)218;
	for (int i = 0; i < 3; i++)
	{
		desenhaLinha();
		cout << (char)194;
	}
	desenhaLinha();
	cout << (char)191 << "\n";

	//Desenha colunas da 1º fila de salas
	for (int i = 2; i < 13; i++)
	{
		for (int j = 5; j < 55; j += 12)
		{
			consola.gotoxy(j, i);
			cout << (char)179;
		}
	}

	//Desenha linha de baixo da 1ª fila de salas
	consola.gotoxy(5, 13);
	cout << (char)192;
	for (int i = 0; i < 4; i++)
	{
		desenhaLinha();
		cout << (char)197;
	}
	desenhaLinha();
	cout << (char)191 << "\n";

	//2ª FILA DE SALAS
	//Desenha colunas da 2º fila de salas
	for (int i = 14; i < 25; i++)
	{
		for (int j = 17; j < 68; j += 12)
		{
			consola.gotoxy(j, i);
			cout << (char)179;
		}
	}

	//Desenha linha de baixo da 2ª fila de salas
	consola.gotoxy(5, 25);
	cout << (char)218;
	for (int i = 0; i < 4; i++)
	{
		desenhaLinha();
		cout << (char)197;
	}
	desenhaLinha();
	cout << (char)217 << "\n";

	//3ª FILA DE SALAS
	//Desenha colunas da 3º fila de salas
	for (int i = 26; i < 37; i++)
	{
		for (int j = 5; j < 55; j += 12)
		{
			consola.gotoxy(j, i);
			cout << (char)179;
		}
	}

	//Desenha linha de baixo da 3ª fila de salas
	consola.gotoxy(5, 37);
	cout << (char)192;
	for (int i = 0; i < 3; i++)
	{
		desenhaLinha();
		cout << (char)193;
	}
	desenhaLinha();
	cout << (char)217 << "\n";
}

void mostraNomeSalas(Nave & nave, Consola & consola)
{
	//Escreve nome das salas
	//for (int i = 0; i < 12; i++)
	//{

	//	for (int j = 2; j < 50; j += 12)
	//	{
	//		consola.gotoxy(j, 2);
	//		cout << nave.getNomeSala(i);
	//	}
	//}

	consola.setTextColor(consola.AZUL_CLARO);
	consola.gotoxy(6, 2);
	cout << nave.getNomeSala(0);
	consola.gotoxy(18, 2);
	cout << nave.getNomeSala(1);
	consola.gotoxy(30, 2);
	cout << nave.getNomeSala(2);
	consola.gotoxy(42, 2);
	cout << nave.getNomeSala(3);
	consola.gotoxy(18, 14);
	cout << nave.getNomeSala(4);
	consola.gotoxy(30, 14);
	cout << nave.getNomeSala(5);
	consola.gotoxy(42, 14);
	cout << nave.getNomeSala(6);
	consola.gotoxy(54, 14);
	cout << nave.getNomeSala(7);
	consola.gotoxy(6, 26);
	cout << nave.getNomeSala(8);
	consola.gotoxy(18, 26);
	cout << nave.getNomeSala(9);
	consola.gotoxy(30, 26);
	cout << nave.getNomeSala(10);
	consola.gotoxy(42, 26);
	cout << nave.getNomeSala(11);
	consola.setTextColor(consola.BRANCO);
}

void mostraIdSalas(Consola & consola)
{
	consola.setTextColor(consola.AMARELO_CLARO);
	consola.gotoxy(16, 2);
	cout << "1";
	consola.gotoxy(28, 2);
	cout << "2";
	consola.gotoxy(40, 2);
	cout << "3";
	consola.gotoxy(52, 2);
	cout << "4";
	consola.gotoxy(28, 14);
	cout << "5";
	consola.gotoxy(40, 14);
	cout << "6";
	consola.gotoxy(52, 14);
	cout << "7";
	consola.gotoxy(64, 14);
	cout << "8";
	consola.gotoxy(16, 26);
	cout << "9";
	consola.gotoxy(27, 26);
	cout << "10";
	consola.gotoxy(39, 26);
	cout << "11";
	consola.gotoxy(51, 26);
	cout << "12";
	consola.setTextColor(consola.BRANCO);
}
