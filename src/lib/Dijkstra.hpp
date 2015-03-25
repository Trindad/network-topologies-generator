#include "Graph.hpp"

#define MAXV 1000

class Dijkstra
{

public:
	Dijkstra();
	~Dijkstra();

	int execute( Graph, int, int );
	vector<int> shortestPath(int);

private:

	vector<int> parent;
};
