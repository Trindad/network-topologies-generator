/**
 * Definições de função-membro que aparecem em Graph.cpp
 */
#include <iostream>
#include <deque>
#include <iterator>
#include <algorithm> 
#include <stdexcept> // for std::runtime_error
#include <string>

class Graph
{
public:

	Graph();
	~Graph();

	/**
	 * Setters
	 */
	void setLink(int);
	void setNode(int);
	void setAverageDegree(double);
	void setMinimumDegree(int);
	void setMaximumDegree(int);
	void setMinimumDistanceOfNode(int);



	/**
	 * Getters
	 */
	int getLink();	
	int getNumberOfNodes();
	double getAverageDegree();
	int getMinimumDegree();
	int getMaximumDegree();
	int getMinimumDistanceOfNode();
	int getMinimumNumberOfLinks();
	int getMaximumNumberOfLinks();

	int limitLinks(int); 

private:

	int nLinks; 		//número de links
	int nNodes;			//número de nós
	int maxDegree;		//grau máximo da topologia
	int minDegree;		//grau minimo da topologia
	double avgDegree;	//grau médio da topologia
	int minDistance; 	//distancia minima entre um par de vertices/nós
};

