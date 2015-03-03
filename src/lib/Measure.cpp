#include "Measure.hpp"

Measure::Measure(){}


Measure::~Measure(){}

void Measure::initialize(vector<Node> & nodes,int n)
{

	this->numberOfNodes = n;

	vector< vector<int> > graph = vector< vector<int> > ( n, vector<int> ( n,0 ) );

	/**
	 * Gera matriz de adjacência do grafo a partir do vetor de nós
	 */
	for ( unsigned int i = 0; i < this->numberOfNodes; i++)
	{
		vector <int> adjacents = nodes[i].getAdjacentsNodes();

		for (unsigned int j = 0; j < adjacents.size(); j++)
		{
			graph[i][ adjacents[j] ] = 1;
		}
	}


}

double Measure::getDegreeCentrality(int index)
{
	return nodes[index].getDegreeCentrality();
}


double Measure::getBetweenCentrality(int index)
{
	return nodes[index].getBetweenCentrality();
}


double Measure::getClosenessCentrality(int index)
{
	return nodes[index].getClosenessCentrality();
}


double Measure::getEfficientCentrality(int index)
{
	return nodes[index].getEfficientCentrality();
}


void Measure::setDegreeCentrality(int index,double value)
{
	nodes[index].setDegreeCentrality(value);
}


void Measure::setBetweenCentrality(int index,double value)
{
	nodes[index].setDegreeCentrality(value);
}


void Measure::setClosenessCentrality(int index,double value)
{
	nodes[index].setClosenessCentrality(value);
}


void Measure::setEfficientCentrality(int index, double value)
{
	nodes[index].setEfficientCentrality(value);
}