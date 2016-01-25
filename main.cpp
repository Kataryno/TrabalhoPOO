#include "libraries.h"
#include "nave.h"
#include "sala.h"
#include "salabeliche.h"
#include "salaescudo.h"
#include "salamaquinas.h"
#include "salacapitao.h"
#include "salaoficina.h"
#include "salaponte.h"
#include "salapropulsor.h"
#include "consola.h"
#include "desenha.h"
#include "tripulacao.h"
#include "eventos.h"
#include "salareparadora.h"
#include "salaraiolaser.h"
#include "salaseguranca.h"
#include "salaenfermaria.h"
#include "salaarmas.h"
#include <time.h>


int escolheOpcao(vector<string> opcoes, Consola & consola, int x, int y);
int n_turnos = 1;
int nivel = 1;
void opcaoConfigurarNave(Nave & nave, Consola & consola);
void opcaoConfigurarTripulacao(Nave & nave, Consola & consola, bool & jogoActivo);
void opcaoPesquisarSala(const Nave & nave);
void preparaConsola(Consola & consola);
void inicioTurno(Nave & nave, Consola & consola);
void faseOrdens(Nave & nave, Consola & consola, bool & jogoActivo);
void fimTurno(Nave & nave, Consola & consola);
void eventos(Nave & nave, Consola & consola);
void TratamentoComandos(Nave & nave, Consola & consola, bool & jogoActivo);

void preparaConsola(Consola & consola)
{
	consola.setTextSize(8, 8);
	consola.setScreenSize(60, 70);
	consola.setBackgroundColor(consola.PRETO);
	consola.clrscr();
	consola.gotoxy(0, 0);
	consola.setTextColor(consola.BRANCO);
}

void inicioTurno(Nave & nave, Consola & consola)
{
	consola.gotoxy(18, 43);
	cout << "TURNO: " << n_turnos << endl;
	nave.InicioTurno();
}

void faseOrdens(Nave & nave, Consola & consola, bool & jogoActivo)
{
	TratamentoComandos(nave, consola, jogoActivo);
}

void fimTurno(Nave & nave, Consola & consola)
{
	nave.FimTurno();
}

void setNivel(Consola & consola)
{
	vector<string> level;
	level.push_back("Facil");
	level.push_back("Medio");
	level.push_back("Dificil");
	level.push_back("Extremo");
	int opcao = 0;
	consola.clrscr();
	desenhaMoldura(consola);

	opcao = escolheOpcao(level, consola, 25, 10);
	switch (opcao)
	{
	case 0: nivel = 1;
		break;
	case 1: nivel = 2;
		break;
	case 2: nivel = 3;
		break;
	case 3: nivel = 4;
		break;
	}
}

