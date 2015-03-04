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
	setMinimumDistanceOfNode(0);//distância mínima entre um par de nodos
}

Graph::~Graph() {}


void Graph::setLink(int u,int v)
{
	if (getDegree(u) < this->maxDegree  && getDegree(v) < this->maxDegree && u != v)
	{
		this->nodes[v].setLinkNode(u);
		this->nodes[u].setLinkNode(v);

		this->nLinks++;
	}
}

void Graph::setNode(int n)
{
	this->nNodes = n;
	memsetGraph();
}

void Graph::setAverageDegree(double avg) 
{
	this->avgDegree = avg;
	this->nLinks = 0;
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

/**
 * Atribui a distancia eucliana 
 */
void Graph::setDistancePairOfNodes(int u,int v,double distance)
{

	this->nodes[u].setDistanceNode(distance);
	this->nodes[v].setDistanceNode(distance);
}

vector<Node> Graph::getNodes() 
{
	return this->nodes;
}

/**
 * Verifica a existência de ligações
 */
bool Graph::getLink(int u,int v)
{
	if(u == v)
	{
		return true;
	}

	return this->nodes[u].getLinkNode(v);
}

int Graph::getDegree(int node)
{
	return this->nodes[node].getDegreeNode();
}


int Graph::getNumberOfLinks()
{
	return this->nLinks;
}

int Graph::getNumberOfNodes()
{
	return this->nNodes;
}

int Graph::getMaximumNumberOfLinks() 
{
	int maximumDegree = ( ( this->maxDegree * this->nNodes )/ 2 ); //máximo de ligações que terá a topologia

	cout<<"maximo de ligações "<<maximumDegree<<endl;
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

int Graph::getMinimumNumberOfLinks()
{

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
	// cout<<"minima distancia "<<this->minDistance<<endl;
	return this->minDistance;
}

/**
 * Inicializa grafo de ligações com todas as posições em 0
 */
void Graph::memsetGraph() 
{
	this->nodes = vector<Node> (this->nNodes);
}

/**
 * Verifica se o número máximo do grau 
 * no pior caso onde todos os grafos 
 * possuem o mesmo grau ele não ultrapassa o limite
 * Se passar lança uma exception.
 */
void Graph::limitLinks(int max) 
{

	int temp = (this->nNodes*(this->nNodes-1))/2; //número máximo de nós em um grafo completo

	if ( max > temp )	
	{
		throw "2 ≤ Maximum Degree ≤ [N*(N-1)]/2";
	}
}