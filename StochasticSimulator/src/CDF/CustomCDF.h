/*
 * CustomCDF.h
 *
 *  Created on: 3 Jun 2015
 *      Author: Fomage
 */

#ifndef CUSTOMCDF_H_
#define CUSTOMCDF_H_

#include "CDF.h"
#include <vector>

using std::vector;

class CustomCDF: public CDF {
public:
	CustomCDF(double(*func)(double arg), double inf=-10, double sup=10, int n=100);//assuming func is a CDF
	virtual ~CustomCDF();

	virtual double getValue(double p);

private:
	vector<double> weights;
	vector<double> args;
	double maxArg;

	void switch2(int i, int j);
	void quicksort(int l, int u);
	//just to test
	bool isSorted();
};

#endif /* CUSTOMCDF_H_ */
