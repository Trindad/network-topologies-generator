/**
 * Definições de função-membro que aparecem em Regions.cpp
 */

#include <iostream>
#include <deque>
#include <iterator>
#include <algorithm> 
#include <stdexcept> // for std::runtime_error
#include <vector>

using namespace std;

class Plane
{
public:

	Plane();
	~Plane();
	void setArea(int);
	void setBreadth(int);
	void setLength(int);
	void setRegion(int);

	int getArea();
	int getBreadth();
	int getLength();

	void memsetPlane();
	void limitArea(int); 			//verifica se o número de nós é : 2N <= R <= N^2
	void limitRegion(int,int);		//limites de cada região do plano
	void setNodeRandomRegion(int);	//distribui os nós nas regiões de forma randomica

	int side; 			//area do plano -- refere-se a quanto irá medir um lado 
	int breadth; 		//comprimento de cada região do plano
	int length; 		//largura de cada região do plano
	int regionBreadth;	//comprimento de cada região do plano
	int regionLength;	//largura de cada região do plano
	int nRegions;		//número de regiões
	vector < vector<int> > plane;  //matriz do plano dinâmica
};