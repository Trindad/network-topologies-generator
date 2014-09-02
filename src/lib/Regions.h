/**
 * Definições de função-membro que aparecem em Regions.cpp
 */

#include <iostream>
#include <deque>
#include <iterator>
#include <algorithm> 
#include <stdexcept> // for std::runtime_error

using std::cout;
using std::cin;
using std::endl;

#include "Graph.h"

class Regions
{
public:

	Regions();
	~Regions();
	void setArea(int);
	void setBreadth(int);
	void setLength(int);

	int getArea();
	int getBreadth();
	int getLength();

private:

	int area;
	int breadth;
	int length;
};