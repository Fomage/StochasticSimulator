/*
 * PoissonCDF.h
 *
 *  Created on: 27 May 2015
 *      Author: Fomage
 */

#ifndef POISSONCDF_H_
#define POISSONCDF_H_

#include "ClassicalCDF.h"
#include <boost/math/distributions/poisson.hpp>

class PoissonCDF: public ClassicalCDF {
public:
	PoissonCDF(double mean=1);
	virtual ~PoissonCDF();

	virtual double getValue(double p);
private:
	boost::math::poisson dist;
};

#endif /* POISSONCDF_H_ */
