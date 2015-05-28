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

	bool execute(Graph &, string);								//encontra caminhos disjuntos 
	bool findPath(Graph &, vector<Node>, int, int);
	tree<int> makeTree(Graph, vector<int>, int);						//insere nós em uma árvore binária
	bool makeDisjointPaths(vector<int>, vector<int>);
	void changeEdgesWeights(Graph &, tree<int>, vector<int>);			//atualiza peso dos nós da árvore
	void makePathVector(vector<int>,vector<int> &,vector<int> &inPath);
	void insereSubtreee(Graph, tree<int> &, typename tree<int>::iterator, vector<int>, vector<int> &, int);
	void updateEdgesWeight(const tree<int>& , typename tree<int>::iterator,vector<int>, Graph &, int); 
	vector<int> disjointPath(int);
	bool makeSubgraphDisjointPaths(Graph &, int, int);
	vector<double> averageHops();										//calculo o número médio de saltos para o caminho principal e o de backup

private:

	int numberOfNodes;
	vector<int> visited;
	vector<int> parent;
	int numberOfPaths;
	vector< vector<int> > path; 				//armazena caminho mínimo 
	vector< vector<double> > hopWorking;		//número de saltos(i,j) do principal
	vector< vector<double> > hopBackup;			//número de saltos(i,j) de backup
	vector< vector<int> > distance;				//armazena distância entre um par de nós d(u,v)
	ofstream datas;								//dados obtidos com o algoritmo de Suurballe
};