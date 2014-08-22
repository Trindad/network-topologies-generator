/**
 * Definições de função-membro que aparecem em Graph.cpp
 */
#include <iostream>
#include <deque>
#include <iterator>
#include <algorithm> 
#include <stdexcept> // for std::runtime_error

using std::cout;
using std::cin;
using std::endl;

class Graph
{
public:

	Graph();

	void setLink();
	
	void setNode();

	void setAvarageDegree();

	void setMinimumDegree();

	void setMaximumDegree();

	int getLink();
	
	int getNode();

	double getAvarageDegree();

	int getMinimumDegree();

	int getMaximumDegree();

private:

	int nLinks; 		//número de links
	int nNode;			//número de nós
	int maxDegree;		//grau máximo da topologia
	int minDegree;		//grau minimo da topologia
	double avgDegree;	//grau médio da topologia
};

