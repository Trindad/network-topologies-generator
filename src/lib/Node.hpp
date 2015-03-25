#ifndef NODE_H
#define NODE_H
/**
 * Definições de função-membro que aparecem em Nodes.cpp
 */
#include <iostream>
#include <deque>
#include <iterator>
#include <algorithm> //reverse vector
#include <limits> //limites numéricos
#include <stdexcept> // for std::runtime_error
#include <vector>
#include <random>

using namespace std;

class Node
{
public:

	Node();
	~Node();

	/**
	 * Setters
	 */
	void setEdgeNode(int);						//faz uma ligação
	void setDegree();							//aumenta o grau do nó
	void setWeight(int, double);				//atualiza peso de uma ligação
	void setDistanceNode(double);				//atribui distância entre dois nós
	void setDegreeCentrality(int);				//atribui o valor da centralidade de grau
	void setBetweenCentrality(double);			//atribui o valor da centralidade de intermediação	
	void setClosenessCentrality(double);		//atribui o valor da centralidade de proximidade
	void setEfficientCentrality(double);		//atribui o valor da centralidade de eficiência
	void setRelativeDegreeCentrality(double);	//atribui o valor da centralidade relativa de grau

	/**
	 * Getters
	 */
	int getDegree(); 					//retorna o grau do nó passado como parâmetro do método
	bool getEdgeNode(int); 				//verifica a existência de uma ligação entre dois vértices passados como parâmetros
	int getNumberOfPaths();				//número de caminhos mínimos
	int getNumberOfNodes();				//retorna o número de caminhos mínimos
	int getAdjacentNode(int);			//retorna nó adjacente na posição passada como parâmetro
	double getWeightEdge(int);			//retorna o peso da ligação
	void incrementPaths(int);			//incrementa o número de caminhos minimos
	double getDegreeCentrality();		//centralidade do grau	
	double getBetweenCentrality();		//centralidade de intermediação
	double getClosenessCentrality();	//centralidade de proximidade
	double getEfficientCentrality();	//centralidade de eficiência
	vector<int> getAdjacentsNodes();	//retorna vetor de nós adjacentes
	int getNumberOfNodesFromPath(int);	//número de nodos em um caminho minimo

	void addNodePath(int);					//adiciona nodo ao caminho
	void removeNode(int);					//remove nodo da lista de adjacências
	int returnNode(int,int);				//retorna nodo das posições indicadas localizada na matriz de caminhos mínimos
	vector< vector<int> > returnPaths();	//retorna caminhos mínimos 
	void printAdjacents();

private:

	int degree; 					//número de links da topologia
	vector<int> adjacents;  		//vetor de adjacências de um nó
	vector<double> weight;			//vetor de peso de ligações entre nós adjacentes
	
	/**
	 * Variáveis utilizadas para medidas de centralidade
	 */
	int index;						//nodo origem
	int numberOfPaths;				//número de caminhos mínimos
	int degreeCentrality;			//centralidade do grau
	double relativeDegreeCentrality;//centralidade relativa de grau
	double betweenCentrality;		//centralidade de intermediação do nó
	double closenessCentrality;		//centralidade de proximidade
	double efficientCentrality;		//centralidade de eficiência
	vector< vector<int> > paths;	//matriz contendo todos caminhos minimos 
};

#endif