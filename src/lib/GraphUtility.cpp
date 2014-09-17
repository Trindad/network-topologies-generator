/**
 * 
 */
#include <iostream>
#include <deque>
#include <iterator>
#include <algorithm> 
#include <stdexcept> // for std::runtime_error

#include "Graph.hpp"
#include "GraphUtility.hpp"

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
 * [GraphUtility::memsetVector description]
 * @param n     [description]
 * @param vetor [description]
 */
void GraphUtility::memsetVector(int n,int vetor[]) {

	int i;

	for (i = 0; i < n; i++)
	{
			vetor[i] = 0;
	}
}