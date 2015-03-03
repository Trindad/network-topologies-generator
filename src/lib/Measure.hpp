/**
 * Definições de função-membro que aparecem em Measure.cpp
 */
#include "Brandes.hpp"

 using namespace std;

 class Measure
 {
 public:

 	Measure();
 	~Measure();


 	double getDegreeCentrality(int);
	double getBetweenCentrality(int);
	double getClosenessCentrality(int);
	double getEfficientCentrality(int);


	void setDegreeCentrality(int,double);
	void setBetweenCentrality(int,double);
	void setClosenessCentrality(int,double);
	void setEfficientCentrality(int, double);

 	void initialize(vector<Node> &,int);

	void degreeCentrality();
	void betweenCentrality();
	void closenessCentrality();
	void efficientCentrality();	

private:

	vector<Node> nodes;
	int numberOfNodes;
 };