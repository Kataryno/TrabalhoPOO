#ifndef DESENHA_H
#define DESENHA_H

#include "libraries.h"

class Nave;
class Consola;

void desenhaLinha();
void desenhaNave(Nave & nave, Consola & consola);
void mostraNomeSalas(Nave & nave, Consola & consola);
void mostraIdSalas(Consola & consola);
void Interface(Consola & consola, Nave & nave);
void desenhaMoldura(Consola & consola);
void mostraOcupanteSala(Nave & nave, Consola & consola);

#endif