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
	double distance(int s,int t);
	double radiusGraph();
	void createLinks(int s,int t);
	
};