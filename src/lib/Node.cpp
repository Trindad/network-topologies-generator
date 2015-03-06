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

Node::Node()
{
	this->degree = 0;

	this->numberOfPaths = 0;
}

Node::~Node(){}

void Node::setLinkNode(int target){

	adjacents.push_back(target);

	setDegree();
}

void Node::setDegree(){

	this->degree += 1;
}

void Node::setDistanceNode(double distance){

	this->weight.push_back(distance);
}

void Node::incrementPaths(int n)
{
	this->numberOfPaths  = this->numberOfPaths + n;
}


void Node::setDegreeCentrality(double value)
{
	this->degreeCentrality = value;
}		

void Node::setBetweenCentrality(double value)
{
	this->betweenCentrality = value;
}

void Node::setClosenessCentrality(double value)
{
	this->closenessCentrality = value;
}


void Node::setEfficientCentrality(double value)
{
	this->efficientCentrality = value;
}

double Node::getDegreeCentrality()
{
	return this->degreeCentrality;
}


double Node::getBetweenCentrality()
{
	return this->betweenCentrality;
}


double Node::getClosenessCentrality()
{
	return this->closenessCentrality;
}


double Node::getEfficientCentrality()
{
	return this->efficientCentrality;
}

int Node::getDegreeNode(){

	return this->degree;
}


vector<int> Node::getAdjacentsNodes() 
{
	return this->adjacents;
}	

/**
 * Verifica se existe ligação
 * Se sim retorna verdadeiro
 * Do contrário falso
 */
bool Node::getLinkNode(int target){

	for (unsigned int i = 0; i < adjacents.size(); i++)
	{
		if (adjacents[i] == target)
		{
			return true;
		}
	}
	
	return false;
}


int Node::getNumberOfPaths() 
{
	return this->numberOfPaths;
}

int Node::getNumberOfNodesFromPath(int index) 	
{
	return this->paths[index].size();
}	

void Node::addNodePath(int newNode) 
{
	//cout<<"ENTROU AQUI AGORA "<<this->numberOfPaths<<endl;
	int position = this->numberOfPaths;

	if (paths.size() < position)
	{
		vector<int> i;
		paths.push_back(i);
	}

	cout<<"POSITION "<<position<<endl<<"Node "<<newNode<<endl;
	paths[position-1].push_back(newNode);
}

int Node::returnNode(int nPath, int index)
{
	return this->paths[nPath][index];
}


vector<vector<int>> Node::returnPaths() 
{
	return this->paths;
}