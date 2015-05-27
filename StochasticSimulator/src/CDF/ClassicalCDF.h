/*
 * ClassicalCDF.h
 *
 *  Created on: 20 May 2015
 *      Author: Fomage
 */

#ifndef CLASSICALCDF_H_
#define CLASSICALCDF_H_

#include "CDF.h"
#include <string>

class ClassicalCDF: public CDF {
public:
	ClassicalCDF();
	ClassicalCDF(std::string name):name(name){};
	virtual ~ClassicalCDF();

	const std::string& getName() const {
		return name;
	}

	void setName(const std::string& name) {
		this->name = name;
	}

	virtual double getValue(double p)=0;

private:
	std::string name;
};

#endif /* CLASSICALCDF_H_ */
