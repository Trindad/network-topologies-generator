#include <iostream>
#include <deque>
#include <iterator>
#include <algorithm> 
#include <cmath>
#include <stdexcept> // for std::runtime_error

#include "Plane.h"
#include "Graph.h"


using namespace std;

Plane::Plane() {}

Plane::~Plane() {}

void Plane::setArea(int side){

	this->side = side;
	memsetPlane();
}

void Plane::setBreadth(int breadth){

	this->breadth = breadth;
}
void Plane::setLength(int length){

	this->length = length;
}

int Plane::getArea(){

	return this->side;
}

int Plane::getBreadth(){

	return this->breadth;
}

int Plane::getLength(){

	return this->length;
}

/**
 * value one region
 * breadth and length
 */
void Plane::setRegion(int nNodes) {

	this->regionBreadth = (int)floor(this->side/this->breadth);
	this->regionLength = (int)floor(this->side/this->length);

	setNodeRandomRegion(nNodes);
}

/**
 * Set values in 0
 */
void Plane::memsetPlane() {

	int i,j,n = this->side;

	for (i = 0; i < n; i++)
	{
		for (i = 0; i < n; j++)
		{
			this->plane[i][j] = 0;
		}
	}
}

/**
 * For N nodes, the number of regions in the area should be at least 2N, as seen from the real networks (Of
 * course, some networks may need more than 2N regions. N^2 is the upper limit. So number of regions, R
 * should be in between 2N and N2. i.e., 2N ≤ R ≤ N^2). So there are several options to divide the area into
 * different types of rectangular dimensions.
 */
void Plane::limitArea(int nNodes) {

	if (this->side > (nNodes*nNodes) || this->side < (2*nNodes)) {
		throw("2N ≤ R ≤ N²");
	}
}

/**
 * Choose any N regions randomly, out of the total R regions, and some of the
 * regions may be chosen more than once (i.e., have more than one nodes).
 */
void Plane::setNodeRandomRegion(int nNodes) {

	int i;

	for (i = 0; i < nNodes; i++)
	{
		
	}
}