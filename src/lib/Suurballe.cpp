/**
 * Algoritmo de roteamento 
 */

#include "Suurballe.hpp"

Suurballe::Suurballe(){}

Suurballe::~Suurballe(){}

void Suurballe::insereSubtreee(Graph graph, tree<int> &tr, typename tree<int>::iterator root,vector<int> nodes, vector<int> &controller, int source)
{
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

	//kptree::print_tree_bracketed(tr,cout); //imprime árvore
	
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
		double weight = 0.0f ;//w'(u,v) = w (w,u) - d(s,v) + d(s,u)

		for (iChildren = t.begin(iRoot), siblingNum = 0; iChildren != t.end(iRoot); ++iChildren, ++siblingNum) 
		{	
			weight = 0.0f;
			int u = *iRoot, v = *iChildren;

			/**
			 * Remove arestas do caminho mínimo de ida
			 * Deixando somente as arestas de volta
			 */
			if ( nodes[ u ] == u && nodes[ v ] == v)
			{
				graph.setWeightEdgeDirected(u,v,weight);
				graph.removeNode(u,v);
				cout<<"w("<<u<<" , "<<v<<" ) = "<<weight<<endl;
			}
			else
			{
				

				weight = this->distance[u][v] - this->distance[source][v] + this->distance[source][u];
				//cout<<" "<<this->distance[u][v]<<" "<<this->distance[source][v]<<" "<<this->distance[source][u]<<endl;
				cout<<"w("<<u<<" , "<<v<<" ) = "<<weight<<endl;
				graph.setWeightEdgeDirected(u,v,weight);

				u = *iChildren, v = *iRoot;

				weight = this->distance[u][v] - this->distance[source][v] + this->distance[source][u];

				graph.setWeightEdgeDirected(u,v,weight);

				cout<<"w("<<u<<" , "<<v<<" ) = "<<weight<<endl;
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

	while( count < nodes.size() )
	{
		temp[ nodes[count] ] = nodes[count];

		count++;
	}

	updateEdgesWeight(tr,iRoot,temp,graph,source);//atualiza peso e remove ligações


}

void Suurballe::makePathVector(vector<int> p1,vector<int> &p2, vector<int> &inPath)
{
	for ( unsigned int u = 0; u < p1.size()-1; u++)
	{
		p2.push_back( p1[u] );
		p2.push_back( p1[u+1] );

		inPath[ p1[u] ] = p1[u];
		inPath[ p1[u+1] ] = p1[u+1];
	}
}

vector<int> Suurballe::disjointPath(int target)
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
 * armazena nós visitados em visited
 */
bool Suurballe::findPath(Graph &g, vector<Node> nodes,int source, int target)  
{  
    if( this->visited[source] == 1 || source == target ) return true;  

    this->visited[source] = 1;  

    vector<int> adjacents = nodes[source].getAdjacentsNodes();

    for( int u = 0; u < this->numberOfNodes; u++)  
    {  
    	//verifica se existe ligação
    	if ( find(adjacents.begin(),adjacents.end(),u) != adjacents.end() )
        {  
        	// cout<<"u "<<source<<" v "<<u<<endl;

        	g.removeNode(source,u);
        	this->parent[u] = source;

            if( findPath(g, nodes,u,target) ) return true;                       
        }  
    }

    return false;    
}

bool Suurballe::makeSubgraphDisjointPaths(Graph &g, int source, int target)
{
	vector<Node> nodes = g.getNodes();

	//nó origem com mais de uma aresta de saída
	if ( nodes[source].getAdjacentsNodes().size() >= 3 )
	{
		return false;
	}

	//nó destino possui aresta de saída
	if ( nodes[target].getAdjacentsNodes().size() >= 1 )
	{
		return false;
	}

	int count = 0;

	vector<vector<int>> p;

	while(count < 2)
	{

		this->visited = vector<int> (g.getNumberOfNodes(),0);
		this->parent = vector<int> (g.getNumberOfNodes(),-1);

		findPath(g,nodes,source,target);

		p.push_back( disjointPath(target) );

		nodes = g.getNodes();
		count++;
	}

	nodes = g.getNodes();

	//verifica se os nós não possuem mais nenhuma ligação
	for (int u = 0; u < g.getNumberOfNodes(); u++)
	{
		if (nodes[u].getAdjacentsNodes().size() >= 1 )
		{
			return false;
		}
	}

	return true;
}

bool Suurballe::makeDisjointPaths(vector<int> path1, vector<int> path2)
{

	vector<int> p1,p2;

	vector<int> temp = vector<int> (this->numberOfNodes,-1);

	makePathVector(path1,p1,temp);
	makePathVector(path2,p2,temp);


	/**
	 * Remover arestas invertidas
	 * Dos caminhos mínimos p1 e p2 
	 */
	
	for ( unsigned int u = 0; u < p1.size()-1; u+=2)
	{
		for (unsigned int v = 0; v < p2.size()-1; v+=2)
		{
			//exclui aresta
			if (p1[u] == p2[v+1] && p1[u+1] == p2[v])
			{
				p1.erase( p1.begin() + u );
				p1.erase( p1.begin() + ( u + 1 ) );

				p2.erase( p2.begin() + v );
				p2.erase( p2.begin() + ( v + 1 ) );
			}
		}
	}
	
	/**
	 * Contruir sub-grafo
	 */
	vector< vector<int> > subGraph = vector< vector<int> > ( this->numberOfNodes, vector<int> (this->numberOfNodes,0) ); 
	
	Graph g;

	g.setNumberOfNodes(this->numberOfNodes);

	g.memsetGraph();

	/**
	 * Insere as arestas e seus respectivos pesos 
	 */
	g.setMaximumDegree(g.getNumberOfNodes()-1);
	g.setMinimumDegree(1);


	for (int u = 0; u < p1.size(); u+=2)
	{
		g.setEdgeDirected(p1[u],p1[u+1]);
	}

	for (int u = 0; u < p2.size(); u+=2)
	{
		g.setEdgeDirected(p2[u],p2[u+1]);
	}

	cout<<"\n";
	cout<<"----------subGraph------------\n";
	for (int u = 0; u < g.getNumberOfNodes(); u++)
	{
		cout<<" node "<<u<<" - ";
		g.printAdjacents(u);
	}
	cout<<"---------------------------------\n";
	

	int source = path1[0];
	int target = path1[ path1.size()-1 ];

	/**
	 * Verifica se existem duas arestas de saída no source
	 * E duas arestas de entrada no target, além disso deve
	 * haver uma de entrada e uma de saída nos nós restantes
	 */
	vector< vector<int> > path;	
	
	int count = 0;
	
	/**
	 * constrói os caminhos disjuntos
	 * remove arestas já visitadas
	 * constrói novo caminho
	 */

	return makeSubgraphDisjointPaths(g,source,target);
}

bool Suurballe::execute(Graph & graph)
{
	//cout<<"Suurballe "<<endl;
	bool survivor = false;
	Dijkstra dijkstra; 

	this->numberOfNodes = graph.getNumberOfNodes();
	
	this->distance = vector<vector<int>> (this->numberOfNodes,vector<int>( this->numberOfNodes,0) );

	int n = 0;
	/**
	 * Para cada par de nós (u,v) 
	 * Obtêm caminho mínimo 
	 */
	for (unsigned int u = 0; u < this->numberOfNodes-1; u++)
	{
		for(unsigned int v = u+1; v < this->numberOfNodes; v++)
		{
			this->distance[u][v] = this->distance[v][u] = dijkstra.execute(graph,u,v);
		
			this->path.push_back( dijkstra.shortestPath(v) );

			if ( path[n].size() <= 1)
			{
				return survivor;
			}

			n++;
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
			cout<<"----------------------------\n"<<endl;
			cout<<"U "<<u<<" V "<<v<<endl;
			tree<int> tr = makeTree(auxiliar, this->path[iterator], u);
			changeEdgesWeights(auxiliar, tr, this->path[iterator]);

			for (int i = 0; i < this->numberOfNodes; i++)
			{
				auxiliar.printAdjacents(i);
			}
			
			dijkstra.execute(auxiliar,u,v);	

			vector<int> newPath = dijkstra.shortestPath(v);

			cout<<" tamanho do newPath "<<newPath.size()<<endl;
			for (unsigned int i = 0; i < newPath.size(); i++)
			{
				cout<<" "<<newPath[i];
			}

			cout<<"\n";
			
			survivor = makeDisjointPaths(path[iterator],newPath);

			if (survivor == false)
			{
				break;
			}

			cout<<endl;
			cout<<"\n----------------------------\n"<<endl;

			iterator++;
		}
	}

	return survivor;
}
