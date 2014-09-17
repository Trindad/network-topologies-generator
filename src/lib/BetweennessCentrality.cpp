#include <iostream>
#include <deque>
#include <iterator>
#include <algorithm> 
#include <stdexcept> // for std::runtime_error
#include <string>

#include "GraphUtility.hpp"
#include "Plane.hpp"
#include "BetweennessCentrality.hpp"


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

int GraphUtility::distanceMinimum() {

}

void GraphUtility::addNode() {

}

void GraphUtility::addPath() {

}

void GraphUtility::insertPath() {

}

int GraphUtility::searchPath() {

}

double BetweennessCentrality::calculateGeodesic() {

}