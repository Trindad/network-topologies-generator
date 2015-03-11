/**
 * Definições de função-membro que aparecem em Regions.cpp
 */

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
	void setRows(int);
	void setLength(int);
	void setRegion(int);
	void setBreadth(int);
	void setColumns(int);
	void setRegionsMeasures();
	void setNumberRegions(int);
	void setNodesCoordinates(Graph); 			//set de coordenadas randomicas X e Y do plano
	void setEuclidean(Graph,int,int);			//calcula a distância euclidiana entre um par de nós
	void setCoodinatesRandomRegion(Graph);		//distribui os nós nas regiões de forma randomica
	void setWaxmanParameters(double,double);	//atribui parâmetros de Waxman que variam de (0,1]
	void setNodeCoordinates(Graph,int,int,int);	// set nas coordenadas
	
	/**
	 * Getters
	 */
	int getLength();	
	int getBreadth();
	double getBetha();										//parâmetro para a probabilidade de Waxman
	double getAlpha();										//parâmetro para a probabilidade de Waxman
	int getSqrtArea();										//retorna a raíz do plano sendo o mesmo com lados iguais
	int getRegionX(int);									//inicio do eixo x de uma região do plano
	int getRegionY(int);									//inicio do eixo y de uma região do plano
	int getNumberRegions();									//número de regiões no plano
	int getCoordinateX(int); 								//coordenada X
	int getCoordinateY(int); 								//coordenada Y
	int getEuclidean(int,int);								//calcula distância euclidiana entre um par de nós
	int getMaximumNodesRegion();							//máximo de nós que cabem em uma região
	void getNumberOfNodesRegion(int,vector<int>&);	//retorna o número de nós na região passada como parâmetro


	/**
	 * Funções auxiliares do plano
	 */
	void print(); 																//imprimir o plano
	int ring(Graph); 															//verifica se formou o anel em uma região 
	void memsetPlane();															//inicializa matriz do plano em -1 para todos as coordenadas
	void limitArea(int); 														//verifica se o número de nós é : 2N <= R <= N^2
	int random(int,int); 														//gera um número randomico através de uma função probalistica
	void randomLink(Graph &);													//sorteio randomizado de um par de nodos qualquer
	void initialize(Graph &);													//inicializa as configurações 
	void limitRegion(int,int);													//limites de cada região do plano
	void memsetCoordinates(int);  												//inicializa vetor de coordenads em 0
	double randomDouble(int,int);												//gera um número randomico do tipo double
	int nearestNeighbor(int,Graph);												//busca um nó mais próximo pelo raio e retorna 
	bool regionEqual(vector<int>,int);											//verifica se o nodo pertence a uma região
	void generateCoordinates(Graph,int);										//gera coordenadas de forma randomica para um nó randomico
	bool waxmanProbability(Graph,int,int);										//calcula a probabilidade de waxman para nós u e v 
	void blockedAreaAroundTheNode(Graph,int,int); 								// bloqueio da área conforme a distância passada pelo usuário
	int targetSearch(int,Graph, vector<vector<int>>,int);						//busca nodo destino
	void regionsInterconnection(Graph &,vector<vector<int>>); 				    //conecção dos nós entre as regiões
	vector<vector<int>> connectionNodesRegion(Graph &,vector<vector<int>>&); 	//conecta nós por região utilizando a probabilidade de Waxman

private:
	
	int side; 								//area do plano -- refere-se a quanto irá a raiz quadrada do planos
	int breadth; 							//largura do plano
	int length; 							//comprimento do plano
	int regionRow;							//comprimento de cada região do plano
	int regionColumn;						//largura de cada região do plano
	int nRegions;							//número de regiões
	double betha;							//parâmetro de Waxman
	double alpha;							//parâmetro de Waxman
	vector < vector<int> > xy; 				//armazena as coordenas randomicas
	vector < vector<int> > plane;  			//matriz do plano dinâmica
	vector < vector<int> > coordinates;  	//matriz de coordenadas de cada nodo da rede
};