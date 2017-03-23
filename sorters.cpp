/*	sorters.cpp	*/
#include "sorters.h"
#include <iostream>
#include <stdlib.h>
#include <string>
#include <cmath>
#include <time.h>

void swap(Set* no, int i, int j)	{
	Node temp;						//NÃ³ auxiliar da troca.
	temp = no->array_[i];
	no->array_[i] = no->array_[j];
	no->array_[j] = temp;
}

void select_algor(Set* no)	{
	int sel = 0;		//VariÃ¡vel para definir qual algoritmo de ordenaÃ§Ã£o usar.
	bool err = 0;		//Verificar erro no switch e nÃ£o deixar imprimir o tempo de exec.
	string alg[] = {"Insertion", "Selection", "Shell","Quick", "Heap"};
	clock_t inicio, fim;	//VariÃ¡veis para contar o tempo de execuÃ§Ã£o do algoritmo de ordenaÃ§Ã£o.
	long double tempo_d;		//Recebe o tempo final de execuÃ§Ã£o se tamanho do vetor > 100000..
	long int tempo_i;		//Recebe o tempo final de execuÃ§Ã£o se tamanho do vetor <= 100000.


	cout << endl << "Deseja ordenar utilizando qual algoritmo:" << endl;
	cout << "	1-Insertion sort;" << endl;
	cout << "	2-Selection sort;" << endl;
	cout << "	3-Shell sort;" << endl;
	cout << "	4-Quick sort;" << endl;
	cout << "	5-Heap sort;" << endl;
	cout << "Digite o nÃºmero escolhido: ";
	cin >> sel;			//Recebe do teclado o algoritmo a ser utilizado.
	cout << endl;

	inicio = clock();	//Recebe o valor do tempo antes da execuÃ§Ã£o do
						// algoritmo de ordenaÃ§Ã£o
	cout << endl << inicio << endl;

	cout << alg[sel - 1] << "sort: " << endl;

	switch (sel)	{
		case 1:	//Insertionsort
			insertion(no);
			break;
		case 2:	//Selectionsort
			selection(no);
			break;
		case 3:	//Shelsort
			shell(no);
			break;
		case 4:	//Quicksort
			quick(no, 0, (no->Size() - 1));
			break;
		case 5:	//Heapsort
			heap(no);
			break;
		default:
			err = 1;
			cout << "Entre com um valor adequado." << endl;
	}

	fim = clock();	//Recebe o valor de tempo para o fim da execuÃ§Ã£o.

	cout << endl << (long double)fim << endl;

	cout << endl << "O tempo de execuÃ§Ã£o da ordenaÃ§Ã£o " << alg[sel - 1];

	if(no->Size() <= 100000)	{
		//Calcula o tempo de execução.
		tempo_d = ((fim - inicio) / (long double)CLOCKS_PER_SEC);
		if(!err)
		cout << " sort foi: " << (long double)(tempo_d) << " segundos." << endl;
	}
	else	{
		//Calcula o tempo de execução.
		tempo_i = ((fim - inicio) / (long int)CLOCKS_PER_SEC);
		if(!err)
		cout << " sort foi: " << (long int)(tempo_i) << " segundos." << endl;
	}

}

void insertion(Set* no)	{
	int j, i;
	Node chv;
	SType key;
	for(j = 1; j < no->Size(); j++)	{
		key = no->array_[j].dado;	//Elemento chave.
		chv = no->array_[j];
		i = j - 1;
		while(i >= 0 && (no->array_[i].dado > key))	{
			no->array_[i + 1] = no->array_[i];	//ComparaÃ§Ã£o.
			i--;
		}
		no->array_[i + 1] = chv;	//Troca.
	}
}

void selection(Set* no)	{
	int i, j, min;
	for(i = 0; i < (no->Size() - 1); i++)	{//Percorre o vetor a partir do primeiro elemento até o último dado.
		min = i;//atribui o elemento no qual será iniciado a comparação como o menor elemento.
		for(j = (i + 1); j < no->Size(); j++)	{ //Loop responsável por encontrar um elemento menor que i.
			if(no->array_[j].dado < no->array_[min].dado)	//Valor de j < min? Sim: min = j.
				min = j;
		}
		if(i != min)
			swap(no, i, min);	//Troca.
	}
}

void shell(Set* no)	{
	int i, d;
	bool flag = 1;						//Marcador booleano.
	d = no->Size();
	while(flag || (d > 1))	{
		flag = 0;
		d = (d + 1)/2;//Elementos são comparados entre d chaves.
		for(i = 0; i < (no->Size() - d); i++)	{
			if(no->array_[i + d].dado < no->array_[i].dado)	{
				swap(no, (i + d), i);
				flag = 1;			//Marca que houve troca.
			}
		}
	}
}

void quick(Set* no, int left, int right)  {
	int i, j, x;
	i = left; //Extremidades da partição declaradas
	j = right;//Extremidades da partição declaradas
	x = no->array_[(left + right)/2].dado; //Seta o pivô
	while(i <= j)	{
		while((no->array_[i].dado < x) && (i < right)) //Procura um elemento na esquerda maior que x.
			i++;
		while((no->array_[j].dado > x) && (j > left))//Procura um elemento na direira menor que x.
			j--;
		if(i <= j)	{
			swap(no, i, j);//troca os itens
			i++;
			j--;
		}
	}
	if(j > left)//Repete o procedimento recursivamente as partições criadas.
		quick(no, left, j);
	if(i < right)
		quick(no, i, right);
}

void buildheap(Set* no, int ini, int fim)	{
	Node aux;
	aux = no->array_[ini];//Inicializa o aux como pai.
	int child = (2*ini) + 1; //Primeiro filho declarado.
	while(child <= fim)	{ //Verifica se o vetor é ímpar ou par.
		if(child < fim)	{
			if(no->array_[child].dado <
				no->array_[child + 1].dado)	//Qual o maior filho?
				child++;
		}
		if(aux.dado < no->array_[child].dado)	{	//Filho > pai?
			no->array_[ini] = no->array_[child];	//Filho = pai.
			ini = child;
			child = (2*ini) + 1;
		}
		else
			child = fim + 1;
	}
	no->array_[ini] = aux;	//Antigo pai ocupa o lugar do último filho
}								// analisado.

void heap(Set* no)   {
	int i;
	for(i = (no->Size() - 1)/2; i >= 0; i--) {	//Cria o monte.
        buildheap(no, i, (no->Size() - 1));
    }

    for(i = (no->Size() - 1); i >= 1; i--)  {
        swap(no, 0, i);		//Troca o maior elemento do monte e o coloca
										//na sua posição correspondente.
        buildheap(no, 0, (i - 1));				//Reconstrói o monte.
    }
}

void radix(Set* no)    {
    int i, exp;
    Node *aux;
    aux = new Node[no->Size()];
    Node maior = no->array_[0];
    exp = 1;
    for(i = 0; (i < no->Size()); i++)   {
        if(no->array_[i].dado > maior.dado)
            maior = no->array_[i];
    }
    while((maior.dado/exp) > 0) {
        SType bucket[10] = {0};
        for(i = 0; (i < no->Size()); i++)
            bucket[(no->array_[i].dado/exp)%10]++;
        for(i = 0; i < 10; i++)
            bucket[i] += bucket[i - 1];
        for(i = (no->Size() - 1); i>= 0; i--)
            aux[--bucket[(no->array_[i].dado/exp)%10]] = no->array_[i];
        for(i = 0; (i < no->Size()); i++)
            no->array_[i] = aux[i];
        exp *= 10;
    }
}
