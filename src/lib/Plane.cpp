#include "Plane.hpp"

using namespace std;

#define MIN 2

Plane::Plane() {

	setNumberRegions(0);
	setArea(0);
	setBreadth(0);
	setLength(0);
}

Plane::~Plane() {}

/**
 * Atribui o valor do lado de um plano (lado X lado)
 * Atribui 0 a todas as posições da matriz do plano
 */
void Plane::setArea(int side)
{

	this->side = side;
	memsetPlane();
}

/**
 * Atribui o valor a largura do plano
 */
void Plane::setBreadth(int breadth)
{

	this->breadth = breadth;
}

/**
 * Atribui valor ao comprimento do plano
 */
void Plane::setLength(int length)
{

	this->length = length;
}

void Plane::setNumberRegions(int n) 
{

	this->nRegions = n;
}

/**
 * Atribui coordenadas correspondentes ao nó
 */
void Plane::setNodeCoordinates(Graph graph, int x, int y,int node)
{

	this->plane[x][y] = node;

	this->coordinates[node][0] = x;
	this->coordinates[node][1] = y;
}

/**
 * Insere as coordenadas(x,y) correspondente ao número do nó
 * De modo que o nó seja gerado randomicamente
 * Verifica se o nó já não está inserido no plano e se 
 */
