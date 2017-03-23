#include "criavet.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <iomanip>

using namespace std;

char letras[] = {'a','b','c','d','e','f','g','h','i','j','k',
	'l','m','n','o','p','q','r','s','t','u','v','x','y','z'};

void cria_rand(Set* no, int size, string tipo)	{
	Node valor;		//Nó auxiliar para inserir no vetor.
	int i;

	srand(time(NULL));	//Inicializa srand para gerar valores aleatorios.

	if(tipo == "int")	{		//Se o SType == int.
		for(i = 0; i < size; i++)	{
			valor.dado = rand() % (size*10);	//Elemento gerado aleatoriamente.
			valor.chave = i;					//Valor da chave.
			no->Insere(valor);					//Insere o nó auxiliar no vetor.
		}
	}
	else if(tipo == "char")	{	//Se o SType == char.
		for(i = 0; i < size; i++)	{
			int x = rand() % 25;				//Gera um número aleatório.
			valor.dado = letras[x];				//Com esse número gera um char aletoriamente.
			valor.chave = i;					//Valor da chave.
			no->Insere(valor);					//Insere o nó auxiliar no vetor.
		}
	}
	else
		cout << endl << "Deu errado 'tipo'." << endl;
}

void cria_crescente(Set* no, int size, string tipo)	{
	Node valor;
	int i;

	if(tipo == "int")	{				//Se o SType == int.
		for(i = 0; i < size; i++)	{
			valor.dado = i;				//Recebe o valor de i que é crescente.
			valor.chave = i;			//Valor da chave.
			no->Insere(valor);			//Insere o nó auxiliar no vetor.
		}
	}
	else if(tipo == "char")	{			//Se o SType == char.
		for(i = 0; i < size; i++)	{
			if(i >= 26)					//Acabaram as letras disponíveis.
				valor.dado = 'z';				//Recebe 'z' pois não há valor maior.
			else
				valor.dado = letras[i % 26];	//Recebe valores decrescentes de char.
			valor.chave = i;				//Valor da chave.
			no->Insere(valor);				//Insere o nó auxiliar no vetor.
		}
	}
	else
		cout << endl << "Deu errado 'tipo'." << endl;
}

void cria_decrescente(Set* no, int size, string tipo)	{
	Node valor;
	int i;

	if(tipo == "int")	{				//Se o SType == int.
		for(i = 0; i < size; i++)	{
			valor.dado = (size - i);		//Recebe valores decrescentes.
			valor.chave = i;
			no->Insere(valor);
		}
	}
	else if(tipo == "char")	{					//Se o SType == char.
		for(i = (size - 1); i >= 0; i--)	{
			if(i <= (size - 25))				//Acabaram as letras disponíveis.
				valor.dado = 'a';					//Recebe 'a' pois não há valor menor.
			else
				valor.dado = letras[i % 26];	//Recebe valores decrescentes de char.
			valor.chave = i;
			no->Insere(valor);
		}
	}
	else
		cout << endl << "Deu errado 'tipo'." << endl;
}

bool cria_teste_estab(Set* no, int size, string tipo)	{
	Node valor;
	int i;

	cria_rand(no, size, tipo);						//Cria vetor aleatório.
	no->array_[2].dado = no->array_[0].dado;		//Iguala dois elementos (chaves diferentes).
}
