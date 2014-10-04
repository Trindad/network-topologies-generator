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
	
	void addNode();
	int distanceMinimum();
	double radiusGraph();
	void Dijkstra();
	void memsetVector(int,int vetor[]);	
	void insertPath();
 	void addPath();
 	int searchPath();
 	int degree(int);
};