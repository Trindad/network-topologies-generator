/**
 *
 * ****************************************************************
 * Gerador de topologias físicas de redes reais de telecomunicações
 * Desenvolvido em linguagem C++ utilizando o conceito de classes
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
 
using std::cout;
using std::cin;
using std::endl;
using std::getline;

#include "Plane.h"
#include "Graph.h"


int main(void)
{

	int nNos,min,max,area,nSimulations = 1,breadth,length,minDistance;
	double prWaxman1,prWaxman2;
	Graph graph; // cria objeto grafo
	Plane plane;

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
	cin >> minDistance;
	graph.setMinimumDistance(minDistance);

	cout << "Digite a area: "<<endl;
	cin >> nNos;
	plane.setArea(nNos);

	cout << "Digite o comprimento de uma região: "<<endl;
	cin >> length;
	plane.setLength(length);

	cout << "Digite a largura de uma região: "<<endl;
	cin >> breadth;
	plane.setBreadth(breadth);


	try{

		plane.limitArea(graph.getNode());
	}
	catch(int error) {

	}
	// cout << "Probabilidade de Waxman: "<<endl;
	// cin >> prWaxman1;
	// graph.setWaxmanOne(prWaxman1);

	// cout << "Probabilidade de Waxman: "<<endl;
	// cin >> prWaxman2;
	// graph.setWaxmanTwo(prWaxman2);

	return 0;
}