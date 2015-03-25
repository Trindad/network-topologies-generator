/**
 * Definição de características de um nó
 */

#include "Node.hpp" /*Inclui  a definição da classe Graph*/

using namespace std;

Node::Node()
{
	this->degree = 0;

	this->numberOfPaths = 0;
}

Node::~Node(){}

void Node::setEdgeNode(int target){

	adjacents.push_back(target);
	weight.push_back(1);//padrão para 1 como havendo ligação

	setDegree();
}

void Node::setDegree(){

	this->degree++;
}

void Node::setDistanceNode(double distance){

	this->weight.push_back(distance);
}

void Node::setWeight(int node, double value)
{

	for (unsigned int i = 0; i < this->adjacents.size(); i++)
	{
		if (this->adjacents[i] == node)
		{
			this->weight[i] = value;

			break;
		}
	}
}

void Node::incrementPaths(int n)
{
	this->numberOfPaths  = this->numberOfPaths + n;
}


void Node::setDegreeCentrality(int value)
{
	this->degreeCentrality = value;
}		

void Node::setBetweenCentrality(double value)
{
	this->betweenCentrality = value;
}

void Node::setClosenessCentrality(double value)
{
	this->closenessCentrality = value;
}


void Node::setEfficientCentrality(double value)
{
	this->efficientCentrality = value;
}


void Node::setRelativeDegreeCentrality(double value)
{
	this->relativeDegreeCentrality = value;
}

double Node::getDegreeCentrality()
{
	return this->degreeCentrality;
}


double Node::getBetweenCentrality()
{
	return this->betweenCentrality;
}


double Node::getClosenessCentrality()
{
	return this->closenessCentrality;
}


double Node::getEfficientCentrality()
{
	return this->efficientCentrality;
}

int Node::getDegree()
{
	return this->degree;
}


vector<int> Node::getAdjacentsNodes() 
{
	return this->adjacents;
}	

/**
 * Verifica se existe ligação
 * Se sim retorna verdadeiro
 * Do contrário falso
 */
bool Node::getEdgeNode(int target){

	for (unsigned int i = 0; i < adjacents.size(); i++)
	{
		if (adjacents[i] == target)
		{
			return true;
		}
	}
	
	return false;
}


int Node::getNumberOfPaths() 
{
	return this->numberOfPaths;
}

int Node::getNumberOfNodesFromPath(int index) 	
{
	return this->paths[index].size();
}

double Node::getWeightEdge(int position)
{
	return this->weight[position];
}	

int Node::getAdjacentNode(int position)
{
	return this->adjacents[position];
}

void Node::addNodePath(int newNode) 
{
	int position = this->numberOfPaths;

	if (paths.size() < position)
	{
		vector<int> i;
		paths.push_back(i);
	}

	this->paths[position-1].push_back(newNode);
}

int Node::returnNode(int nPath, int index)
{
	return this->paths[nPath][index];
}


vector<vector<int>> Node::returnPaths() 
{
	return this->paths;
}

void Node::removeNode(int node)
{
	int n = this->degree;

	for (int i = 0; i < degree; i++)
	{
	
		if (this->adjacents[i] == node)
		{
			this->adjacents.erase(this->adjacents.begin()+i);
			this->degree--;
			break;	
		}	
	}
}

void Node::printAdjacents()
{
	for (unsigned int i = 0; i < this->adjacents.size(); i++)
	{
		cout<<" "<<adjacents[i];
	}
	cout<<endl;
}