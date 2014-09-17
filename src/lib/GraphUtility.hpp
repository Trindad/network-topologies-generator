/**
 * Definições de função-membro que aparecem em Dijkstra.cpp
 */

#include <iostream>
#include <deque>
#include <iterator>
#include <algorithm> 
#include <stdexcept> // for std::runtime_error

class GraphUtility
{
public:

	GraphUtility();
	~GraphUtility();
	
	int distance();
	double radiusGraph();
	void createLinks(int,int);
	void Dijkstra();
	void memsetVector(int,int vetor[]);	
};