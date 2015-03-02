/**
 * Definições de função-membro que aparecem em Measure.cpp
 */
#include <iostream>
#include <deque>
#include <iterator>
#include <algorithm> 
#include <stdexcept> // for std::runtime_error
#include <vector>
#include <random>


 using namespace std;

 class Measure
 {
 public:

 	Measure();
 	~Measure();

 	initialize();

 	getDegreeCentrality();
	getBetweenCentrality();
	getClosenessCentrality();
	getEfficientCentrality();


	setDegreeCentrality();
	setBetweenCentrality();
	setClosenessCentrality();
	setEfficientCentrality();


	degreeCentrality();
	betweenCentrality();
	closenessCentrality();
	efficientCentrality();	
 };