void Plane::setNodesCoordinates(Graph graph) 
{

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

void Plane::setWaxmanParameters(double alpha,double betha) 
{

	this->alpha = alpha;
	this->betha = betha;
}

/**
 * Calcula a distância euclidiana
 * entre um par de nós u e v
 * através das coordenas do plano
 */
int Plane::getEuclidean(int u, int v) 
{

	int baseU = abs(this->coordinates[u][0]-this->coordinates[u][1]);
	int baseV = abs(this->coordinates[v][0]-this->coordinates[v][1]);
	
	int distance = sqrt( pow(baseU,2) + pow(baseV,2) );
	
	return distance;
}

void Plane::setEuclidean(Graph graph,int u,int v) 
{

	graph.setDistancePairOfNodes(u,v,getEuclidean(u,v));
}

/**
 * Atribui as posições dos nós existentes na região ao vetor de posições (nPOsitions)
 */
void Plane::getNumberOfNodesRegion(int numberRegion, vector<int> &nodes) 
{
	
	int column = 0, row = 0;
	int columns = 0,rows = 0;

	
	if (this->nRegions < this->side)
	{
		column = floor( numberRegion / getBreadth() ) * this->regionColumn;	//armazena a linha do plano 
		cout<<"Coluna init "<<column<<endl;
		row =  floor( numberRegion / this->regionRow ) * this->regionRow;	//armazena a coluna do plano 
		cout<<"Linhas init "<<row<<endl;
		columns = column + this->regionColumn;			//limite de colunas da região
		rows = row + this->regionRow;
	}
	else
	{

		column = (numberRegion % this->regionRow) * this->regionColumn;	//armazena a linha do plano 
		row =  floor( numberRegion / this->regionRow )*this->regionRow;	//armazena a coluna do plano 

		cout<<"Região "<<numberRegion<<" column "<<column<<" row "<<row<<endl;
		
		// int row = getRegionX(numberRegion/planeColumn);	
		// int column = getRegionY( floor(numberRegion/planeRow) );		
		
		columns = column + this->regionColumn;			//limite de colunas da região
		rows = row + this->regionRow; 					//limite de linhas da região

		cout<<"row "<<row<<"rows "<<rows<<"regionRow "<<this->regionRow <<endl;

	}
	
	cout<<"Coluna init "<<column<<" até "<<columns<<endl;
	cout<<"Linhas init "<<row<<" até "<<rows<<endl;
	cout<<"\n\n";

	for (int i = column; i < columns; i++)
	{
		for (int j = row; j < rows; j++)
		{
			if (this->plane[i][j] >= 0)
			{
				int node = this->plane[i][j];

				nodes.push_back(node);
			}
		}
	}
}

/**
 * Atribui o número de colunas de uma região
 * Em seguida obtêm o valor do comprimento
 */
void Plane::setColumns(int columns) 
{

	this->regionColumn = columns;
	this->length = this->side/columns;//obtêm o comprimento do plano
	cout<<"length "<<this->length<<endl;
}

/**
 * Atribui o número de linhas de uma região
 * Em seguida obtêm o valor da largura
 */
void Plane::setRows(int rows) 
{

	cout<<"setRows"<<endl;
	this->regionRow = rows;

	this->breadth = this->side/rows;//obtêm a largura do plano
	cout<<"breadth "<<this->breadth<<endl;
}

/**
 * Obtêm o número de linhas por região
 * Obêm o número de colunas por região
 */
void Plane::setRegion(int nRegions) 
{

	this->regionRow = (int)floor(nRegions/this->length);
	this->regionColumn = (int)floor(nRegions/this->breadth);	
}

/**
 * Calcula largura e comprimento 
 * de cada região do plano
 */
void Plane::setRegionsMeasures() 
{

	int X = this->side;
	vector<int> primes = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71}; // 20 números
	
	bool prime = false; 	// verifica se é primo
	unsigned int temp = 0;

	vector<int> factorial; // lista que irá guardar os numeros primos divisiveis pelos números de regiões
	
	bool nextPair = true;
	int R = this->nRegions;
	int number = 3;
	int auxF = 0;
	int A = 1;

	//busca no vetor de primos para verificar se o número de regiões é primo
	while(prime == false && temp < primes.size()) {
        
        if(R == primes[temp])
        {
            prime = true;
        }
        else
        {
        	temp = temp + 1;
        }
	}

	/**
	 * se o R for um número primo
	 * se não o numero de regiões não for primo é necessário factorizá-lo
	 */
	if(prime == true)
	{
		setRows( X );     				//a largura de cada região é a largura do plano
		setColumns( (int)floor( X/R ) ); 		//a altura é o menor inteiro da divisão entre o tamanho do plano e o número de regiões
	}
	else
	{ 
		if(R == 1)
		{
			factorial.push_back(1);
		}
	    else
	    {
	    	//decomposição de todos os números pares
	    	while(nextPair == true) { 

	    		if( R % 2 == 0)
	    		{
	    			R = (int)( R/2 ); // se auxR for um numero par, só receberá o numero dois no fact
					factorial.push_back(2); //inserção no vector fact
	    		}
	    	    else
	    	    {
	    	    	nextPair = false;
	    	    }
	    	}

	    	//factorização dos números impares
	    	while(R > 1) {  

    			if(R % number == 0)
    			{
    				if(R != auxF)
    				{
						factorial.push_back(number); //inserção do primo na lista
						auxF = number;
					}

					R = (int) ( R/number );
    			}
    		    else
    		    {
    		    	number = number + 2; //avançar para o primo seguinte
    		    } 
	    	} 
		}

		int n = (int) ceil(factorial.size()/2);

	    for(int i = 0; i < n; i++){

			if(factorial[i]!=0)
			{
				A = A * factorial[i];  //para decompor em dois números de igual tamanho multiplicaremos metade da lista fact
			}
	   	}

		int K = (int)(nRegions/A);

		setRows( (int)floor( X/A ) ); 		//largura de cada regiao
		setColumns( (int)floor( X/K ) ); 	//altura de cada regiao
	}

	cout<<"column "<<this->regionColumn<<" row "<<this->regionRow<<endl;
}

/**
 * Retorna o lado de uma area 
 * a area do plano é quadrada
 */
int Plane::getSqrtArea()
{

	return this->side;
}

/**
 * Retorna o largura do plano
 */
int Plane::getBreadth()
{

	return this->breadth;
}

/**
 * Retorna a comprimento do plano
 */
int Plane::getLength()
{

	return this->length;
}

/**
 * Retorna o número de regiões que terá o plano
 */
int Plane::getNumberRegions() 
{

	return (this->nRegions = this->breadth * this->length);
}

/**
 * Retorna eixo X do no passado como referência 
 */
