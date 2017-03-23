#include <stdio.h>
#include <cmath>
#include <time.h>
#include <stdlib.h>
#include <iostream>
#include "chaves.cpp"
#include "sorters.cpp"
#include "criavet.cpp"
#include <iomanip>

using namespace std;

int main(int argc, char *argv[])	{
	Set conj;		//Classe para guardar vetor de nós (chave e elemento).
	int tam;		//Tamanho do vetor.
	bool est = 0;	//Verifica utilização do algoritmo cria_teste_estab.
	string tipo;	//Recebe o tipo dos elementos.

	/* Testa se o numero de parametros fornecidos esta' correto
	o primeiro parametro é o nome do programa,
	o segundo o número de chaves do vetor*/
    if(argc == 3)	{
		tam = atoi(argv[2]);
		tipo = argv[1];
	}
    else
        cout << "Erro!! Verifique os valores de entrada!" << endl;

    /*  PIOR CASO QUICK */
/*    Node aux;
    char pior_quick[] = {'t', 'v', 'y', 'z', 's', 'x', 'u'};//Pior caso Quicksort
    for(int i = 0; i < 7; i++)  {
        aux.dado = pior_quick[i];
        aux.chave = i;
        conj.Insere(aux);
    }*/

//	cria_rand(&conj, tam, tipo);				//Cria arquivo com elementos em ordem aleatória.
//	cria_crescente(&conj, tam, tipo);			//Cria arquivo com elementos em ordem crescente.

    /* PIOR CASO INSERTION  */
	cria_decrescente(&conj, tam, tipo);		//Cria arquivo com elementos em ordem decrescente.

//	est = cria_teste_estab(&conj, 13, tipo);	//Testa estabilidade.

/*	conj.Imprime();			//Imprime vetor de elementos.
	if(est)
		conj.Imprime_key();	//Imprime chaves dos elementos para testar estabilidade.
*/
	select_algor(&conj);	//Seleciona qual algoritmo de ordenação usar.
//    radix(&conj);

/*	conj.Imprime();			//Imprime vetor de elementos.
	if(est)
		conj.Imprime_key();	//Imprime chaves dos elementos para testar estabilidade.
*/
	return 0;
}

