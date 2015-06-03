/*
 * ExponentialCDF.cpp
 *
 *  Created on: 27 May 2015
 *      Author: Fomage
 */

#include "ExponentialCDF.h"
using boost::math::exponential;

ExponentialCDF::ExponentialCDF(double lambda) {
	setName("exponential");
	dist=exponential(lambda);
}

ExponentialCDF::~ExponentialCDF() {
	// TODO Auto-generated destructor stub
}

double ExponentialCDF::getValue(double p){
	if((p>0)&&(p<1))
		return quantile(dist,p);
	else
		return 0;
}


