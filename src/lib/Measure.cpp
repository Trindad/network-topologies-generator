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

	vector< vector<int> > graph = vector< vector<int> > ( n, vector<int> ( n,0 ) );

	/**
	 * Gera matriz de adjacência do grafo a partir do vetor de nós
	 */
	for ( unsigned int i = 0; i < this->numberOfNodes; i++)
	{
		vector <int> adjacents = nodes[i].getAdjacentsNodes();

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
		brandes.execute(graph,i,nodes);
		cout<<"getNumberOfPaths "<<nodes[i].returnPaths().size()<<endl;
	}

	for (int i = 0; i < this->numberOfNodes; i++)
	{
		for (int j = 0; j < this->numberOfNodes; j++)
		{
			cout<<graph[i][j]<<"\t";
		}
		cout<<"\n";
	}
	/**
	 * Obtendo medidas de centralidade
	 */
	
	vector< vector <int> > shortestPath = brandes.getShortestPath();

	betweenCentrality(nodes);						//centralidade de intermediação

	closenessCentrality(nodes,shortestPath);		//centralidade de proximidade

	efficientCentrality(nodes,shortestPath);		//centralidade de eficiência

	degreeCentrality(nodes);						//centralidade de grau

	for (unsigned int i = 0; i < this->numberOfNodes; i++)
	{
		cout<<"bc["<<i<<"] = "<< nodes[i].getBetweenCentrality();
	}
}


void Measure::degreeCentrality(vector<Node> &nodes)
{

	int maximumDegree = -1;

	for (int i = 0; i < this->numberOfNodes; i++)
	{
		int degree = nodes[i].getDegree();

		nodes[i].setDegreeCentrality(degree);

		double relative = ( (double)degree / (double)(this->numberOfNodes-1) );

		nodes[i].setRelativeDegreeCentrality(relative);

		if (maximumDegree < degree)
		{
			maximumDegree = degree;
		}
	}
}


void Measure::closenessCentrality(vector<Node> &nodes, vector<vector <int> > shortestPath)
{
	for (int i = 0; i < this->numberOfNodes;i++)
	{	
		double sum = 0;
		/**
		 * Guarda a soma das distância de i para 
		 * os demais nós do grafo.
		 */
		for (int j = 0; j < this->numberOfNodes; j++)
		{
			sum += shortestPath[i][j];
		}

		double cc = (double)( 1.0f / sum );

		nodes[i].setClosenessCentrality(cc);
	}
}


void Measure::efficientCentrality(vector<Node> &nodes, vector<vector <int> > shortestPath)
{

	for (int i = 0; i < this->numberOfNodes;i++)
	{	
		int longestPath = 0; 

		/**
		 * Guarda a soma das distância de i para 
		 * os demais nós do grafo.
		 */
		for (int j = 0; j < this->numberOfNodes; j++)
		{
			if (shortestPath[i][j] >  longestPath)
			{
				longestPath = shortestPath[i][j];
				
				double auxiliar = (double)shortestPath[i][j];

				double ef = (double) ( 1 / auxiliar ) ;

				nodes[i].setEfficientCentrality(ef);
			}
		}

	}
}

void Measure::betweenCentrality(vector<Node> & nodes)
{
	int node = 0;
  	double bc = -1.0;
	double value = 0;

	for (int v = 0; v < this->numberOfNodes; v++)
	{
		double value =  geodesic(nodes,v);

		cout<<"bc "<<value<<endl;
		nodes[v].setBetweenCentrality(value);

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

  double bc = 0.0f;

  for ( int i = 0; i < this->numberOfNodes-1; i++)
  {
    for (int j = i+1; j < this->numberOfNodes; j++)
    {
      if (j != node && i != j && i != node)
      {
      	vector< vector<int> > paths;

        int nPaths = pathsSearch(nodes,i,j,paths);

        int nNodes = nodeSearch(paths,node,nPaths);

        cout<<"\n\n\n getNumberOfPaths geodesic "<<nodes[node].getNumberOfPaths()<<endl<<"\n\n";

        bc = bc + ( (double)nNodes / (double)nPaths );
      }
    }
  }

  return bc;
}

/**
 * Encontra o número de caminhos que contêm o vértice de destino
 */
int Measure::pathsSearch(vector<Node> nodes, int source, int target, vector< vector<int> > &paths)
{

	int k = 0,nPaths = 0;

	paths = vector< vector<int> > ( this->numberOfNodes, vector<int>(this->numberOfNodes,-1) );
	
	for (unsigned int i = 0; i < nodes[source].getNumberOfPaths(); i++)
	{
		int auxiliar = nodes[source].getNumberOfNodesFromPath(i)-1;

		if (nodes[source].returnNode(i,auxiliar) == target)
		{
		  for (unsigned int k = 0; k < nodes[source].getNumberOfNodesFromPath(i); k++)
		  {
		    paths[nPaths][k] = nodes[source].returnNode(i,k);
		  }

		  nPaths++;
		}
	}

	return nPaths;

}

/**
 *Busca vertice em um ou mais caminhos 
 *parametros de entrada: caminhos e o vertice a ser buscado e o numero de caminhos minimos a ser buscado
 *retorna o numero de vezes que o vertice foi encontrado
 */
int Measure::nodeSearch(vector< vector<int> > &paths, int node, int nPaths)
{
	int count = 0;

	cout<<"\n\n\n nPaths "<<nPaths<<endl;

	for (unsigned int i = 0; i < nPaths; i++)
	{
		for (unsigned int j = 0; j < this->numberOfNodes-1; j++)
	    {
	      if (node == paths[i][j] && paths[i][j] > -1)
	      {
	        count++;
	      }
	    }
	}

	return count;
}