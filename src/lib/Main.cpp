#include "Graph.hpp"
#include "Suurballe.hpp"
#include <sstream>

vector<string> &split(const string &s, char delim, vector<string> &elems);

vector<string> split(const string &s, char delim);

int main(int argc, char const *argv[])
{
	if (argc <= 1)
	{
		return 0;
	}

	ifstream file;

	file.open(argv[1]);

	vector<string> pathFile = split(argv[1],'/');

	
	if (file.is_open())
	{
		Graph g;

		string line = " ";

		getline (file,line);

		int n = stoi(line);//obtêm o número de nós

		g.setNumberOfNodes(n);
		g.setMinimumDegree(2);
		g.setMaximumDegree(n-1);

		// cout<<"Número de nós: "<<n<<endl;
		vector<string> nodes;

		while( getline (file,line) )
		{
			nodes = split(line.c_str(),' ');
			// cout<<" "<<nodes[0]<<" "<<nodes[1]<<endl;

			int u = stoi(nodes[0])-1;
			int v = stoi(nodes[1])-1;
			// g.setEdgeDirected(u,v);
			g.setEdge(u,v);
			g.setWeight(u,v,1.0);
			g.setWeight(v,u,1.0);
		}
		
		// g.setWeightEdgeDirected(1-1,8-1,2.0f);
		// g.setWeightEdgeDirected(1-1,7-1,8.0f);
		// g.setWeightEdgeDirected(1-1,2-1,3.0f);
		// g.setWeightEdgeDirected(2-1,3-1,1.0f);
		// g.setWeightEdgeDirected(2-1,6-1,6.0f);
		// g.setWeightEdgeDirected(2-1,7-1,4.0f);
		// g.setWeightEdgeDirected(3-1,4-1,5.0f);
		// g.setWeightEdgeDirected(5-1,4-1,7.0f);
		// g.setWeightEdgeDirected(6-1,5-1,2.0f);
		// g.setWeightEdgeDirected(5-1,8-1,3.0f);
		// g.setWeightEdgeDirected(8-1,6-1,5.0f);
		// g.setWeightEdgeDirected(7-1,4-1,1.0f);

		Suurballe s;

		bool sobrevivente = s.execute(g,pathFile[pathFile.size()-1]);

		cout<<"sobrevivente "<<sobrevivente<<endl;

		file.close();

	}
	
	
	return 0;
}


vector<string> &split(const string &s, char delim, vector<string> &elems) {
    stringstream ss(s);
    string item;
    while (getline(ss, item, delim)) {
        elems.push_back(item);
    }
    return elems;
}


vector<string> split(const string &s, char delim) {
   vector<string> elems;
    split(s, delim, elems);
    return elems;
}