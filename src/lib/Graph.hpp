/**
 * Definições de função-membro que aparecem em Graph.cpp
 */
#ifndef DIJKSTRA_H
#define DIJKSTRA_H

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
	void setNumberOfNodes(int);
	void setEdge(int,int); 				//para grafo não dirigido
	void setEdgeDirected(int,int);		//para grafo dirigido
	void setMinimumDegree(int);
	void setMaximumDegree(int);
	void setAverageDegree(double);
	void removeEgde(int,int);
	void setWeight(int,int,double);
	void setWeightEdgeDirected(int, int, double);
	void setMinimumDistanceOfNode(int);
	void setDistancePairOfNodes(int,int,double);


	/**
	 * Getters
	 */
	int getDegree(int); 		//retorna o grau do nó passado como parâmetro do método
	bool getEdge(int,int); 		//verifica a existência de uma ligação entre dois vértices passados como parâmetros
	int getNumberOfEdges();		//número máximo de arestas do grafo
	int getMinimumDegree();		//número mínimo do grau
	int getMaximumDegree();		//número máximo do grau
	int getNumberOfNodes();		//número de nós do grafo
	vector<Node> getNodes();	//retorna um vetor de nós do grafo
	double getAverageDegree();	//retorna grau médio do grafo
	Node getNodeAtPosition(int);
	int getMinimumDistanceOfNode();
	int getMinimumNumberOfEdges();
	int getMaximumNumberOfEdges();

	void memsetGraph();
	void limitEdges(int); 
	void removeNode(int,int);
	void printAdjacents(int);

private:

	int nEdges; 					//número de edges da topologia
	int nNodes;						//número de nós da topologia
	int maxDegree;					//grau máximo da topologia
	int minDegree;					//grau minimo da topologia
	double avgDegree;				//grau médio da topologia
	int minDistance; 				//distancia minima entre um par de vertices/nós
	vector <Node> nodes;			//vetor de informações de um nó do grafo
};

#endif