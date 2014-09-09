#include <iostream>
#include <deque>
#include <iterator>
#include <algorithm> 
#include <stdexcept> // for std::runtime_error
#include <string>

#include "GraphUtility.h"
#include "Plane.h"
#include "BetweennessCentrality.h"


BetweennessCentrality::BetweennessCentrality(){

}
BetweennessCentrality::~BetweennessCentrality(){}

void GraphUtility::Dijkstra() {

	Plane plane;

	int distance[plane.getArea()];
	int sptSet[plane.getArea()];

	memsetVector(plane.getArea(),distance);
	memsetVector(plane.getArea(),sptSet);
}