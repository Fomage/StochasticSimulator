/*
 * CDF.h
 *
 *  Created on: 20 May 2015
 *      Author: Fomage
 */

#ifndef CDF_H_
#define CDF_H_


class CDF{//Cumulative Distribution Function
public:
	/*
	 * Argument double p : real between 0 and 1
	 * return : F^-1(p)
	 */
	virtual double getValue(double p)=0;
};


#endif /* CDF_H_ */