void main() {
	
	Consola consola;
	Nave Apollo;

	bool jogoActivo = false,naveDestruida=false;
	const int distanciaFixa = 4000;
	const int distanciaPorNivel = 1000;
	int distanciaTotal = 0;
	
	preparaConsola(consola);
	desenhaMoldura(consola);
	//desenhaNave(Apollo, consola);
	//mostraNomeSalas(Apollo, consola);
	
	vector<string> opcoes;
	opcoes.push_back("Sair");
	opcoes.push_back("Listar");
	opcoes.push_back("Configurar Nave");
	opcoes.push_back("Configurar Tripulacao");
	opcoes.push_back("Pesquisar sala");
	opcoes.push_back("Iniciar Jogo");
	opcoes.push_back("Dificuldade");
	opcoes.push_back("Auto Configurar Nave");//Opção para testes mais rápido

	int opcao = 0;
	do {
		consola.clrscr();
		desenhaMoldura(consola);

		opcao = escolheOpcao(opcoes, consola, 25, 10);
		switch (opcao) {
		case 0: cout << "\nSair\n";
			break;
		case 1: consola.gotoxy(1, 1);
			cout << Apollo.getAsString() << endl;
			consola.gotoxy(1, 57);
			cout << "Prima qualquer tecla para continuar...";
			consola.getch();
			break;
		case 2:	opcaoConfigurarNave(Apollo, consola);
			break;
		case 3:
			if (!Apollo.naveConfiguradaSalas())
			{
				consola.gotoxy(1, 54);
				consola.setTextColor(consola.VERMELHO_CLARO);
				cout << "A nave nao esta completamente configurada. Enquanto nao estiver";
				consola.gotoxy(1, 55);
				cout << "toda configurada nao podera configurar a tripulacao.";
				consola.gotoxy(1, 57);
				consola.setTextColor(consola.BRANCO);
				cout << "Prima qualquer tecla para continuar.";
				consola.getch();
			}
			else
				opcaoConfigurarTripulacao(Apollo, consola, jogoActivo);
			break;
		case 4:opcaoPesquisarSala(Apollo);
			break;
		case 5:
			if (!Apollo.naveConfiguradaSalas())
			{
				consola.gotoxy(1, 54);
				consola.setTextColor(consola.VERMELHO_CLARO);
				cout << "A nave nao esta completamente configurada. Enquanto nao estiver";
				consola.gotoxy(1, 55);
				cout << "toda configurada nao podera configurar a tripulacao.";
				consola.gotoxy(1, 57);
				consola.setTextColor(consola.BRANCO);
				cout << "Prima qualquer tecla para continuar.";
				consola.getch();
			}
 			else
			{
				//Ciclo de jogo
				jogoActivo = true;

				Apollo.resetDistanciaPercorrida();
				n_turnos = 1;

				distanciaTotal = distanciaFixa + distanciaPorNivel * nivel;
				while (1)
				{
		/*			consola.clrscr();
					desenhaMoldura(consola);
					desenhaNave(Apollo, consola);
					mostraNomeSalas(Apollo, consola);
					mostraIdSalas(consola);*/

					inicioTurno(Apollo, consola);
					faseOrdens(Apollo, consola, jogoActivo);
					fimTurno(Apollo, consola);
					if (naveDestruida = Apollo.statusNave())
						break;
					Apollo.avancaNave();

					eventos(Apollo, n_turnos);
					if (naveDestruida = Apollo.statusNave())
						break;
					n_turnos++;

					if (Apollo.getDistanciaPercorrida() >= distanciaTotal)
						break;
				}

				jogoActivo = false;
				if (naveDestruida)
				{
					consola.gotoxy(1, 57);
					cout << "Nave destruída: Fim de Jogo";
					consola.getch();
				}
				else
				{
					consola.gotoxy(1, 57);
					cout << "Chegou ao destino - " << Apollo.getDistanciaPercorrida() << " / " << distanciaTotal;
					consola.getch();
				}
			}
				break;
		case 6: ;
			setNivel(consola);
			break;
		case 7:	
			Apollo.preencheNaveAuto();
			//Apollo.criaBlobs();
			break;
		}

	} while (opcao != 0);

	/*//Ciclo de jogo
	jogoActivo = true;
	
	distanciaTotal = distanciaFixa + distanciaPorNivel * nivel;
	while (1)
	{
		consola.clrscr();
		desenhaMoldura(consola);
		desenhaNave(Apollo, consola);
		mostraNomeSalas(Apollo, consola);
		mostraIdSalas(consola);

		inicioTurno(Apollo, consola);
		faseOrdens(Apollo, consola, jogoActivo);
		fimTurno(Apollo, consola);
		if (naveDestruida = Apollo.statusNave())
			break;
		Apollo.avancaNave();

		eventos(Apollo, consola);
		if (naveDestruida = Apollo.statusNave())
			break;
		n_turnos++;

		if (Apollo.getDistanciaPercorrida() >= distanciaTotal)
			break;
	}

	jogoActivo = false;
	if (naveDestruida)
	{ 
		cout << "Nave destruída: Fim de Jogo" << endl;
	}else
	cout << "Chegou ao destino - " << Apollo.getDistanciaPercorrida() << " / " << distanciaTotal;*/
}

