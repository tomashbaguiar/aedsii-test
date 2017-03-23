/*	sorters.h	*/
#ifndef SORTERS_H
#define SORTERS_H
#include <iostream>
#include <stdlib.h>
#include <cmath>
#include <string>

#include "def.cpp"	//Arquivo que define tipo SType.

void swap(Set* no, Node prev, Node next);	//Realiza a troca
										// de elementos no vetor.
void select_algor(Set* no);	//Seleciona algoritmo para ordenar.
void insertion(Set* no);	//Insertionsort
void selection(Set* no);	//Selectionsort
void shell(Set* no);		//Shellsort
void quick(Set* no, int left, int right);		//Quicksort
int partition(Set* no, int left, int right);
void heap(Set* no);		//Heapsort
void buildheap(Set* no, int ini, int fim);
void radix(Set* no);

#endif

