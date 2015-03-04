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


	void degreeCentrality();
	void closenessCentrality();
	void efficientCentrality();	
	void betweenCentrality(vector<Node> nodes);

 	double geodesic(vector<Node>,int);
 	void initialize(vector<Node> &,int);
 	int nodeSearch(vector< vector<int> >, int);

private:

	vector<Node> nodes;
	int numberOfNodes;
	int centralNode;	//nó central em relação a centralidade de intermediação
 };