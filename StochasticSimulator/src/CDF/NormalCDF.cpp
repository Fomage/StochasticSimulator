/*
 * NormalCDF.cpp
 *
 *  Created on: 27 May 2015
 *      Author: Fomage
 */

#include "NormalCDF.h"
using boost::math::normal;

NormalCDF::NormalCDF(double mean, double variance) {
	setName("normal");
	dist=normal(mean,variance);
}

NormalCDF::~NormalCDF() {
	// TODO Auto-generated destructor stub
}

double NormalCDF::getValue(double p){
	if((p>0)&&(p<1))
		return quantile(dist,p);
	else
		return 0;
}





