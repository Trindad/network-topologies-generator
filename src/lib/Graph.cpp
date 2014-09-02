/**
 * Definição de estruturas básicas de um Grafo para redes de telecomunicações
 */
#include <iostream>
#include <deque>
#include <iterator>
 #include <algorithm> 
#include <stdexcept> // for std::runtime_error
#include <string>

#include "Graph.h" /*Inclui  a definição da classe Graph*/


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

void Graph::setMinimumDistance(int min)
{
	this->minDistance = min;
}

//gets
int Graph::getLink()
{
	return this->nLinks;
}

int Graph::getNode()
{
	return this->nNodes;
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

int Graph::getMinimumDistance()
{
	return this->minDistance;
}