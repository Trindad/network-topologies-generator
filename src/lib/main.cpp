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

#include "Graph.h"

int main(void)
{

	int nNos,nLinks;
	Graph graph; // cria objeto grafo

	cout << "Digite o número de nós: "<<endl;
	cin >> nNos;
	graph.setNode(nNos);

	cout << "Digite o número de links: "<<endl;
	cin >> nLinks;
	graph.setLink(nLinks);

	return 0;
}