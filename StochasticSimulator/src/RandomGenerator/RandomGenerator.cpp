/*
 * RandomGenerator.cpp
 *
 *  Created on: 27 May 2015
 *      Author: Fomage
 */

#include "RandomGenerator.h"

RandomGenerator::RandomGenerator() {
	// TODO Auto-generated constructor stub

}

RandomGenerator::~RandomGenerator() {
	// TODO Auto-generated destructor stub
}

double RandomGenerator::sample(CDF *f){
	double p=((double)rand()/(double)RAND_MAX);
	while((p==0)||(p==1))
		p=((double)rand()/(double)RAND_MAX);
	return f->getValue(p);
}

