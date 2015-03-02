#include "Measure.hpp"

Measure::Measure(){}


Measure::~Measure(){}

void Measure::initialize(vector<Node> & nodes)
{

}

double Measure::getDegreeCentrality(int index)
{
	return nodes[index].getDegreeCentrality();
}


double Measure::getBetweenCentrality(int index)
{
	return nodes[index].getBetweenCentrality();
}


double Measure::getClosenessCentrality(int index)
{
	return nodes[index].getClosenessCentrality();
}


double Measure::getEfficientCentrality(int index)
{
	return nodes[index].getEfficientCentrality();
}


void Measure::setDegreeCentrality(int index,double value)
{
	nodes[index].setDegreeCentrality(value);
}


void Measure::setBetweenCentrality(int index,double value)
{
	nodes[index].setDegreeCentrality(value);
}


void Measure::setClosenessCentrality(int index,double value)
{
	nodes[index].setClosenessCentrality(value);
}


void Measure::setEfficientCentrality(int index, double value)
{
	nodes[index].setEfficientCentrality(value);
}