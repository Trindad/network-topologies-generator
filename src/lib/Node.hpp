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
	void setLinkNode(int);			//faz um ligação
	void setDegreeNode();			//aumenta o grau do nó
	void setDistanceNode(double);	//atribui distância entre dois nós

	/**
	 * Getters
	 */
	int getDegreeNode(); 			//retorna o grau do nó passado como parâmetro do método
	bool getLinkNode(int); 			//verifica a existência de uma ligação entre dois vértices passados como parâmetros
	


private:

	int degree; 					//número de links da topologia
	double betweenCentrality;		//centralidade de intermediação do nó
	double degreeCentrality;		//centralidade do grau
	double closenessCentrality;		//centralidade de proximidade 
	vector<int> adjacents;  		//vetor de adjacências de um nó
	vector<double> distances;		//vetor de distâncias de u até v
};

