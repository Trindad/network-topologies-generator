/**
 * Definições de função-membro que aparecem em Graph.cpp
 */
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
	void setEdge(int,int);
	void setNode(int);
	void setAverageDegree(double);
	void setMinimumDegree(int);
	void setMaximumDegree(int);
	void setMinimumDistanceOfNode(int);
	void setDistancePairOfNodes(int,int,double);



	/**
	 * Getters
	 */
	int getDegree(int); 	//retorna o grau do nó passado como parâmetro do método
	bool getEdge(int,int); 	//verifica a existência de uma ligação entre dois vértices passados como parâmetros
	int getNumberOfEdges();	
	int getMinimumDegree();
	int getMaximumDegree();
	int getNumberOfNodes();
	vector<Node> getNodes();
	Node getNodeAtPosition(int);
	double getAverageDegree();
	int getMinimumDistanceOfNode();
	int getMinimumNumberOfEdges();
	int getMaximumNumberOfEdges();

	void limitEdges(int); 
	void memsetGraph();

private:

	int nEdges; 					//número de edges da topologia
	int nNodes;						//número de nós da topologia
	int maxDegree;					//grau máximo da topologia
	int minDegree;					//grau minimo da topologia
	double avgDegree;				//grau médio da topologia
	int minDistance; 				//distancia minima entre um par de vertices/nós
	vector <Node> nodes;			//vetor de informações de um nó do grafo
};

