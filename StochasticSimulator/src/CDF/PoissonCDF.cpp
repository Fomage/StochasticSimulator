/*
 * PoissonCDF.cpp
 *
 *  Created on: 27 May 2015
 *      Author: Fomage
 */

#include "PoissonCDF.h"
using boost::math::poisson;

PoissonCDF::PoissonCDF(double mean) {
	setName("poisson");
	if(mean>0)
		dist=poisson(mean);
	else
		dist=poisson(1);
}

PoissonCDF::~PoissonCDF() {
	// TODO Auto-generated destructor stub
}

double PoissonCDF::getValue(double p){
	if((p>0)&&(p<1))
		return quantile(dist,p);
	else
		return 0;
}





