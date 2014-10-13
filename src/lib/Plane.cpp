#include <iostream>
#include <deque>
#include <iterator>
#include <algorithm> 
#include <cmath>
#include <random>
#include <stdexcept> // for std::runtime_error

#include "Plane.hpp"

using namespace std;

Plane::Plane() {

	setArea(0);
	setBreadth(0);
	setLength(0);
}

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

void Plane::setNodeCoordinates(Graph graph, int x, int y,int node) {

	this->plane[x][y] = node;

	this->coordinates[node][0] = x;
	this->coordinates[node][1] = y;
}

/**
 * Insere as coordenadas(x,y) correspondente ao número do nó
 */
void Plane::setNodesCoordinates(Graph graph) {

	int nNodes = graph.getNumberOfNodes();

	// cout<<"coordinates"<<endl;

	for (int i = 0; i < nNodes ; i++)
	{
		int x = this->xy[i][0];
		int y = this->xy[i][1];
		// cout<<"x= "<<x<<"y= "<<y<<endl;
		while(true) 
		{

			int node = random(0,nNodes-1);

			if (this->coordinates[node][0] == -1 && this->coordinates[node][1] == -1)
			{
				setNodeCoordinates(graph,x,y,node);
				break;
			}
		}
	}
}

void Plane::setWaxmanParameters(int alpha,int betha) {
	
	this->alpha = alpha;
	this->betha = betha;
}

/**
 * Calcula a distância euclidiana
 * entre um par de nós u e v
 * através das coordenas do plano
 */
int Plane::getEuclidean(int u, int v) {

	int baseU = this->coordinates[u][0]-this->coordinates[u][1];
	int baseV = this->coordinates[v][0]-this->coordinates[v][1];
	
	int distance = sqrt( pow(baseU,2) + pow(baseV,2));
	
	return distance;
}


void Plane::setEuclidean(Graph graph,int u,int v) {

	graph.setDistancePairofNodes(u,v,getEuclidean(u,v));
}


void Plane::blockedAreaAroundTheNode(Graph graph,int x,int y) {

	int distance = graph.getMinimumDistanceOfNode(); 

	for (int i = -distance; i <= distance; i++)
	{
		if (x+i >= 0 && x+i < getSqrtArea())
		{
			int cordX = x+i;

			for (int j = -distance; j <= distance; j++)
			{
				int cordY = y+j;

				if (y+j >= 0 && y+j < getSqrtArea() && this->plane[cordX][cordY] == -1)
				{
					this->plane[cordX][cordY] = -graph.getMinimumDistanceOfNode();
				}
			}
		}
	}		
}

/**
 * Obtêm o número de regiões no plano
 * Obtêm o número de linhas por região
 * Obêm o número de colunas por região
 */
void Plane::setRegion(int nRegions) {

	this->regionRow = (int)floor(nRegions/this->length);
	this->regionColumn = (int)floor(nRegions/this->breadth);	
}

/**
 * Retorna o lado de uma area 
 * a area do plano é quadrada
 */
int Plane::getSqrtArea(){

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

	this->coordinates = vector<vector<int>> (nodes,vector<int>(2,-1));
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

void Plane::initialize(Graph graph) {

	memsetCoordinates(graph.getNumberOfNodes());

	this->xy = vector<vector<int>> (graph.getNumberOfNodes(),vector<int>(2,0));

	/**
	 * Obtêm valores referentes a área de cada região do plano
	 */
	setRegion(getNumberRegions());

	
	/**
	 * Gerando coordenadas (X,Y) de forma randomica
	 * para distribuir os nós nas regiões
	*/
	setCoodinatesRandomRegion(graph);
	setNodesCoordinates(graph);

	print();

	/**
	 * Primeiro conecta nós em uma região
	 * Depois interconecta nós mais próximos entre regiões
	 */
	connectionNodesRegion(graph);
	regionsInterconnection(graph);
}

/**
 * Atribui coordenadas randomicas no plano
 */
void Plane::generateCoordinates(Graph graph,int position) {

	/**
	 * Gera coordenadas x e y randomicas para a  matriz xy
	 */

	int x = random(0,this->side-1);
	int y = random(0,this->side-1);

	/**
	 * Verifica se não existe nenhum nó 
	 * nas coordenadas x e y
	 * testa se a posição esta livre e 
	 * se o nó não esta na posição correspondente 
	 * a diagonal principal
	 */
	if (this->plane[x][y] == -1)
	{
		xy[position][0] = x;
		xy[position][1] = y;

		/**
		* Bloqueia zona conforme a distância minima 
		* Insere -2 na coordenada de bloqueio
		*/
		blockedAreaAroundTheNode(graph,x,y);

		return;
	}
	else
	{
		generateCoordinates(graph,position);
	}
}


/**
 * Choose any N regions randomly, out of the total R regions, and some of the
 * regions may be chosen more than once (i.e., have more than one nodes).
 */
void Plane::setCoodinatesRandomRegion(Graph graph) {

	int nNodes = graph.getNumberOfNodes();
	
	/**
	 * Gera coordenadas randomicas
	 */
	for (int i = 0; i < nNodes; i++)
	{
		generateCoordinates(graph,i); 
	}
}

/**
 * Geração de número de nós randomicos  
 */
int Plane::random(int minimum,int maximum) {

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

/**
 * Busca no plano por força bruta pelo nó mais próximo
 */
int Plane::nearestNode(int node,Graph graph) {

	int neighbor = node;
	int distance = 9999; //número infinito

	for (int i = 0; i < graph.getNumberOfNodes(); i++)
	{
		if (i != node)
		 {
			int X = abs(getCoordinateX(i)-getCoordinateX(node));
			int Y = abs(getCoordinateY(i)-getCoordinateY(node));

			int distanceNow = X+Y;

			/**
			 * Distância deve ser menor que a anterior
			 * Não haver ligações já entre o node e i e
			 * O grau deve ser inferior ao grau máximo
			 */
			if (distance > distanceNow && graph.getLink(node,i) == 0 && graph.getDegree(i) < graph.getMaximumDegree())
			{
				neighbor = i;
				distance = distanceNow;
			}

		} 
	}
	return neighbor;		
}

/**
 * Estabelece a conecção entre nós em sua respectiva região
 */
void Plane::connectionNodesRegion(Graph graph) {

	/**
	 * Percorre todas as regiões estabelecendo conecção
	 */
	for (int i = 0; i < getNumberRegions(); i++)
	{
		
	}

}

/**
 * Estabelcer a conecção dos nós entre as regiões
 * Busca pelo raio de modo que os nós interligados serão os mais próximos
 */
void Plane::regionsInterconnection(Graph graph) {

	for (int i = 0; i < graph.getNumberOfNodes(); i++)
	{
		int neighbor = nearestNode(i,graph);

		graph.setLink(i,neighbor); //faz a ligação dos nós no grafo de matriz adjacente

		cout<<" origem = "<<i<<" destino = "<<neighbor<<endl;
	}
}