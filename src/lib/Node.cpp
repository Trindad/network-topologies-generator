/**
 * Definição de características de um nó
 */
#include <iostream>
#include <deque>
#include <iterator>
#include <algorithm> 
#include <stdexcept> // for std::runtime_error
#include <vector>
#include <random>

#include "Node.hpp" /*Inclui  a definição da classe Graph*/

using namespace std;

Node::Node(){

	this->degree = 0;
}

Node::~Node(){}

void Node::setLinkNode(int target){

	this->adjacents.push_back(target);

	setDegree();
}

void Node::setDegree(){

	// cout<<"degree "<<endl;
	this->degree += 1;
}

void Node::setDistanceNode(double distance){

	this->distances.push_back(distance);
}

int Node::getDegreeNode(){

	return this->degree;
}	

/**
 * Verifica se existe ligação
 * Se sim retorna verdadeiro
 * Do contrário falso
 */
bool Node::getLinkNode(int target){
	
	int n = adjacents.size();

	for (int i = 0; i < n; i++)
	{
		if (adjacents[i] == target)
		{
			return true;
		}
	}
	
	return false;
} 		