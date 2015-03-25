/**
 * Definição de estraura para o algoritmo de Dijkstra 
 */

#include "Dijkstra.hpp"

Dijkstra::Dijkstra(){}

Dijkstra::~Dijkstra(){}

/**
 * Insere caminho mínimo ao inverso
 */
vector<int> Dijkstra::shortestPath(int target)
{
	vector<int> path;

	int u = target;

	path.push_back( target );

	while( this->parent[u] != -1 )
	{
		path.push_back( this->parent[u] );
		u = this->parent[u];
	}

	reverse( path.begin(),path.end() );//inverte caminho

	for (unsigned int i = 0; i < path.size(); i++)
	{
		cout<<" "<<path[i];
	}
	cout<<endl;

	return path;
}

/**
 * Implementação baseada no livro The Algorithm Design Manual -- Skiena
 */
int Dijkstra::execute( Graph graph, int source, int target) 
{
	Node p; 					//vetor temporário
	vector<bool> inTree;		//O nó já esta na árvore?
	vector<double> distance;	//armazena distância para source
	int v;						//nó atual
	int w;						//candidato a próximo nó
	int n;						//número de nós adjacentes
	double weight;				//peso da aresta
	double dist;				//melhor distância atual para o nó de partida


	inTree = vector<bool> ( graph.getNumberOfNodes(), false);
	distance = vector<double> ( graph.getNumberOfNodes(), std::numeric_limits<double>::max() );
	this->parent = vector<int> ( graph.getNumberOfNodes(), -1);

	v = source;
	distance[v] = 0;

	while( inTree[target] == false)
	{
		inTree[v] = true;

		p = graph.getNodeAtPosition(v);

		n = p.getDegree();

		if (n == 0)
		{
			cout<<"Topologia com nó "<<v<<" desconexo."<<endl;

			return -std::numeric_limits<double>::max() ;
		}
		
		int iterator = 0;
		
		while( iterator < n )
		{
			w = p.getAdjacentNode(iterator); 
			weight = p.getWeightEdge(iterator); //obtêm peso da aresta

			/**
			 * Verificação de caminho
			 */
			if ( distance[w] > ( distance[v] + weight ) && inTree[w] == false )
			{
				distance[w] = distance[v] + weight;
				this->parent[w] = v;
			}

			iterator++;
		}

		v = 0;

		dist = std::numeric_limits<double>::max();

		for (unsigned int i = 0; i < graph.getNumberOfNodes(); i++)
		{
			if ( ( inTree[i] == false ) && ( dist > distance[i] ) )
			{
				dist = distance[i];
				v = i;		
			}
		}

		if (inTree[v] == true)
		{
			break;
		}
	}

	return distance[target];//retorna distância
}