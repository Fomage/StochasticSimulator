/*
 * RandomGenerator.h
 *
 *  Created on: 27 May 2015
 *      Author: Fomage
 */

#ifndef RANDOMGENERATOR_H_
#define RANDOMGENERATOR_H_

#include "../CDF/CDF.h"
#include <cstdlib>

class RandomGenerator {
public:
	RandomGenerator();
	virtual ~RandomGenerator();

	static double sample(CDF *f);
};

#endif /* RANDOMGENERATOR_H_ */
