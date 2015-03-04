#include "Measure.hpp"

Measure::Measure(){}


Measure::~Measure(){}

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

void Measure::initialize(vector<Node> & nodes,int n)
{

	this->numberOfNodes = n;

	this->nodes = nodes;

	vector< vector<int> > graph = vector< vector<int> > ( n, vector<int> ( n,0 ) );

	/**
	 * Gera matriz de adjacência do grafo a partir do vetor de nós
	 */
	for ( unsigned int i = 0; i < this->numberOfNodes; i++)
	{
		vector <int> adjacents = this->nodes[i].getAdjacentsNodes();

		for (unsigned int j = 0; j < adjacents.size(); j++)
		{
			graph[i][ adjacents[j] ] = 1;//atribui ligação
		}
	}

	Brandes brandes (this->numberOfNodes);

	/**
	 * Encontra todos os caminhos mínimos entre pares de nós do grafo
	 */
	for (int i = 0; i < this->numberOfNodes; i++)
	{
		brandes.modifiedDijkstra(graph,i,this->nodes);
	}

	/**
	 * Obtendo medidas de centralidade
	 */
	
	betweenCentrality(nodes);	//centralidade de intermediação

	closenessCentrality();		//centralidade de proximidade

	efficientCentrality();		//centralidade de eficiência

	degreeCentrality();			//centralidade de grau


	for (int i = 0; i < this->numberOfNodes; i++)
	{
		for (int j = 0; j < this->numberOfNodes; j++)
		{
			cout<<graph[i][j]<<"\t";
		}
		cout<<"\n";
	}
}


void Measure::degreeCentrality()
{

}


void Measure::closenessCentrality()
{

}


void Measure::efficientCentrality()
{

}

void Measure::betweenCentrality(vector<Node> nodes)
{

	int node = 0;
  	double bc = -1.0;
	double value = 0;

	for (int v = 0; v < this->numberOfNodes; v++)
	{
		double value =  geodesic(nodes,v);

		this->nodes[v].setBetweenCentrality(value);

		if (bc < value)
		{
		  bc = value;
		  node = v;
		}
	}

	this->centralNode = node;
}

/**
 * Calcula a centralidade de intermediação a partir das geodésicas obtidas 
 * pelo algoritmo de Brandes e em seguida retorna a medida.
 */
double Measure::geodesic(vector<Node> nodes,int node)
{

  double bc = 0.0;

  for ( int i = 0; i < this->numberOfNodes-1; i++)
  {
    for (int j = i+1; j < this->numberOfNodes; j++)
    {
      if (j != node && i != j && i != node)
      {
        int nNodes = nodeSearch(nodes[node].returnPaths(), node);

        bc = bc + ( (double)nNodes / (double)nodes[node].getNumberOfPaths() );
      }
    }
  }

  return bc;
}

/**
 *Busca vertice em um ou mais caminhos 
 *parametros de entrada: caminhos e o vertice a ser buscado e o numero de caminhos minimos a ser buscado
 *retorna o numero de vezes que o vertice foi encontrado
 */
int Measure::nodeSearch(vector< vector<int> > path, int node)
{

	int count = 0;

	for (int i = 0; i < nodes[node].getNumberOfPaths(); i++)
	{
		for (int j = 0; j < this->numberOfNodes-1; j++)
	    {
	      if (node == path[i][j] && path[i][j] > -1)
	      {
	        count++;
	      }
	    }
	}

	return count;
}