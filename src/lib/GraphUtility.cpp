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
 * Armazena em uma matriz de adjacências
 */
void  GraphUtility::createLinks(int s,int t) {

}

/**
 * Preenche todas as posições de uma matriz com zero(0)
 */
void GraphUtility::memsetVector(int n,int vetor[]) {

	int i;

	for (i = 0; i < n; i++)
	{
			vetor[i] = 0;
	}
}

/**
 * Obtêm o  grau do nó passado como parâmetro do método
 */
int GraphUtility::degree(int node) {
	int degree  = 0;

	return degree;
}