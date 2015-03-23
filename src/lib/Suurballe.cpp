/**
 * Algoritmo de roteamento 
 */

#include "Suurballe.hpp"

Suurballe::Suurballe(){}

Suurballe::~Suurballe(){}

void Suurballe::insereSubtreee(Graph graph, tree<int> &tr, typename tree<int>::iterator root,vector<int> nodes, vector<int> &controller, int source)
{
	cout<<"Suurballe source "<<source<<endl;
	Node node = graph.getNodeAtPosition(source);
	vector<int> adjacents = node.getAdjacentsNodes();
	typename tree<int>::iterator temp;
	typename tree<int>::iterator newRoot;
	int newSource = source;

	int it = 0;

	while( adjacents.size() > it )
	{
		if (controller[ adjacents[it] ] == -1)
		{
			temp = tr.append_child( root, adjacents[it] );

			controller[ adjacents[it] ] = adjacents[it];
			
			if( find(nodes.begin(),nodes.end(),adjacents[it]) != nodes.end() )
			{
				cout<<"Entra"<<adjacents[it]<<endl;
				newRoot = temp;
				newSource = adjacents[it];
			}
		}


		it++;
	}

	int n = nodes.size()-1;

	if (source == nodes[n] )
	{
		return;
	}

	insereSubtreee(graph,tr,newRoot,nodes,controller,newSource);
}

tree<int> Suurballe::makeTree(Graph graph, vector<int> nodes, int source)
{
	vector<Node> auxiliar;
	auxiliar = graph.getNodes();

	tree<int> tr;

	tree<int>::iterator root, top, parent;

	top = tr.begin();
   	root = tr.insert( top, source );

   	vector<int> controller = vector<int> (this->numberOfNodes,-1);

   	controller[source] = source;

   	insereSubtreee(graph,tr,root,nodes,controller,source);

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

	if (t.number_of_children(iRoot) == 0) 
	{
		return;	
	} 
	else
	{
		// child1, ..., childn
		int siblingCount = t.number_of_siblings( t.begin(iRoot) );
		int siblingNum;

		typename tree<int>::sibling_iterator iChildren;
		
		for (iChildren = t.begin(iRoot), siblingNum = 0; iChildren != t.end(iRoot); ++iChildren, ++siblingNum) 
		{	
			cout<<"iRoot "<<*iRoot<<" iChildren "<<*iChildren<<endl;
			/**
			 * Remove arestas do caminho mínimo de ida
			 * Deixando somente as arestas de volta
			 */
			if ( nodes[ *iRoot ] == *iRoot && nodes[ *iChildren ] == *iChildren)
			{
				graph.setWeightEdgeDirected(*iRoot,*iChildren,0.0f);
				graph.removeNode(*iRoot,*iChildren);
			}
			else
			{

				double weight = 0.0f ;//w'(u,v) = w (w,u) - d(s,v) + d(s,u)

				weight = distance[ *iRoot ][ *iChildren ] - distance[source][*iChildren] + distance[source][*iRoot];
			
				graph.setWeightEdgeDirected(*iRoot,*iChildren,weight);
			}

			updateEdgesWeight(t,iChildren,nodes,graph,source);
		}
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


	unsigned int count = 0;

	vector<int> temp = vector<int> (this->numberOfNodes,-1);

	while(count < nodes.size())
	{
		temp[ nodes[count] ] = nodes[count];

		count++;
	}

	updateEdgesWeight(tr,iRoot,temp,graph,source);//atualiza peso e remove ligações
}

bool Suurballe::execute(Graph & graph)
{
	cout<<"Suurballe "<<endl;
	bool survivor = false;
	Dijkstra dijkstra; 

	this->numberOfNodes = graph.getNumberOfNodes();
	
	this->distance = vector<vector<int>> (this->numberOfNodes,vector<int>( graph.getNumberOfNodes(), std::numeric_limits<double>::max() ));
	/**
	 * Para cada par de nós (u,v) 
	 * Obtêm caminho mínimo 
	 */
	for (unsigned int u = 0; u < this->numberOfNodes-1; u++)
	{
		for(unsigned int v = u+1; v < this->numberOfNodes; v++)
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

	for (unsigned int u = 0; u < this->numberOfNodes-1; u++)
	{
		for (unsigned int v = u+1; v < this->numberOfNodes; v++)
		{
			Graph auxiliar = graph;

			/**
			 * mudança de peso nas arestas
			 * Monta árvore a partir do nó u
			 */
			cout<<"u "<<u<<" v "<<v<<endl;
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
