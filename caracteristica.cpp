#include "caracteristica.h"

Caracteristica::Caracteristica(string n)
{
	nome = n;
}

string Caracteristica::getAsString() const
{
	ostringstream oss;
	oss << "   Nome: " << nome << endl;
	return oss.str();
}

string Caracteristica::getNome() const
{
	return nome;
}