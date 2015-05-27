/*
 * ExponentialCDF.h
 *
 *  Created on: 27 May 2015
 *      Author: Fomage
 */

#ifndef EXPONENTIALCDF_H_
#define EXPONENTIALCDF_H_

#include "ClassicalCDF.h"
#include <boost/math/distributions/exponential.hpp>

class ExponentialCDF: public ClassicalCDF {
public:
	ExponentialCDF(double lambda=1);
	virtual ~ExponentialCDF();

	virtual double getValue(double p);

private:
	boost::math::exponential dist;
};

#endif /* EXPONENTIALCDF_H_ */
