/**
 * Definições de função-membro que aparecem em Brandes.cpp
 */
#include <iostream>
#include <deque>
#include <iterator>
/**
 * 
 */
#include <climits>
#include <algorithm> 
#include <stdexcept> // for std::runtime_error
#include <vector>
#include <random>

#include "Node.hpp"

using namespace std;

 class Brandes
 {
 public:

 	Brandes(int);
 	~Brandes();

 	vector< vector<int> > getShortestPath();


 	void insertPaths(vector<Node> &,int,int,int); 
 	void addNode(vector<Node> &, vector< vector<int> > &, int, int, int);
 	int addPaths(vector<Node> &,vector< vector<int> > &,int,int,int);
 	int minimumDistance(vector<int> &, vector<int> &, vector<int> &,int);
 	void modifiedDijkstra(vector< vector<int> >, int ,vector<Node> &);

private:

	int nNodes;							//número de vértices no grafo
	vector<int> nodeAdjacent;			//vetor de nó adjacente
	vector<int> nodeAuxiliar;			//auxiliar  
	vector< vector<int> > shortestPath;	//armazena caminhos minimos de uma origem i à um destino j	

};