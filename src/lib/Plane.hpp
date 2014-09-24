/**
 * Definições de função-membro que aparecem em Regions.cpp
 */

#include <iostream>
#include <deque>
#include <iterator>
#include <algorithm> 
#include <stdexcept> // for std::runtime_error
#include <vector>
#include <random>

using namespace std;

class Plane
{
public:

	Plane();
	~Plane();

	/**
	 * Set
	 */
	void setArea(int);
	void setBreadth(int);
	void setLength(int);
	void setRegion(int);
	void setNodeRandomRegion(int);	//distribui os nós nas regiões de forma randomica
	void setNodeCoordinates(int,int,int);
	
	/**
	 * Get
	 */
	int getArea();
	int getBreadth();
	int getLength();
	int getRegionX(int);
	int getRegionY(int);
	int getMaximumNodesRegion();
	int getCoordinateX();
	int getCoordinateY();

	void memsetPlane();
	void memsetPlane(int); 
	void limitArea(int); 			//verifica se o número de nós é : 2N <= R <= N^2
	void limitRegion(int,int);		//limites de cada região do plano
	void coordinates(int);	//gera coordenadas de forma randomica para um nó
	int random(int,int); //gera um número randomico através de uma função probalistica



	int side; 			//area do plano -- refere-se a quanto irá medir um lado 
	int breadth; 		//comprimento de cada região do plano
	int length; 		//largura de cada região do plano
	int regionRow;		//comprimento de cada região do plano
	int regionColumn;	//largura de cada região do plano
	int nRegions;		//número de regiões
	vector < vector<int> > plane;  //matriz do plano dinâmica
	vector < vector<int> > coordinates;  //matriz de coordenadas de cada nó da rede
};