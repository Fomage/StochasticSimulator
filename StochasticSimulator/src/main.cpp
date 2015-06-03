/*
 * main.cpp
 *
 *  Created on: 27 May 2015
 *      Author: Fomage
 */

#include <iostream>
#include <string>
#include <time.h>
#include <cstdlib>

#include "StochasticSimulator.h"
#include "DESP/DESP.h"
#include "CDF/ExponentialCDF.h"

using namespace std;

int main() {
	srand(time(NULL));

	int a(0), b(1);

	DESP<int>* myModel = new DESP<int>();
	Node n1(1), n2(0);
	myModel->getNodes().push_back(&n1);
	myModel->getNodes().push_back(&n2);

	ExponentialCDF law1(1), law2(2);

	Edge<int> e1(&n1,&n2,&law1,&a);
	Edge<int> e2(&n2,&n1,&law2,&b);
	myModel->getEdges().push_back(&e1);
	myModel->getEdges().push_back(&e2);

	StochasticSimulator<int> mySim(myModel);
	mySim.run(10);
	vector<int*> trace=mySim.getTrace();
	for(int i=0;i<trace.size();i++)
		cout<<*trace[i]<<endl;
	return 0;
}



