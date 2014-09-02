#include <iostream>
#include <deque>
#include <iterator>
#include <algorithm> 
#include <stdexcept> // for std::runtime_error

#include "Regions.h"

using std::cout;
using std::cin;
using std::endl;


Regions::Regions() {}

Regions::~Regions() {}

void Regions::setArea(int a){

	this->area = a;
}
void Regions::setBreadth(int b){

	this->breadth = b;
}
void Regions::setLength(int l){

	this->length = l;
}

int Regions::getArea(){

	return this->area;
}
int Regions::getBreadth(){

	return this->breadth;
}
int Regions::getLength(){

	return this->length;
}

