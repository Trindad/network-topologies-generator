#include "Graph.hpp"
#include "Suurballe.hpp"

int main(int argc, char const *argv[])
{
	if (argc <= 1)
	{
		return 0;
	}

	ifstream file;

	file.open(argv[1]);
	
	if (file.is_open())
	{
		string line = " ";

		getline (file,line);

		int n = stoi(line);//obtêm o número de nós

		cout<<"Número de nós: "<<n<<endl;

		while( getline (file,line) )
		{
			cout<<" "<<line<<endl;
		}
		file.close();

	}

	
	return 0;
}