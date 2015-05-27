/*
 * NormalCDF.h
 *
 *  Created on: 27 May 2015
 *      Author: Fomage
 */

#ifndef NORMALCDF_H_
#define NORMALCDF_H_

#include "ClassicalCDF.h"
#include <boost/math/distributions/normal.hpp>

class NormalCDF: public ClassicalCDF {
public:
	NormalCDF(double mean=0, double variance=1);
	virtual ~NormalCDF();

	virtual double getValue(double p);
private:
	boost::math::normal dist;
};

#endif /* NORMALCDF_H_ */
