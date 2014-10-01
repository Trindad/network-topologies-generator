/**
 * Definição de estruturas básicas de um Grafo para redes de telecomunicações
 */
#include <iostream>
#include <deque>
#include <iterator>
 #include <algorithm> 
#include <stdexcept> // for std::runtime_error
#include <string>

#include "Graph.hpp" /*Inclui  a definição da classe Graph*/

using namespace std;

Graph::Graph() {

	setLink(0); 				//número de links
	setNode(0);					//número de nós
	setAverageDegree(0);		//grau máximo da topologia
	setMinimumDegree(0);		//grau minimo da topologia
	setMaximumDegree(0.0);		//grau médio da topologia
}

Graph::~Graph() {}

//sets
void Graph::setLink(int n)
{
	this->nLinks = n;
}

void Graph::setNode(int n)
{
	this->nNodes = n;
}

void Graph::setAverageDegree(double avg) 
{
	this->avgDegree = avg;
}

void Graph::setMinimumDegree(int min)
{
	this->minDegree = min;
}

void Graph::setMaximumDegree(int max)
{
	this->maxDegree = max;
}

void Graph::setMinimumDistanceOfNode(int min)
{
	this->minDistance = min;
}

//gets
int Graph::getLink()
{
	return this->nLinks;
}

int Graph::getNumberOfNodes()
{
	return this->nNodes;
}

int Graph::getMaximumNumberOfLinks() {

	int maximumDegree = (this->maxDegree*this->nNodes)/2;
	try 
	{
		limitLinks( maximumDegree );
	}
	catch(const char *error) 
	{
		cout<<error<<endl;
	}
	return maximumDegree;
}

int Graph::getMinimumNumberOfLinks() {

	return (this->minDegree*this->nNodes)/2;
}

double Graph::getAverageDegree() 
{
	return this->avgDegree;
}

int Graph::getMinimumDegree()
{
	return this->minDegree;
}

int Graph::getMaximumDegree()
{
	return this->maxDegree;
}

int Graph::getMinimumDistanceOfNode()
{
	return this->minDistance;
}

/**
 * Verifica se o número máximo do grau 
 * no pior caso onde todos os grafos 
 * possuem o mesmo grau ele não ultrapassa o limite
 * Se passar lança uma exception.
 */
int Graph::limitLinks(int max) {

	int temp = (this->nNodes*(this->nNodes-1))/2; //número máximo de nós em um grafo completo

	if ( max > temp )	
	{
		throw "2 ≤ Maximum Degree ≤ [N*(N-1)]/2";
	}
}