int Plane::getCoordinateX(int node) 
{

	return this->coordinates[node][0];
}

/**
 * Retorna eixo Y do no passado como referência 
 */
int Plane::getCoordinateY(int node) 
{

	return this->coordinates[node][1];
}  

/**
 * Bloqueia pelo raio de modo que não se consiga inserir nenhum nó 
 * conforme a restrição da distância
 */
void Plane::blockedAreaAroundTheNode(Graph graph,int x,int y) 
{

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
int Plane::getRegionX(int index) 
{

	return ( index * this->breadth );
}

/**
 * Obtêm o eixo Y inicial 
 * Multiplica o número de linhas de uma região (todas as linhas terão o mesmo número)
 * por o indice da região dividido pela largura da mesma
 */
int Plane::getRegionY(int index) 
{

	return ( index * this->length ); 	
}

double Plane::getBetha()
{

	return this->betha;
}

double Plane::getAlpha()
{

	return this->alpha;
}

/**
 * Retorna o número máximo de nós 
 * que cabem em uma região
 */
int Plane::getMaximumNodesRegion() 
{

	return (this->regionRow*this->regionColumn);
}

bool Plane::waxmanProbability(Graph graph,int u,int v) 
{

	if (u == v)
	{
		return false;
	}

	int distance = graph.getMinimumDistanceOfNode();
	
	double exponent = exp( (double)getEuclidean(u,v) / ( getAlpha()* (double)distance ) );

	double probability = getBetha()*exponent;//calculo da probalidade 

	double temp = randomDouble(0,1)*0.75f;

	// cout<<"temp "<<temp<<"\t probability "<<probability<<endl;
	// cout<<"ok ? "<<graph.getEdge(u,v)<<endl;
	if (probability > temp && !graph.getEdge(u,v) == true)
	{	
		return true;
	}
	
	// cout<<"Problema no waxman"<<endl;
	return false;
	
}

/**
 * Função para atribuir zero a todas as coordenadas do plano
 */
void Plane::memsetPlane() 
{

	int n = this->side;

	this->plane = vector<vector<int>> (n,vector<int>(n,-1));
}

/**
 * Função para atribuir zero a todas as coordenadas do plano
 */
void Plane::memsetCoordinates(int nodes) 
{

	this->coordinates = vector<vector<int>> (nodes,vector<int>(2,-1));
}

/**
 * For N nodes, the number of regions in the area should be at least 2N, as seen from the real networks (Of
 * course, some networks may need more than 2N regions. N^2 is the upper limit. So number of regions, R
 * should be in between 2N and N2. i.e., 2N ≤ R ≤ N^2). So there are several options to divide the area into
 * different types of rectangular dimensions.
 */
void Plane::limitArea(int nNodes) 
{

	if (this->side > (nNodes*nNodes) || this->side < (2*nNodes)) 
	{
		throw "2N ≤ R ≤ N²";
	}
}

/**
 * Atribui coordenadas randomicas no plano
 */
void Plane::generateCoordinates(Graph graph,int position) 
{

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
void Plane::setCoodinatesRandomRegion(Graph graph) 
{

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
int Plane::random(int minimum,int maximum) 
{

	random_device rd;
	mt19937_64 gen(rd());//utilizando merssene twister 64 bits

	uniform_int_distribution<> dis(minimum, maximum);
	
	return	dis(gen);
}

/**
 * Geração de número de nós randomicos  
 */
double Plane::randomDouble(int minimum,int maximum) 
{

	double number = (double)( rand() / RAND_MAX );

    return minimum + number * ( maximum - minimum );
}

/**
 * Imprimir o plano
 */
void Plane::print() 
{

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
 * Verifica se o nó pertence a uma região
 */
bool Plane::regionEqual(vector<int> nodes,int node) 
{
	for (unsigned int i = 0; i < nodes.size(); i++)
	{
		if (nodes[i] == node)
		{
			return true;
		}
	}

	return false;
}

/**
 * Busca nodo destino mais próximo
 * Busca utilizando o raio
 */
int Plane::targetSearch(int source,Graph graph, vector<vector<int>> nodes,int indexRegion )
{

	int minimum = 1;
	int maximum = graph.getNumberOfNodes();

	/*
	 * Obtem o valor das coordenadas dos nodos
	 */
	int xSource = this->coordinates[source][0];
	int ySource = this->coordinates[source][1];	
	
	int target = source;
	int count = minimum;

	vector<int> targets = vector<int> (graph.getNumberOfNodes(),0);

	targets[source] = 1;

	while(count < maximum) 
	{
		cout<<"Maximum "<<maximum<<" count "<<count<<endl;
		int targetNow = random(0,maximum-1);

		int radiusNow = 0, radiusEarlier = 1; 
		
		// cout<<"tm coordinates x "<< this->coordinates[0].size()<<" tm coordinates y "<< this->coordinates[1].size()<<endl;
		// for (int p = 0; p < graph.getNumberOfNodes(); p++)
		// {
		// 	cout<<" x "<<this->coordinates[p][0]<<" y "<<this->coordinates[p][1]<<endl;
		// }

		int xTarget = this->coordinates[targetNow][0];
		int yTarget = this->coordinates[targetNow][1];
		
		for(int i = 1; i <= this->side; i++) 
		{
			for(int j =  xSource-i; j <= xSource+i; j++) 
			{
				for(int k = ySource-i; k <= ySource+i; k++) 
				{	
					/*
					 * Testa se as coordenadas encontradas são iguais ao nó candidato a target 
					*/
					if(xTarget == j && k == yTarget && targetNow != source)
					{
						if(radiusNow < radiusEarlier && regionEqual(nodes[indexRegion],targetNow) == false && graph.getEdge(source,targetNow) == false)
						{
							cout<<" target "<<targetNow<<" source "<<source<<"\n\n\n"<<endl;
							target = targetNow;
							radiusEarlier = radiusNow;
							
							break;
						}

						radiusNow++;
					}
					
				}
			}
		}

		if ( targets[targetNow] == 0)
		{
			targets[targetNow] = 1;
			count++;
		}
	}

	cout<<"source "<<source<<" target "<<target<<endl;
	return target;
}

/**
 * Busca no plano por força bruta pelo nó mais próximo
 */
int Plane::nearestNeighbor(int node,Graph graph) 
{

	int neighbor = node;
	int distance = std::numeric_limits<int>::min(); //número infinito

	for (int i = 0; i < graph.getNumberOfNodes(); i++)
	{
		if (i != node)
		{
			int X = abs( getCoordinateX(i) - getCoordinateX(node) );
			int Y = abs( getCoordinateY(i) - getCoordinateY(node) );

			int distanceNow = X+Y;

			/**
			 * Distância deve ser menor que a anterior
			 * Não haver ligações já entre node e i, e
			 * O grau deve ser inferior ao grau máximo
			 * O nodo i deve ser de uma outra região
			 */
			if (distance > distanceNow && graph.getEdge(node,i) == 0 && graph.getDegree(i) < graph.getMaximumDegree())
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
 * Retorna o número de nós com grau dois
 * Caso todos os nós tenham grau 2 então existe ciclo
 */
int Plane::ring(Graph graph) 
{

	int count = 0;

	/**
	 * Para haver um anel todos os vértices precisam ter grau 2
	 */
	for (int i = 0; i < graph.getNumberOfNodes(); i++)
	{
		if (graph.getDegree(i) == 2)
		{
			count++;
		}
	}

	return count;
}

/**
 * Estabelece a conecção entre nós em sua respectiva região
 */
vector<vector<int>> Plane::connectionNodesRegion(Graph &graph,vector<vector<int>> &nodes) 
{

	/**
	 * Controladores para fechamento do anel
	 * O nodo somente poderá ser uma vez destino e origem
	 */
	vector<int> sources = vector<int> (graph.getNumberOfNodes(),0);
	vector<int> targets = vector<int> (graph.getNumberOfNodes(),0);

	for (int i = 0; i < this->nRegions; i++)
	{

		// cout<<"connection Nodes Region "<<i<<endl;

		vector<int> temp;

		getNumberOfNodesRegion(i,temp);

		nodes.push_back( temp );//retorna os nós de uma região

		// for (unsigned int p = 0; p < nodes[i].size(); p++)
		// {
		// 	cout<<"v = "<<nodes[i][p]<<endl;
		// }


		int controller = 0;
		int n = nodes[i].size();

		// cout<<"N Nodes "<<n<<endl;
		/**
		 * Região possui somente dois nós
		 */
		if (n == 2)
		{
			graph.setEdge(nodes[i][0],nodes[i][1]);//liga os dois nós no grafo

			continue;
		}

		/**
		 * Região deverá gerar um anel
		 */
		if (n >= 3)
		{
			random_shuffle(nodes[i].begin(),nodes[i].end());//sorteio

			/**
			 * Interliga nodos até formar um anel
			 * end recebe o nó inicial que só
			 * será destino na ultima ligação
			 */

			vector<int>::iterator it = nodes[i].begin();

			int source = *it;
			int target;
			
			int end = source;

			while(controller < n)
			{
				 cout<<"Controladores"<<controller<<endl;

				/**
				 * Verifica se o nodo já foi origem
				 */
				if (sources[source] == 1)
				{
					for (vector<int>::iterator j = nodes[i].begin(); j != nodes[i].end(); j++)
					{
						source = *j;

						if (sources[source] == 0)
						{
							break;
						}
					}

				}	
					
				target = source;
				
				for (vector<int>::iterator k = nodes[i].begin(); k != nodes[i].end(); k++)
				{
					target = *k;

					// cout<<"target "<<target<<endl;
					if (target == source)
					{
						// cout<<"src "<< source <<"\t trt"<<target <<endl;
						continue;
					}
					else if(targets[target] == 0 && target != end && controller < n && waxmanProbability(graph,source,target) == true)
					{
						cout<<"ligação entre "<<source<<" e "<<target<<endl;
						graph.setEdge(source,target);//liga os dois nós no grafo

						targets[target] = 1;
						sources[source] = 1;

						controller++;

						break;
					}
					else if( targets[target] == 0  && controller == n-1 && waxmanProbability(graph,source,target) == true) 
					{
						cout<<"ligação entre "<<source<<" e "<<target<<endl;
						graph.setEdge(source,target);//liga os dois nós no grafo
						
						targets[target] = 1;
						sources[source] = 1;

						controller++;

						break;
					}
				}

 				source = target;
			}


			/**
			 * Verifica se formou um anel na região
			 */
			if ( controller == n )
			{
				break;
			}
			else
			{
				i--;
			}
		}
			
	}

	return nodes;
}


/**
 * Estabelecer a conecção dos nós entre as regiões
 * Busca pelo raio de modo que os nós interligados serão os mais próximos
 */
void Plane::regionsInterconnection(Graph &graph,vector<vector<int>> nodes) 
{

	int controller = 0;

	for (int i = 0; i < this->nRegions; i++)
	{
		int neighbor,j = 0;
		unsigned int count = 0;

		/**
		 * Se existir somente um nó na região
		 * então haverá ligação entre dois nós 
		 * mais próximos.
		 */
		if ( nodes[i].size() == 1)
		{
			
			neighbor = targetSearch(nodes[i][0],graph,nodes,i);

			graph.setEdge(nodes[i][0],neighbor); //faz a ligação dos nós no grafo de matriz adjacente
			
			controller++;

			if (controller < 2)
			{
				i--;//retorna a região e faz a segunda ligação
			}
			else
			{
				controller = 0;
			}

		}
		else
		{
			while( count < nodes[i].size() )
			{
				
				neighbor = targetSearch(nodes[i][j],graph,nodes,i);

				graph.setEdge(nodes[i][j],neighbor); //faz a ligação dos nós no grafo de matriz adjacente
				
				count++;

				j++;
			}
		}
	}
}

/**
 * Faz a inicialização do plano 
 */
void Plane::initialize(Graph &graph) 
{

	memsetCoordinates( graph.getNumberOfNodes() );

	this->xy = vector<vector<int>> (graph.getNumberOfNodes(),vector<int>(2,0));

	/**
	 * Verifica com procedera a distribuição dos nodos
	 * de acordo com a configuração referente ao número
	 * de regiões do plano
	 */
	

	if(!this->nRegions)
	{
		setRegion( getNumberRegions() );
	}

	/**
	 * Gerando coordenadas (X,Y) de forma randomica
	 * para distribuir os nós nas regiões
	*/
	setCoodinatesRandomRegion(graph);
	setNodesCoordinates(graph);

	print();

	vector<vector<int>> nodesFromRegion;
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
	nodesFromRegion = connectionNodesRegion(graph,nodesFromRegion);

	/**
	 * Interconecta regiões do plano
	 * Seleciona pares de nós de regiões distintas
	 * Os nós selecionados não devem ter o grau máximo
	 * As ligações novas devem acontecer sempre entre os 
	 * nós mais próximos, ou seja entre regiões vizinhas
	 * Obs: descrição na pg. 124 (Tese Pavan)
	 */
	if (this->nRegions >= 2)
	{
		regionsInterconnection(graph,nodesFromRegion);
	}

	cout<<graph.getNumberOfEdges();
}


/**
 * faz uma ligação randômica entre um par de nodos
 * Ambos os nodos não devem ter grau máximo e 
 * Não deve haver ligação entre estes
 * O nodo destino deve ser diferente da sua origem
 */
void Plane::randomLink(Graph &graph) 
{
	cout<<"ligações randomicas"<<endl;
	vector<int> nodes;
	int maximum = graph.getMaximumDegree();

	/**
	 * Insere os nodos que possuem grau inferior ao limite
	 */
	for (int i = 0; i < graph.getNumberOfNodes(); i++)
	{
		// cout<<"v "<<i<<" degree "<<graph.getDegree(i)<<endl;	
		if (graph.getDegree(i) < maximum)
		{
			cout<<"nodo "<<i<<endl;
			nodes.push_back(i);
		}	
	}

	if (nodes.size() == 0)
	{
		return;
	}
	else if (nodes.size() == 2)
	{
		if ( !graph.getEdge(nodes[0],nodes[1]) ==  true && waxmanProbability(graph,nodes[0],nodes[1]) == true )
		{
			cout<<"Ligação entre "<<nodes[0]<<" e "<<nodes[1]<<endl;
			graph.setEdge(nodes[0],nodes[1]);	

			return;
		}
	}

	random_shuffle(nodes.begin(),nodes.end());//sorteio


	vector<int> sources = vector<int> (graph.getNumberOfNodes(),0);
	vector<int> targets = vector<int> (graph.getNumberOfNodes(),0);
	int controller = 0;

	/**
	 * Sorteia um par de nodos origem e destino
	 */
	while(true) 
	{

		int indexNode = random(0,nodes.size()-1); 
		// cout<<"indexNode "<<indexNode<<endl;
		int source = nodes[ indexNode ];

		indexNode = random(0,nodes.size()-1);
		int target = nodes[ indexNode ];


		if (target == source || graph.getDegree(source)  == maximum || graph.getDegree(target) == maximum )
		{

			if (targets[target] == 0 || sources[source] == 0)
			{

				targets[target] == 0 ? targets[target] = 1 :  targets[target] = 0 ;
				sources[source] == 0 ? sources[source] = 1 :  sources[source] = 0 ;

				if(controller == graph.getNumberOfNodes())
				{
					return;
				} 
				
				controller++;
			}

			continue;
		}

		/**
		 * Verifica se já existe ligação entre o par de nodos
		 * Conecta os nodos verificanda a probabilidade de Waxman
		 */
		if ( !graph.getEdge(source,target) ==  true && waxmanProbability(graph,source,target) == true )
		{
			cout<<"ligação entre "<<source<<" e "<<target<<endl;
			graph.setEdge(source,target);	

			return;
		}
	}
}
