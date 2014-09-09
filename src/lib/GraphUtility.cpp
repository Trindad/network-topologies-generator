/**
 * 
 */
#include <iostream>
#include <deque>
#include <iterator>
#include <algorithm> 
#include <stdexcept> // for std::runtime_error

#include "Graph.h"
#include "GraphUtility.h"

using std::cout;
using std::cin;
using std::endl;

GraphUtility::GraphUtility() {

}

/**
 * Cria a ligação entre dois nós
 * s é o nó de origem
 * t é o nó de destino.
 */
void  GraphUtility::createLinks(int s,int t) {

}

/**
 * Calcula a distância entre dois nós
 * s é o destino e t a origem .
 */
double GraphUtility::distance(int s,int t) {

}

void GraphUtility::memsetVector(int n,int vetor[]) {

	int i;

	for (i = 0; i < n; i++)
	{
			vetor[i] = 0;
	}
}