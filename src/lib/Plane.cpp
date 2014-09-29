#include <iostream>
#include <deque>
#include <iterator>
#include <algorithm> 
#include <cmath>
#include <random>
#include <stdexcept> // for std::runtime_error

#include "Plane.hpp"
#include "Graph.hpp"


using namespace std;

Plane::Plane() {}

Plane::~Plane() {}

/**
 * Atribui o valor do lado de um plano (lado X lado)
 * Atribui 0 a todas as posições da matriz do plano
 */
void Plane::setArea(int side){

	this->side = side;
	memsetPlane();
}

/**
 * Atribui o valor a largura do plano
 */
void Plane::setBreadth(int breadth){

	this->breadth = breadth;
}

/**
 * Atribui valor ao comprimento do plano
 */
void Plane::setLength(int length){

	this->length = length;
}

/**
 * Insere as coordenadas(x,y) correspondente ao número do nó
 */
void Plane::setNodeCoordinates(int node, int x, int y) {

	this->coordinates[node][0] = x;
	this->coordinates[node][1] = y;
}

/**
 * Obtêm o número de regiões no plano
 * Obtêm o número de linhas por região
 * Obém o número de colunas por região
 */
void Plane::setRegion(int nRegions) {

	this->regionRow = (int)floor(nRegions/this->length);
	this->regionColumn = (int)floor(nRegions/this->breadth);	
}

/**
 * Retorna o lado de uma area 
 * a area do plano é quadrada
 */
int Plane::getArea(){

	return this->side;
}

/**
 * Retorna o largura do plano
 */
int Plane::getBreadth(){

	return this->breadth;
}

/**
 * Retorna a comprimento do plano
 */
int Plane::getLength(){

	return this->length;
}

/**
 * Retorna o número de regiões que terá o plano
 */
int Plane::getNumberRegions() {

	return (this->breadth * this->length);
}

/**
 * Retorna eixo X do no passado como referência 
 */
int Plane::getCoordinateX(int node) {

	return this->coordinates[node][0];
}

/**
 * Retorna eixo Y do no passado como referência 
 */
int Plane::getCoordinateY(int node) {

	return this->coordinates[node][1];
}  

/**
 * Obtêm o eixo X inicial 
 * Passa como parâmetro o indice da região
 * Multiplica o indice pelo número de colunas da região (todas terão o mesmo número de colunas)
 * faz o módulo com a área do plano 
 */
int Plane::getRegionX(int index) {

	return (index*this->regionColumn) % this->side; 
}

/**
 * Obtêm o eixo Y inicial 
 * Multiplica o número de linhas de uma região (todas as linhas terão o mesmo número)
 * por o indice da região dividido pela largura da mesma
 */
int Plane::getRegionY(int index) {

	return this->regionRow*floor(index/this->length);	
}

/**
 * Retorna o número máximo de nós 
 * que cabem em uma região
 */
int Plane::getMaximumNodesRegion() {

	return (this->regionRow*this->regionColumn);
}

/**
 * Função para atribuir zero a todas as coordenadas do plano
 */
void Plane::memsetPlane() {

	int n = this->side;

	this->plane = vector<vector<int>> (n,vector<int>(n,-1));
}

/**
 * Função para atribuir zero a todas as coordenadas do plano
 */
void Plane::memsetCoordinates(int nodes) {

	this->coordinates = vector<vector<int>> (nodes,vector<int>(2,0));
}

/**
 * For N nodes, the number of regions in the area should be at least 2N, as seen from the real networks (Of
 * course, some networks may need more than 2N regions. N^2 is the upper limit. So number of regions, R
 * should be in between 2N and N2. i.e., 2N ≤ R ≤ N^2). So there are several options to divide the area into
 * different types of rectangular dimensions.
 */
void Plane::limitArea(int nNodes) {

	if (this->side > (nNodes*nNodes) || this->side < (2*nNodes)) {
		throw "2N ≤ R ≤ N²";
	}
}

void Plane::initialize(int nNodes) {

	/**
	 * Obtêm valores referentes a área de cada região do plano
	 */
	setRegion(getNumberRegions());

	/**
	 * Gerando coordenadas (X,Y) de forma randomica
	 * para distribuir os nós nas regiões
	 */
	setNodeRandomRegion(nNodes);

	print();
	

}
/**
 * Atribui coordenadas randomicas
 * para o nó passado como parâmetro
 */
void Plane::generateCoordinates(int node) {
	/**
	 * Gera coordenadas x e y randomicas para o nó i
	 */
	int x = random(0,this->side-1);
	int y = random(0,this->side-1);

	/**
	 * Verifica se não existe nenhum nó 
	 * nas coordenadas x e y
	 */
	if (this->plane[x][y] == -1)
	{
		this->plane[x][y] = node;
		setNodeCoordinates(node,x,y);
		return;
	}
	else
	{
		generateCoordinates(node);
	}
}


/**
 * Choose any N regions randomly, out of the total R regions, and some of the
 * regions may be chosen more than once (i.e., have more than one nodes).
 */
void Plane::setNodeRandomRegion(int nNodes) {

	memsetCoordinates(nNodes);
	/**
	 * Distribuição dos nós de forma randomica
	 */
	for (int i = 0; i < nNodes; i++)
	{
		generateCoordinates(i);
	}
}

/**
 * Geração de número de nós randomicos  
 */
int Plane::random(int minimum,int maximum) {

	default_random_engine generator;
	random_device rd;
	mt19937_64 gen(rd());

	uniform_int_distribution<> dis(minimum, maximum);
	
	return	dis(gen);
}

/**
 * Imprimir o plano
 */
void Plane::print() {

	for (int i = 0; i < this->side; i++)
	{
		for (int j = 0; j < this->side; j++)
		{
			cout<<this->plane[i][j]<<"\t";
		}
		cout<<"\n"<<endl;
	}
}