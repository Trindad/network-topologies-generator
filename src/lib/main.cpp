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

int
main(void)
{

	int nNos = 2,min = 2,max = 2,area = 4,nSimulations = 1,breadth = 1,length = 4,minDistanceNode = 1;
	double betha,alpha;
	Graph graph; // cria objeto grafo
	

	cout << "Digite o número de nós: "<<endl;
	cin >> nNos;
	graph.setNode(nNos);

	cout << "Digite o número do grau médio mínimo: "<<endl;
	cin >> min;
	graph.setMinimumDegree(min);

	cout << "Digite o número do grau médio máximo: "<<endl;
	cin >> max;
	graph.setMaximumDegree(max);

	cout << "Digite a distância mínima entre dois nós: "<<endl;
	cin >> minDistanceNode;
	graph.setMinimumDistanceOfNode(minDistanceNode);

	/**
	 * Configurações do plano
	 */
	
	Plane plane;

	cout << "Digite a area: "<<endl;
	cin >> area;
	plane.setArea(area);

	cout << "Digite o comprimento de uma região: "<<endl;
	cin >> length;
	plane.setLength(length);

	cout << "Digite a largura de uma região: "<<endl;
	cin >> breadth;
	plane.setBreadth(breadth);

	plane.initialize(graph);
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


	return 0;
}