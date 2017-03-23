/*	chaves.h	*/
#ifndef CHAVE_H
#define CHAVE_H
#include <iostream>
#include <stdlib.h>
#include <cmath>
#include <string>

#include "def.cpp"	//Arquivo que define tipo SType.

struct Node;			//Struct para nós de elementos, com chave.

//Classe para criar vetor que contenha os elementos e chaves.
class Set	{	
	public:
		Node *array_;	//Ponteiro para vetor de nós de elementos.
		Set();			//Construtor de classe, inicializador.
		void reserve(int m);	//Reserva memória para vetor.
		bool Empty();	//Testa se vetor está vazio.
		int Size();		//Retorna o tamanho do vetor de Set.
		void Insere(Node k);	//Insere o nó k no vetor.
		void Imprime();	//Imprime o vetor na tela.	
		void Imprime_key();		//Imprime o vetor de chaves de elem.
		~Set();			//Destrutor de classe, desaloca memória.
	private:
		int size_;		//Tamanho do vetor.
		int capacity_;	//Capacidade do vetor.
};

#endif
