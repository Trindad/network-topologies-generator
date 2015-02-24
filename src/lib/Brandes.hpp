/**
 * Definições de função-membro que aparecem em Brandes.cpp
 */
#include <iostream>
#include <deque>
#include <iterator>
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

 	Brandes();
 	~Brandes();


 	int minimumDistance(vector<int>, vector<int>, vector<int>,int);
 	void insertPaths(vector<Node>,int,int,int); 
 	int addPaths(vector<Node>,vector<vector<int>>,int,int,int);
 	void modifiedDijkstra(vector<vector<int>>, int ,vector<Node>);
 	void addNode(vector<Node>, vector< vector<int> >, int);

private:

	int nNodes;							//número de vértices no grafo
	vector<int> nodeAdjacent;
	vector<int> nodeAuxiliar;
	vector< vector<int> > pathMinimum;	//armazena caminhos minimos de uma origem i à um destino j	

};