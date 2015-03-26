/**
 * Definições de função-membro que aparecem em Graph.cpp
 */

#include "Dijkstra.hpp"
#include "tree.hh"
#include "tree_util.hh"

class Suurballe
{
public:

	Suurballe();
	~Suurballe();

	bool execute(Graph &);								//encontra caminhos disjuntos 
	bool findPath(vector<Node>, int, int);
	tree<int> makeTree(Graph, vector<int>, int);	//insere nós em uma árvore binária
	bool makeDisjointPaths(vector<int>, vector<int>);
	void removeEdges(Graph &);
	void changeEdgesWeights(Graph &, tree<int>, vector<int>);			//atualiza peso dos nós da árvore
	void makePathVector(vector<int>,vector<int> &,vector<int> &inPath);
	void insereSubtreee(Graph, tree<int> &, typename tree<int>::iterator, vector<int>, vector<int> &, int);
	void updateEdgesWeight(const tree<int>& , typename tree<int>::iterator,vector<int>, Graph &, int); 

private:

	int numberOfNodes;
	vector<int> visited;
	vector< vector<int> > path; 	//armazena caminho mínimo 
	vector< vector<int> > distance;	//armazena distância entre um par de nós d(u,v)
};