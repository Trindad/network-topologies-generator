/**
 * Algoritmo de roteamento 
 */

#include "Suurballe.hpp"

Suurballe::Suurballe(){}

Suurballe::~Suurballe(){}

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
		parent = tr.append_child(root,nodes[count]);

		vector<int> adjacents = auxiliar[ nodes[count] ].getAdjacentsNodes();

		unsigned int it = 0;

		/**
		 * inserir nós adjacentes do filho
		 */
		while( it < adjacents.size() )
		{
			
			tr.append_child(parent,adjacents[it]);

			temp[ adjacents[it] ] = adjacents[it];

			temp[ adjacents[it] ] =  adjacents[it];

			it++;	
   		}

   		count++;
   	}

   	kptree::print_tree_bracketed(tr,cout); //imprime árvore

   	cout<<"\n"<<endl;
   	return tr;
}

void Suurballe::updateEdgesWeight(const tree<int>& t, typename tree<int>::iterator iRoot, vector<int> nodes, Graph & graph, int source) 
{

	if( t.empty() )
	{
		return;
	} 
	
	// child1, ..., childn
	int siblingCount = t.number_of_siblings(t.begin(iRoot));
	int siblingNum;

	typename tree<int>::sibling_iterator iChildren;
	
	for (iChildren = t.begin(iRoot), siblingNum = 0; iChildren != t.end(iRoot); ++iChildren, ++siblingNum) 
	{	
		/**
		 * Remove arestas do caminho mínimo de ida
		 * Deixando somente as arestas de volta
		 */
		if ( nodes[ *iRoot ] == *iRoot && nodes[ *iChildren ] == *iChildren)
		{
			graph.setWeight(*iRoot,*iChildren,0.0f);
			graph.removeNode(*iRoot,*iChildren);
		}
		else
		{

			double weight = 0 ;//w'(u,v) = w (w,u) - d(s,v) + d(s,u)

		}

		updateEdgesWeight(t,iChildren,nodes,graph,source);
	}
}

/**
 * Todas as arestas da árvore receberão peso 0
 * Os demais nós será aplicado a fórmula proposta:
 * 		w'(u,v) = w (w,u) - d(s,v) + d(s,u)
 */
void Suurballe::changeEdgesWeights(Graph & graph, tree<int> tr, vector<int> nodes)
{
	int source = *tr.begin();

	/**
	 * Percore árvore atualizando o peso das ligações u --> v
	 * Se o nodo esta no caminho o peso passa a ser 0 (zero)
	 * Do contrário aplica a equação proposta por Suurballe
	 * Sendo s o source e u e v nós pertencentes a árvore
	 * 		w'(u,v) = w (u,v) - d(s,v) + d(s,u)
	 */
	
	int headCount = tr.number_of_siblings(tr.begin());//número de cabeças da árvore

	typename tree<int>::sibling_iterator iRoot = tr.begin();
	
	updateEdgesWeight(tr,iRoot,nodes,graph,source);//atualiza peso e remove ligações
}

bool Suurballe::execute(Graph & graph)
{
	cout<<"Suurballe "<<endl;
	bool survivor = false;
	Dijkstra dijkstra; 
	
	this->distance = vector<vector<int>> (graph.getNumberOfNodes(),vector<int>( graph.getNumberOfNodes(), std::numeric_limits<double>::max() ));
	/**
	 * Para cada par de nós (u,v) 
	 * Obtêm caminho mínimo 
	 */
	for (unsigned int u = 0; u < graph.getNumberOfNodes()-1; u++)
	{
		for(unsigned int v = u+1; v < graph.getNumberOfNodes(); v++)
		{
			cout<<"source "<<u<<" target "<<v<<endl;	
			this->distance[u][v] = this->distance[v][u] = dijkstra.execute(graph,u,v);
		
			this->path.push_back( dijkstra.shortestPath(v) );
		}
	}

	for (int i = 0; i < this->path.size(); i++)
	{
		for (int j = 0; j < this->path[i].size(); j++)
		{
			cout<<" "<<this->path[i][j];
		}
		cout<<endl;
	}

	int iterator = 0;

	for (unsigned int u = 0; u < graph.getNumberOfNodes()-1; u++)
	{
		for (unsigned int v = u+1; v < graph.getNumberOfNodes(); v++)
		{

			Graph auxiliar = graph;

			/**
			 * mudança de peso nas arestas
			 * Monta árvore a partir do nó u
			 */
			tree<int> tr = makeTree(auxiliar, this->path[iterator], u);
			changeEdgesWeights(auxiliar, tr, this->path[iterator]);

			//int distance = dijkstra.execute(graph,u,v);
			//cout<<" distance "<<distance<<endl;

			//vector<int> newPath = dijkstra.shortestPath(v);	

			iterator++;
		}
	}

	return survivor;
}