int escolheOpcao(vector<string> opcoes, Consola & consola, int x, int y)
{
	for (unsigned int i = 0; i < opcoes.size(); i++)
	{
		cout << endl;
		consola.gotoxy(x, y+i);
		cout << i << " - " << opcoes[i];
	}
	consola.gotoxy(1, 57);
	cout << "Opcao > ";

	int opcao = -1;
	do {
		cin >> opcao;
	} while (opcao < 0 || opcao > opcoes.size());
	return opcao;
}

bool validaPosicao(int & pos, Consola & consola)
{
	if ((pos >= 2 && pos <= 4) || (pos >= 10 && pos <= 12))
		return true;
	consola.gotoxy(1, 54);
	consola.setTextColor(consola.VERMELHO_CLARO);
	cout << "Essa posicao nao pode ser alterada ou nao existe.";
	consola.gotoxy(1, 55);
	cout << "Escolha uma posicao de 2 a 4 ou de 10 a 12.";
	consola.gotoxy(1, 57);
	consola.setTextColor(consola.BRANCO);
	cout << "Prima qualquer tecla para continuar...";
	consola.getch();
	return false;
}

bool validaPosicao(Consola & consola, int & opcao, Nave & nave, int & pos)
{
	consola.gotoxy(1, 57);	cout << "Posicao: ";
	
	cin >> pos;

	if ((pos >= 2 && pos <= 4) || (pos >= 10 && pos <= 12))
	{
		switch (opcao)
		{
		case 1:	nave.alteraNave(new SalaPropulsor, pos - 1);
			break;
		case 2: nave.alteraNave(new SalaBeliche, pos - 1);
			break;
		case 3: nave.alteraNave(new SalaRaioLaser, pos - 1);
			break;
		case 4: nave.alteraNave(new SalaReparadora , pos - 1);
			break;
		case 5: nave.alteraNave(new SalaSeguranca, pos - 1);
			break;
		case 6: nave.alteraNave(new SalaEnfermaria, pos - 1);
			break;
		case 7: nave.alteraNave(new SalaArmas , pos - 1);
			break;
		}
		return true;
	}
	consola.gotoxy(1, 54);
	consola.setTextColor(consola.VERMELHO_CLARO);
	cout << "Essa posicao nao pode ser alterada ou nao existe.";
	consola.gotoxy(1, 55);
	cout << "Escolha uma posicao de 2 a 4 ou de 10 a 12.";
	consola.gotoxy(1, 57);
	consola.setTextColor(consola.BRANCO);
	cout << "Prima qualquer tecla para continuar...";
	consola.getch();
	return false;
}

