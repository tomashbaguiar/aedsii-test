#include "chaves.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <iomanip>

using namespace std;

struct Node	{
	SType dado;		//Valor do nó.
	int chave;		//Valor da chave do nó.
};

Set::Set()	{
	size_ = 0;						//Tamanho do vetor.
	capacity_ = 2;					//Capacidade do ponteiro.
	array_ = new Node[capacity_];	//Aloca memória para o vetor.
}

int Set::Size()	{
	return (size_);	//Retorna valor do tamanho do vetor.
}

bool Set::Empty()	{
	return (size_ == 0);	//Retorna vazio (1) ou não-vazio (0).
}

void Set::reserve(int m)	{
	if(m > capacity_)	{	//Se m é maior que capacidade atual:
		capacity_ = m;		//Aumenta capacidade atual.
		Node* aux = new Node[capacity_];	//Auxiliar para alocação.
		for(int i = 0; i < Size(); i++)
			aux[i] = array_[i];				//aux = array_.
		delete [] array_;					//Desaloca array_.
		array_ = aux;		//Aloca memória de aux para array_.
	}
}

void Set::Insere(Node k)	{	//Recebe um nó como entrada.
	if(size_ == capacity_)		//Se houver necessidade,
		reserve(2*capacity_);	// aloca mais memória para o vetor.
	array_[size_] = k;			//Insere o nó no vetor.
	size_++;					//Aumenta o tamanho do vetor.
}

void Set::Imprime()	{			//Imprime os elementos do vetor (valores).
	cout << endl;
	for(int i = 0; i < Size(); i++)
		cout << setw(6) << array_[i].dado;	//Imprime com 6 casas.
	cout << endl;
}

void Set::Imprime_key()	{		//Imprime as chaves do s elementos.
	cout << endl;
	for(int i = 0; i < Size(); i++)
		cout << setw(6) << array_[i].chave;	//Imprime com 6 casas.
	cout << endl;
}
Set::~Set()	{
	delete [] array_;
}

