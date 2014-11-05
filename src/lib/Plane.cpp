#include <iostream>
#include <deque>
#include <iterator>
#include <algorithm> 
#include <cmath>
#include <random>
#include <stdexcept> // for std::runtime_error

#include "Plane.hpp"

using namespace std;

#define MIN 2

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

/**
 * Atribui coordenadas correspondentes ao nó
 */
void Plane::setNodeCoordinates(Graph graph, int x, int y,int node) {

	this->plane[x][y] = node;

	this->coordinates[node][0] = x;
	this->coordinates[node][1] = y;
}

/**
 * Insere as coordenadas(x,y) correspondente ao número do nó
 * De modo que o nó seja gerado randomicamente
 * Verifica se o nó já não está inserido no plano e se 
 */
void Plane::setNodesCoordinates(Graph graph) {

	int nNodes = graph.getNumberOfNodes();

	for (int i = 0; i < nNodes ; i++)
	{
		int x = this->xy[i][0];
		int y = this->xy[i][1];

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

/**
 * Atribui as posições dos nós existentes na região ao vetor de posições (nPOsitions)
 */
vector<int> Plane::getNumberOfNodesRegion(int numberRegion, vector<int> nodes) {
	
	int auxRow = floor(numberRegion/ this->regionColumn);	//armazena a linha do plano 
	
	int x = 0,y = 0;

	if (auxRow == 0)
	{
		x = getRegionX(numberRegion);
		y = getRegionY(numberRegion);
	}
	else
	{
		x = getRegionX(numberRegion);
		y = (auxRow*this->regionRow)*getRegionY(numberRegion);
	}

	int colunas = this->regionColumn+y;
	int linhas = this->regionRow+x;

	for (int i = y; i < colunas; i++)
	{
		for (int j = x; j < linhas; j++)
		{
			if (this->plane[i][j] >= 0)
			{
				int node = this->plane[i][j];
				nodes.push_back(node);
			}
		}
	}

	return nodes;
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

	return (this->nRegions = this->breadth * this->length);
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
 * Bloqueia pelo raio de modo que não se consiga inserir nenhum nó 
 * conforme a restrição da distância
 */
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
					this->plane[cordX][cordY] = -2;
				}
			}
		}
	}		
}

/**
 * Obtêm o eixo X inicial 
 * Passa como parâmetro o indice da região
 * Multiplica o indice pelo número de colunas da região (todas terão o mesmo número de colunas)
 * faz o módulo com a área do plano 
 */
int Plane::getRegionX(int index) {

	return (index*this->regionRow) % this->side; 
}

/**
 * Obtêm o eixo Y inicial 
 * Multiplica o número de linhas de uma região (todas as linhas terão o mesmo número)
 * por o indice da região dividido pela largura da mesma
 */
int Plane::getRegionY(int index) {

	return this->regionRow*floor(index/this->length);	
}

double Plane::getBetha(){

	return this->betha;
}

double Plane::getAlpha(){

	return this->alpha;
}

/**
 * Retorna o número máximo de nós 
 * que cabem em uma região
 */
int Plane::getMaximumNodesRegion() {

	return (this->regionRow*this->regionColumn);
}

bool Plane::waxmanProbability(Graph graph,int u,int v) {

	double distance = graph.getMinimumDistanceOfNode();
	double exponent = exp( getEuclidean(u,v) / (getAlpha()*distance) );

	double probability = getBetha()*exponent;//calculo da probalidade 

	double temp = randomDouble(0,1)*0.75f;

	if (probability > temp)
	{
		graph.getLink(u,v);
		return true;
	}
	else
	{
		return false;
	}
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
	mt19937_64 gen(rd());//utilizando merssene twister 64 bits

	uniform_int_distribution<> dis(minimum, maximum);
	
	return	dis(gen);
}

/**
 * Geração de número de nós randomicos  
 */
double Plane::randomDouble(int minimum,int maximum) {

	double f = (double)rand() / RAND_MAX;

    return minimum + f * (maximum - minimum);
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
 * Verifica se já foi formado um anel dentro de uma região
 */
bool Plane::ring(Graph graph) {


	return true;
}
/**
 * Estabelece a conecção entre nós em sua respectiva região
 */
void Plane::connectionNodesRegion(Graph graph,vector<int> nodes,int indexRegion) {

	/**
	 * verifica se existe mais de um nó em uma região
	 */
	if (nodes.size() <= 1)
	{
		return;
	}

	random_shuffle(nodes.begin(),nodes.end());//sorteio

	vector<int>::iterator it = nodes.begin();

	/**
	 * Região possui somente dois nós
	 */
	if (nodes.size() == 2)
	{
		graph.setLink(nodes[0],nodes[1]);//liga os dois nós no grafo
		return;
	}

	Graph graphRegion;

	graphRegion.memsetGraph();

	/**
	 * Interliga nós até formar um anel
	 */
	int source = *it;

	/**
	 * Continua até se formar um anel
	 */
	while(true)
	{	
		int target = source;

		do
		{
			target = *it;//seleciona nó de destino enquanto a probabilidade de waxman não for satisfeita

			if (source != target || graph.getLink(source,target) == 1)
			{
				continue;
			}
		}
		while( waxmanProbability(graph,source,target) == false );

		if (graph.getDegree(source) == MIN)		
		{
			*it == -1;
		}

		/**
		 * verifica se anel já esta formado
		 */
		if ( ring(graph) == true )
		{
			break;
		}
		source = target;//a origem recebe o destino de modo que forme o anel
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

/**
 * Faz a inicialização do plano 
 */
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
	 * Obtêm o número de nós em um subplano 'i'
	 * Interconecta todos nós em uma região i do plano
	 * Com suas respectivas distâncias euclidianas
	 * Utilizando Waxman
	 * Depois interconecta nós mais próximos entre regiões
	 * Não utiliza Waxman
	 * Verifica se o limite de links foi atingido 
	 * E se todos os vértices tem grau 2 no mínimo
	 */
	for (int i = 0; i < this->nRegions; i++)
	{
		// cout<< "Region "<<i<<endl;
		
		/**
		 * retorna as coordenas dos nós pertencentes a região
		 */
		vector<int> nodes;

		nodes = getNumberOfNodesRegion(i,nodes);//retorna os nós de uma região
		connectionNodesRegion(graph,nodes,i);	
	}
	regionsInterconnection(graph);
}
