/**
 * Definição de estruturas básicas de um Grafo para redes de telecomunicações
 */
#include <iostream>
#include <deque>
#include <iterator>
 #include <algorithm> 
#include <stdexcept> // for std::runtime_error

#include "Graph.h" /*Inclui  a definição da classe Graph*/


Graph::Graph() {

	// setLink();
	// setNode();
	// setMaximumDegree();
	// setMaximumDegree();
}

void Graph::setLink(int n)
{
	nLinks = n;
}

void Graph::setNode(int n)
{
	nNodes = n;
}

void Graph::setAverageDegree(double avg) 
{
	avgDegree = avg;
}

void Graph::setMinimumDegree(int min)
{
	minDegree = min;
}

void Graph::setMaximumDegree(int max)
{
	maxDegree = max;
}

int Graph::getLink()
{
	return nLinks;
}

int Graph::getNode()
{
	return nNodes;
}

double Graph::getAverageDegree() 
{
	return avgDegree;
}

int Graph::getMinimumDegree()
{
	return minDegree;
}

int Graph::getMaximumDegree()
{
	return maxDegree;
}