void opcaoConfigurarNave(Nave & nave, Consola & consola)
{
	int pos;

	vector<string> opcoes;
	opcoes.push_back("Voltar ao menu anterior");
	opcoes.push_back("Propulsor Adicional");
	opcoes.push_back("Beliche");
	opcoes.push_back("Raio Laser");
	opcoes.push_back("Auto-reparador");
	opcoes.push_back("Sistema de seguranca interno");
	opcoes.push_back("Enfermaria");
	opcoes.push_back("Sala de armas");
	opcoes.push_back("Alojamento do Capitao");
	opcoes.push_back("Oficina Robotica");

	//Chama função que limpa o vector de salasAddjacecntes de cada sala da nave, no sentido de que se forem efectuas alterações na confiuração da nave, as salas ficam sem ligação às adjacentes.
	nave.removeSalasAdjacentes();

	int opcao = 0;
	do {
		consola.clrscr();
		desenhaMoldura(consola);
		desenhaNave(nave, consola);
		mostraNomeSalas(nave, consola);
		mostraIdSalas(consola);
		
		opcao = escolheOpcao(opcoes, consola, 18, 43);
		switch (opcao) {
		case 0:
			if (!nave.naveConfiguradaSalas())
			{
				consola.gotoxy(1, 54);
				consola.setTextColor(consola.VERMELHO_CLARO);
				cout << "A nave nao esta completamente configurada.";
				consola.gotoxy(1, 55);
				cout << "Enquanto nao estiver toda configurada nao podera jogar.";
				consola.gotoxy(1, 57);
				consola.setTextColor(consola.BRANCO);
				cout << "Deseja voltar ao menu principal? (S/N) > ";
				char tecla;

				while (1) {
					tecla = consola.getch();
					if (tecla == 'N' || tecla == 'n')
					{
						opcao = -1;
						break;
					}
					if (tecla == 'S' || tecla == 's')
						break;
				}
			}
			break;
		case 1:  //A função validaPosicao é overloaded. Atenção aos argumentos
		case 2:
		case 3:
		case 4:
		case 5:
		case 6:
		case 7:validaPosicao(consola, opcao, nave, pos);
			break;
		case 8:consola.gotoxy(1, 57);
			cout << "Posicao: ";
			cin >> pos;
			if (validaPosicao(pos, consola))
			{
				//Verifica se já existe uma sala de Aposento de Capitão. Caso não exista cria uma, senão dá informação de existência e não altera a nave.
				if (!nave.getAposentoCapitao())
				{
					nave.alteraNave(new SalaCapitao, pos - 1);
					nave.setAposentoCapitao(true);
				}
				else
				{
					consola.gotoxy(1, 54);
					consola.setTextColor(consola.VERMELHO_CLARO);
					cout << "So pode existir uma sala de Capitao.";
					consola.gotoxy(1, 55);
					cout << "Escolha outra sala.";
					consola.gotoxy(1, 57);
					consola.setTextColor(consola.BRANCO);
					cout << "Prima uma tecla para continuar.";
					consola.getch();
				}
			}
			break;
		case 9:consola.gotoxy(1, 57);
			cout << "Posicao: ";
			cin >> pos;
			if (validaPosicao(pos, consola))
			{
				//Verifica se já existe uma sala de Oficina Robotica. Caso não exista cria uma, senão dá informação de existência e não altera a nave.
				if (!nave.getOficinaRobot())
				{
					nave.alteraNave(new SalaOficina, --pos);
					nave.setOficinaRobot(true);
				}
				else
				{
					consola.gotoxy(1, 54);
					consola.setTextColor(consola.VERMELHO_CLARO);
					cout << "So pode existir uma sala de Oficina Robotica.";
					consola.gotoxy(1, 55);
					cout << "Escolha outra sala.";
					consola.gotoxy(1, 57);
					consola.setTextColor(consola.BRANCO);
					cout << "Prima uma tecla para continuar.";
					consola.getch();
				}
			}
		}

	} while (opcao != 0);
	
	//Chama função que preenche o vector de salasAddjacecntes de cada sala da nave
	nave.preencheSalasAdjacentes();

	//Para testes. Apagar depois
	nave.criaInimigos();
	//nave.criaXenomorfos();
}

