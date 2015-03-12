/**
 * Algoritmo de roteamento 
 */

#include "Suurballe.hpp"

Suurballe::Suurballe(){}

Suurballe::~Suurballe(){}

void changeEdgesWeights(Graph & graph, tree<int> tr)
{

}

tree<int> Suurballe::makeTree(Graph graph, vector<int> nodes, int source)
{
	vector<Node> auxiliar;
	auxiliar = graph.getNodes();
   	unsigned int count = 0;

	tree<int> tr;

	tree<int>::iterator root, top, parent;

	top = tr.begin();

   	root = tr.insert( top, source );

   	while( count < nodes.size() )
   	{
   		if (nodes[count] >= 0)
   		{
   			parent = tr.append_child(root,nodes[count]);

   			vector<int> adjacents = auxiliar[ nodes[count] ].getAdjacentsNodes();

   			unsigned int it = 0;

   			/**
   			 * inserir nós adjacentes do filho
   			 */
   			while( it < adjacents.size() )
   			{
   				if (nodes[ adjacents[it] ] == -1)
   				{
   					tr.append_child(parent,adjacents[it]);

   					nodes[ adjacents[it] ] = adjacents[it];
   				}

   				it++;
   			}
   		}

   		count++;
   	}

   	return tr;
}

/**
 * Todas as arestas da árvore receberão peso 0
 * Os demais nós será aplicado a fórmula proposta:
 * 		w'(u,v) = w (w,u) - d(s,v) + d(s,u)
 */
void Suurballe::changeEdgesWeights(Graph & graph, tree<int> tr)
{



}

bool Suurballe::algorithmSuurballe(Graph & graph)
{
	bool survivor = false;
	Dijkstra dijkstra; 
	
	/**
	 * Para cada par de nós encontrar caminhos disjuntos
	 */
	for (unsigned int i = 0; i < graph.getNumberOfNodes(); i++)
	{

		Graph auxiliar = graph;

		int count = 0;

		while (count < 2)
		{

			vector<int> nodes = dijkstra.shortestPath(auxiliar,i);
			
			/**
			 * mudança de peso nas arestas
			 * Monta árvore a partir do nó i
			 */
			tree<int> tr = makeTree(auxiliar, nodes, i);
			changeEdgesWeights(auxiliar, tr);

			count++;
		}

	}

	return survivor;
}
