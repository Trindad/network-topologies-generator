/**
 * Definições de função-membro que aparecem em Dijkstra.cpp
 */

#include <iostream>
#include <deque>
#include <iterator>
#include <algorithm> 
#include <stdexcept> // for std::runtime_error

#include "Graph.hpp"

class GraphUtility
{
public:

	GraphUtility();
	~GraphUtility();

	int DFS(Graph,int);//verifica ciclo

private:
	vector<int> visited;
};