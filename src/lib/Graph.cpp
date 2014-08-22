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

}

void Graph::setLink(int nLinks)
{

}

void Graph::setNode(int nNodes)
{

}

void Graph::setAvarageDegree(double avgDegree) 
{

}

void Graph::setMinimumDegree(int minDegree)
{

}

void Graph::setMaximumDegree(int maxDegree)
{

}

void Graph::getLink()
{
	return nLinks;
}

int Graph::getNode()
{
	return nNodes;
}

double Graph::getAvarageDegree() 
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