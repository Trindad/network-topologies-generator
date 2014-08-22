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

	setLink();
	setNode();
	setMaximumDegree();
	setMaximumDegree();
}

void Graph::setLink(int nLinks)
{
	this.nLinks = nLinks;
}

void Graph::setNode(int nNodes)
{
	this.nNodes = nNodes;
}

void Graph::setAverageDegree(double avgDegree) 
{
	this.avgDegree = avgDegree;
}

void Graph::setMinimumDegree(int minDegree)
{
	this.minDegree = minDegree;
}

void Graph::setMaximumDegree(int maxDegree)
{
	this.maxDegree = maxDegree;
}

void Graph::getLink()
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