void opcaoConfigurarTripulacao(Nave & nave, Consola & consola, bool & jogoActivo)
{
	string entrada;
	int pos, idSala;

	if (!nave.naveTripulantesCriados())
		nave.criaTripulacao();

	TratamentoComandos(nave, consola, jogoActivo);

	/*while (true)
	{*/
		
		//consola.clrscr();
		//desenhaMoldura(consola);
		//desenhaNave(nave, consola);
		//mostraNomeSalas(nave, consola);
		//mostraIdSalas(consola);
		//nave.mostraOcupanteSala(consola);

		//consola.gotoxy(1, 45);
		//cout << nave.mostraTripulantes() << endl;

		//consola.gotoxy(1, 57);
		//cout << "Comando > ";

		//getline(cin, entrada);
		//if (entrada == "fim")
		//	break;
		//istringstream iss(entrada);

		////Verifica se é comando de mover a tripulação
		//if ((entrada.length() == 2) && (entrada[1] - 48 >= 0 && entrada[1] - 48 <= 9))
		//{
		//	pos = nave.pesquisaTripulante((char)toupper(entrada[0]));
		//	if (pos >= 0)
		//	{
		//		idSala = entrada[1] - 48;
		//		if (idSala >= 0 && idSala <= 12)
		//			nave.atribuiSala(pos, idSala - 1);

		//		
		//	}
		//}
		//else if ((entrada.length() == 3) && (entrada[2] - 48 >= 0 && entrada[2] - 48 <= 9))
		//{
		//	pos = nave.pesquisaTripulante((char)toupper(entrada[0]));
		//	if (pos >= 0)
		//	{
		//		idSala = (entrada[1] - 48) * 10 + (entrada[2] - 48);
		//		if (idSala >= 0 && idSala <= 12)
		//			nave.atribuiSala(pos, idSala - 1);
		//		
		//	}
		//}
		//else
		//{
		//	
		//}
		
	/*}*/
}

void opcaoPesquisarSala(const Nave & nave) {
	string nome;
	cout << "\nPesquisar sala por nome\nNome: ";
	cin >> nome;
	cout << nave.pesquisaSala(nome) << endl;
}

void TratamentoComandos(Nave & nave, Consola & consola, bool & jogoActivo)
{
	string entrada;
	int pos, idSala;

	while (true)
	{
		consola.clrscr();
		desenhaMoldura(consola);
		desenhaNave(nave, consola);
		mostraNomeSalas(nave, consola);
		mostraIdSalas(consola);
		nave.mostraOcupanteSala(consola);
		nave.mostraOcupanteSalaInimigos(consola);
		nave.mostraOcupanteSalaXenomorfos(consola);

		if (jogoActivo)
		{
			consola.gotoxy(40, 40);
			cout << "Distancia percorrida: " << nave.getDistanciaPercorrida();
			consola.gotoxy(40, 42);
			cout << "TURNO: " << n_turnos << endl;
			nave.mostraIntegridadeSalas(nave, consola);
			nave.mostraOxigenioSalas(nave, consola);
			nave.mostraEfeitosAmbientaisSalas(nave, consola);
		}

		//consola.gotoxy(1, 45);
		nave.mostraTripulantes(consola);
		nave.mostraInimigos(consola);
		nave.mostraXenomorfos(consola);
		//cout << nave.mostraTripulantes(consola) << endl;
		consola.gotoxy(2, 57);
		cout << "Comando > ";

		//cin.ignore(1000,'\n'); //limpa o buffer

		getline(cin, entrada);
		if (entrada == "fim")
			break;

		istringstream iss(entrada);

		//Verifica se é comando de mover a tripulação
		if ((entrada.length() == 2) && (entrada[1] - 48 >= 0 && entrada[1] - 48 <= 9))
		{
			pos = nave.pesquisaTripulante((char)toupper(entrada[0]));
			if (pos >= 0)
			{
				idSala = entrada[1] - 48;
				if (idSala >= 0 && idSala <= 12)
					nave.atribuiSalaTripulante(pos, idSala - 1);
			}
		}
		else if ((entrada.length() == 3) && (entrada[2] - 48 >= 0 && entrada[2] - 48 <= 9))
		{
			pos = nave.pesquisaTripulante((char)toupper(entrada[0]));
			if (pos >= 0)
			{
				idSala = (entrada[1] - 48) * 10 + (entrada[2] - 48);
				if (idSala >= 0 && idSala <= 12)
					nave.atribuiSalaTripulante(pos, idSala - 1);
			}
		}
		else
		{
		}
	}
}