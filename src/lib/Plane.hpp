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

#include "Graph.hpp"

using namespace std;

class Plane
{
public:

	Plane();
	~Plane();

	/**
	 * Setters
	 */
	void setArea(int);
	void setBreadth(int);
	void setLength(int);
	void setRegion(int);
	void setNodeRandomRegion(Graph);	//distribui os nós nas regiões de forma randomica
	void setNodeCoordinates(Graph,int,int,int); //set de coordenadas randomicas X e Y do plano
	
	/**
	 * Getters
	 */
	int getArea();
	int getBreadth();
	int getLength();
	int getNumberRegions();
	int getRegionX(int);
	int getRegionY(int);
	int getMaximumNodesRegion();
	int getCoordinateX(int); //coordenada X
	int getCoordinateY(int); //coordenada Y

	/**
	 * Funções do plano
	 */
	void memsetPlane();
	void memsetCoordinates(int);  		//inicializa vetor de coordenads em 0
	void initialize(Graph);				//inicializa as configurações 
	void limitArea(int); 				//verifica se o número de nós é : 2N <= R <= N^2
	void limitRegion(int,int);			//limites de cada região do plano
	void generateCoordinates(Graph,int);		//gera coordenadas de forma randomica para um nó
	void blockedAreaAroundTheNode(Graph,int,int); // bloqueio da área conforme a distância passada pelo usuário
	void nearestNode();					//busca nó mais próximo pelo raio
	void regionInterconnection(); 		//conecção dos nós entre as regiões
	int random(int,int); 				//gera um número randomico através de uma função probalistica
	void print(); 						//imprimir o plano


private:
	int side; 			//area do plano -- refere-se a quanto irá a raiz quadrada do planos
	int breadth; 		//comprimento de cada região do plano
	int length; 		//largura de cada região do plano
	int regionRow;		//comprimento de cada região do plano
	int regionColumn;	//largura de cada região do plano
	int nRegions;		//número de regiões
	vector < vector<int> > plane;  //matriz do plano dinâmica
	vector < vector<int> > coordinates;  //matriz de coordenadas de cada nó da rede
};