#ifndef NODE_H
#define NODE_H
/**
 * Definições de função-membro que aparecem em Nodes.cpp
 */
#include <iostream>
#include <deque>
#include <iterator>
#include <algorithm> 
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
	void setLinkNode(int);						//faz uma ligação
	void setDegree();							//aumenta o grau do nó
	void setNumberOfPaths(int);					//incrementa o número de caminhos minimos
	void setDistanceNode(double);				//atribui distância entre dois nós
	void setDegreeCentrality(double);			//atribui o valor da centralidade de grau
	void setBetweenCentrality(double);			//atribui o valor da centralidade de intermediação	
	void setClosenessCentrality(double);		//atribui o valor da centralidade de proximidade
	void setEfficientCentrality(double);		//atribui o valor da centralidade de eficiência


	/**
	 * Getters
	 */
	int getDegreeNode(); 				//retorna o grau do nó passado como parâmetro do método
	bool getLinkNode(int); 				//verifica a existência de uma ligação entre dois vértices passados como parâmetros
	int getNumberOfPaths();				//número de caminhos mínimos
	int getNumberOfNodes();				//retorna o número de caminhos mínimos
	int getNumberOfNodesPath(int);		//número de nodos em um caminho minimo
	double getDegreeCentrality();		//centralidade do grau	
	double getBetweenCentrality();		//centralidade de intermediação
	double getClosenessCentrality();	//centralidade de proximidade
	double getEfficientCentrality();	//centralidade de eficiência
	vector<int> getAdjacentsNodes();	//retorna vetor de nós adjacentes



	void addNodePath(int);				//adiciona nodo ao caminho
	int returnNode(int,int);			//retorna nodo das posições indicadas localizada na matriz de caminhos mínimos

private:

	int degree; 					//número de links da topologia
	vector<int> adjacents;  		//vetor de adjacências de um nó
	vector<double> distances;		//vetor de distâncias de u até v
	
	/**
	 * Variáveis utilizadas para medidas de centralidade
	 */
	int index;						//nodo origem
	int numberOfPaths;				//número de caminhos mínimos
	double degreeCentrality;		//centralidade do grau
	double betweenCentrality;		//centralidade de intermediação do nó
	double closenessCentrality;		//centralidade de proximidade
	double efficientCentrality;		//centralidade de eficiência
	vector<vector<int>> paths;		//matriz contendo todos caminhos minimos 
};

#endif