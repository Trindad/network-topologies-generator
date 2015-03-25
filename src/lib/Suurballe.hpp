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
	tree<int> makeTree(Graph, vector<int>, int);	//insere nós em uma árvore binária
	void changeEdgesWeights(Graph &, tree<int>, vector<int>);			//atualiza peso dos nós da árvore
	void insereSubtreee(Graph, tree<int> &, typename tree<int>::iterator, vector<int>, vector<int> &, int);
	void updateEdgesWeight(const tree<int>& , typename tree<int>::iterator,vector<int>, Graph &, int); 
	vector<vector<int>> makeDisjointPaths(vector<int>, vector<int>);
	void makePathVector(vector<int>,vector<int> &);

private:

	int numberOfNodes;
	vector< vector<int> > path; 	//armazena caminho mínimo 
	vector< vector<int> > distance;	//armazena distância entre um par de nós d(u,v)
};