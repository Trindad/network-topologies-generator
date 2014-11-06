/**
 * Definições de função-membro que aparecem em Graph.cpp
 */
#include <iostream>
#include <deque>
#include <iterator>
#include <algorithm> 
#include <stdexcept> // for std::runtime_error
#include <vector>
#include <random>

#include "Node.hpp"

using namespace std;

class Graph
{
public:

	Graph();
	~Graph();

	/**
	 * Setters
	 */
	void setLink(int,int);
	void setNode(int);
	void setAverageDegree(double);
	void setMinimumDegree(int);
	void setMaximumDegree(int);
	void setMinimumDistanceOfNode(int);
	void setDistancePairofNodes(int,int,double);



	/**
	 * Getters
	 */
	int getDegree(int); 	//retorna o grau do nó passado como parâmetro do método
	int getLink(int,int); 	//verifica a existência de uma ligação entre dois vértices passados como parâmetros
	int getNumberOfLinks();	
	int getMinimumDegree();
	int getMaximumDegree();
	int getNumberOfNodes();
	double getAverageDegree();
	int getMinimumDistanceOfNode();
	int getMinimumNumberOfLinks();
	int getMaximumNumberOfLinks();

	int limitLinks(int); 
	void memsetGraph();

private:

	int nLinks; 					//número de links da topologia
	int nNodes;						//número de nós da topologia
	int maxDegree;					//grau máximo da topologia
	int minDegree;					//grau minimo da topologia
	double avgDegree;				//grau médio da topologia
	int minDistance; 				//distancia minima entre um par de vertices/nós
	vector <Node> nodes;			//vetor de informações de um nó do grafo
};

