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

int
main(void)
{
	int nNodes = 2,min = 2,max = 2,area = 4,nSimulations = 1,breadth = 1,length = 4,minDistanceNode = 1;
	double betha,alpha;
	Graph graph; // cria objeto grafo
	

	cout << "Digite o número de nós: "<<endl;
	cin >> nNodes;
	graph.setNode(nNodes);

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

	plane.initialize(graph);

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

	cout<<"Número de ligações até o momento "<<graph.getNumberOfLinks()<<endl;
	while( graph.getNumberOfLinks() < graph.getMinimumNumberOfLinks() )
	{
		plane.randomLink(graph);
	}


	while( graph.getNumberOfLinks() < graph.getMaximumNumberOfLinks() )
	{
		plane.randomLink(graph);
	}
	cout<<"ligações "<<graph.getNumberOfLinks()<<"limite de ligações "<<graph.getMaximumNumberOfLinks()<<endl;
	// for (int i = 0; i < graph.getNumberOfNodes(); i++)
	// {
	// 	cout<<"v "<<i<<" degree "<<graph.getDegree(i)<<endl;
	// }

	Measure measures;

	vector<Node> _nodes = graph.getNodes();
	measures.initialize( _nodes,nNodes); //obtêm as medidas de centralidade para cada nó da rede

	return 0;
}