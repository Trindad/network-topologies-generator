/**
 * Definições de função-membro que aparecem em Graph.cpp
 */
#include <iostream>
#include <deque>
#include <iterator>
 #include <algorithm> 
#include <stdexcept> // for std::runtime_error

#include "/usr/include/boost/graph/graph_traits.hpp"
#include "/usr/include/boost/graph/adjacency_list.hpp"
using namespace boost;

class Graph
{
public:

	Graph();

	void setLink();
	
	void setNode();

	void setAvarageDegree();

	void setMinimumDegree();

	void setMaximumDegree();


	void getLink();
	
	void getNode();

	void getAvarageDegree();

	void getMinimumDegree();

	void getMaximumDegree();

private:

	typedef adjacency_list <vecS, vecS, undirectedS> UndirectedGraph;
};

