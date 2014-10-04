/**
 * Definição de estruturas básicas de um Grafo para redes de telecomunicações
 */
#include <iostream>
#include <deque>
#include <iterator>
#include <algorithm> 
#include <stdexcept> // for std::runtime_error
#include <vector>
#include <random>

#include "Graph.hpp" /*Inclui  a definição da classe Graph*/

using namespace std;

Graph::Graph() {

	setNode(0);					//número de nós
	setAverageDegree(0);		//grau máximo da topologia
	setMinimumDegree(0);		//grau minimo da topologia
	setMaximumDegree(0.0);		//grau médio da topologia
	memsetGraph();
}

Graph::~Graph() {}


void Graph::setLink(int u,int v)
{
	this->graph[u][v] = 1;
	this->graph[v][u] = 1;
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

int Graph::getLink(int u,int v)
{
	if (this->graph[u][v] == 1 && this->graph[v][u])
	{
		return 1;
	}
	return 0;
}

int Graph::getDegree(int node)
{
	int degree = 0;
	/**
	 * Obtêm o grau do node
	 */
	for (int i = 0; i < getNumberOfNodes(); i++)
	{
		degree = this->graph[node][i] + degree ; 
	}

	return degree;
}


int Graph::getNumberOfLinks()
{
	return this->nLinks;
}

int Graph::getNumberOfNodes()
{
	return this->nNodes;
}

int Graph::getMaximumNumberOfLinks() {

	int maximumDegree = (int)(this->maxDegree*this->nNodes)/2; //máximo de ligações que terá a topologia

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
 * Inicializa grafo de ligações com todas as posições em 0
 */
void Graph::memsetGraph() {

	int n = this->nNodes;

	this->graph = vector<vector<int>> (n,vector<int>(n,0));
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