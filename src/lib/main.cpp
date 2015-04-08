/**
 *
 * ****************************************************************
 * Gerador de topologias físicas de redes reais de telecomunicações
 * Desenvolvido em linguagem C++ utilizando o conceito de classes
 *
 * Compile:
 * 	g++ *.cpp -o main -std=c++11 -g
 * ****************************************************************
 *
 * Copyright(c) 2014 S. Trindade
 * 
 */

#include <iostream>
#include <string>
#include <deque>
#include <iterator>
#include <algorithm> 
 
using namespace std;

#include "Plane.hpp"
#include "Measure.hpp"
#include "Suurballe.hpp"

int
main(void)
{
	int nNodes = 2,min = 2,max = 2,area = 4,nSimulations = 1,breadth = 1,length = 4,minDistanceNode = 1;
	double betha,alpha;
	Graph graph; // cria objeto grafo
	

	cout << "Digite o número de nós: "<<endl;
	cin >> nNodes;
	graph.setNumberOfNodes(nNodes);

	cout << "Digite o número do grau médio mínimo: "<<endl;
	cin >> min;
	graph.setMinimumDegree(min);

	cout << "Digite o número do grau médio máximo: "<<endl;
	cin >> max;
	graph.setMaximumDegree(max);

	cout << "Digite a distância mínima entre dois nós: "<<endl;
	cin >> minDistanceNode;
	graph.setMinimumDistanceOfNode(minDistanceNode);

	graph.memsetGraph();

	/**
	 * Configurações do plano
	 */
	
	Plane plane;

	cout << "Digite a area: "<<endl;
	cin >> area;
	plane.setArea(area);

	int config = 1;

	cout<<"Digite 1 para configurar a região por largura X comprimento" <<endl;
	cout<<"Digite 2 para configurar a região por número de regiões" <<endl;
	cin>>config;

	/**
	 * Verifica tipo de configuração para as regiões
	 * Caso o usuário inserir somente o número de regiões
	 * Então será calculado a largura e o comprimento.
	 */
	if (config == 1)
	{
		cout << "Digite o comprimento de uma região: "<<endl;
		cin >> length;
		plane.setLength(length);

		cout << "Digite a largura de uma região: "<<endl;
		cin >> breadth;
		plane.setBreadth(breadth);
	}
	else
	{
		int numberRegions = 0;

		cout << "Digite o número de regiões do plano: "<<endl;
		cin >> numberRegions;

		plane.setNumberRegions(numberRegions);

		plane.setRegionsMeasures();
	}
	
	cout << "Probabilidade de Waxman: "<<endl;
	cin >> betha;

	cout << "Probabilidade de Waxman: "<<endl;
	cin >> alpha;
	plane.setWaxmanParameters(alpha,betha);
	
	try 
	{
		plane.limitArea(graph.getNumberOfNodes());
	}
	catch(const char *error) 
	{
		cout<<error<<endl;
	}
	cout<<"Incialize o plano"<<endl;

	plane.initialize(graph);

	cout<<"Fim das interligações"<<endl;
	/**
	 * Verifica se o número de ligações foi atingido
	 * Se sim verifica se a topologia gerada é sobrevivente
	 * Do contrário realiza sorteio randômico de nós até atingir 
	 * o limit e máximo, verificando-se a sobrevivência
	 */
	// cout <<" LIMITES "<< graph.getNumberOfLinks()<<endl;
	// cout <<" LIMITES "<< graph.getMinimumNumberOfLinks()<<endl;

	// for (int i = 0; i < graph.getNumberOfNodes(); i++)
	// {
	// 	cout<<"v "<<i<<" degree "<< graph.getDegree(i) <<endl;
	// }

	int notMax = std::numeric_limits<int>::max();

	cout<<"Numero de ligações "<<graph.getNumberOfEdges()<<" máximo de ligações "<<graph.getMaximumNumberOfEdges()<<endl;
	while( graph.getNumberOfEdges() < graph.getMinimumNumberOfEdges() && notMax >= 2)
	{
		notMax = plane.randomLink(graph);//retorna o número de nós que ainda não atingiram o limite de ligações
	}


	while( graph.getNumberOfEdges() < graph.getMaximumNumberOfEdges() && notMax >= 2)
	{
		notMax = plane.randomLink(graph);//retorna o número de nós que ainda não atingiram o limite de ligações
	}

	cout<<"Numero de ligações "<<graph.getNumberOfEdges()<<" máximo de ligações "<<graph.getMaximumNumberOfEdges()<<endl;

	// vector<Node> p = graph.getNodes();
	// cout<<"ligações "<<graph.getNumberOfEdges()<<"limite de ligações "<<graph.getMaximumNumberOfLinks()<<endl;
	// for (int i = 0; i < graph.getNumberOfNodes(); i++)
	// {
	// 	cout<<"v "<<i<<" degree "<<graph.getDegree(i)<<endl;

		
	// 	vector<int> adj = p[i].getAdjacentsNodes();
	// 	for (int j = 0; j < adj.size(); j++)
	// 	{
	// 		cout<<" "<<adj[j];
	// 	}
	// 	cout<<endl;
	// }

	cout<<"Measure"<<endl;
	Measure measures;

	vector<Node> _nodes = graph.getNodes();
	measures.initialize( _nodes,nNodes); //obtêm as medidas de centralidade para cada nó da rede


	/**
	 * Teste algoritmo de Suurballe
	 */
	
	//inserir nós no grafo
	
	cout<<"\n\nTeste Suurballe "<<endl;
	
	// Graph g;

	// g.setNumberOfNodes(6);
	// g.memsetGraph();

	// /**
	//  * Insere as arestas e seus respectivos pesos 
	//  */
	// g.setMaximumDegree(5);
	// g.setMinimumDegree(2);

	// g.setEdge(3,5);
	// g.setEdge(5,4);
	// g.setEdge(4,1);
	// g.setEdge(1,0);
	// g.setEdge(0,2);
	// g.setEdge(2,3);
	// g.setEdge(3,1);

	// g.setWeight(3,5,1);
	// g.setWeight(5,4,2);
	// g.setWeight(4,1,2);
	// g.setWeight(0,1,1);
	// g.setWeight(0,2,2);
	// g.setWeight(2,3,2);
	// g.setWeight(1,3,1);


	Suurballe s;

	bool suvivor = s.execute(graph);

	cout<<"suvivor "<<suvivor<<endl;
	return 0;
}