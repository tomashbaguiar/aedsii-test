/*	criavet.h	*/
#ifndef CRIA_H
#define CRIA_H

#include "def.cpp"	//Arquivo que define tipo SType.

//Cria vetores aleatórios.
void cria_rand(Set* no, int size, string tipo);
//Cria vetores crescentes.
void cria_crescente(Set* no, int size, string tipo);
//Cria vetores decrescentes.
void cria_decrescente(Set* no, int size, string tipo);

//Cria vetores para teste de estabilidade, ou seja, com valores iguais (alguns)
bool cria_teste_estab(Set* no, int size, string tipo);

#endif

