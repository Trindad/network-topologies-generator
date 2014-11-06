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
	void setLength(int);
	void setRegion(int);
	void setBreadth(int);
	void setNodesCoordinates(Graph); 			//set de coordenadas randomicas X e Y do plano
	void setEuclidean(Graph,int,int);			//calcula a distância euclidiana entre um par de nós
	void setWaxmanParameters(int,int);			//atribui parâmetros de Waxman que variam de (0,1]
	void setCoodinatesRandomRegion(Graph);		//distribui os nós nas regiões de forma randomica
	void setNodeCoordinates(Graph,int,int,int);	// set nas coordenadas
	
	/**
	 * Getters
	 */
	int getLength();	
	int getBreadth();
	double getBetha();				//parâmetro para a probabilidade de Waxman
	double getAlpha();				//parâmetro para a probabilidade de Waxman
	int getSqrtArea();				//retorna a raíz do plano sendo o mesmo com lados iguais
	int getRegionX(int);			//inicio do eixo x de uma região do plano
	int getRegionY(int);			//inicio do eixo y de uma região do plano
	int getNumberRegions();			//número de regiões no plano
	int getCoordinateX(int); 		//coordenada X
	int getCoordinateY(int); 		//coordenada Y
	int getEuclidean(int,int);		//calcula distância euclidiana entre um par de nós
	int getMaximumNodesRegion();	//máximo de nós que cabem em uma região
	vector<int> getNumberOfNodesRegion(int,vector<int>);	//retorna o número de nós na região passada como parâmetro


	/**
	 * Funções auxiliares do plano
	 */
	void print(); 									//imprimir o plano
	int ring(Graph); 								//verifica se formou o anel em uma região 
	void memsetPlane();								//inicializa matriz do plano em -1 para todos as coordenadas
	void limitArea(int); 							//verifica se o número de nós é : 2N <= R <= N^2
	int random(int,int); 							//gera um número randomico através de uma função probalistica
	void initialize(Graph);							//inicializa as configurações 
	void limitRegion(int,int);						//limites de cada região do plano
	void memsetCoordinates(int);  					//inicializa vetor de coordenads em 0
	double randomDouble(int,int);					//gera um número randomico do tipo double
	int nearestNeighbor(int,Graph);					//busca um nó mais próximo pelo raio e retorna 
	void regionsInterconnection(Graph); 			//conecção dos nós entre as regiões
	void generateCoordinates(Graph,int);			//gera coordenadas de forma randomica para um nó randomico
	bool waxmanProbability(Graph,int,int);			//calcula a probabilidade de waxman para nós u e v 
	void blockedAreaAroundTheNode(Graph,int,int); 	// bloqueio da área conforme a distância passada pelo usuário
	void connectionNodesRegion(Graph,vector<int>,int);	//conecta nós por região utilizando a probabilidade de Waxman

private:
	int side; 								//area do plano -- refere-se a quanto irá a raiz quadrada do planos
	int breadth; 							//comprimento de cada região do plano
	int length; 							//largura de cada região do plano
	int regionRow;							//comprimento de cada região do plano
	int regionColumn;						//largura de cada região do plano
	int nRegions;							//número de regiões
	double betha;							//parâmetro de Waxman
	double alpha;							//parâmetro de Waxman
	vector < vector<int> > xy; 				//armazena as coordenas randomicas
	vector <int> nNodesRegions; 			// armazena a quantidade de nós em uma região
	vector < vector<int> > plane;  			//matriz do plano dinâmica
	vector < vector<int> > coordinates;  	//matriz de coordenadas de cada nó da rede
};