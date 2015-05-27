/*
 * StochasticSimulator.h
 *
 *  Created on: 27 May 2015
 *      Author: Fomage
 */

#ifndef STOCHASTICSIMULATOR_H_
#define STOCHASTICSIMULATOR_H_

#include <vector>
#include "DESP/DESP.h"
#include <cstdlib>

template <class EventType> class StochasticSimulator {
public:
	StochasticSimulator<EventType>(DESP<EventType> *despArg){
		desp=despArg;
		currentTrace=vector<EventType*>();
		reset();
	}
	virtual ~StochasticSimulator<EventType>(){}

	void reset(){//choses a new initial state AND destroys the currentTrace
		currentTime=0;
			currentTrace.clear();
			double total=0;
			for(int i=0;i<desp->getNodes().size();i++){
				total+=(desp->getNodes()[i])->getInitialState();
			}
			double chosen=(double)rand()*total/(double)RAND_MAX;
			double current=0;
			int j=-1;
			do{
				j++;
				current+=desp->getNodes()[j]->getInitialState();
			}while(current<chosen);
			currentState=desp->getNodes()[j];
	}
	void step();
	void run(double t=0);//runs until currentTime reaches t, or until deadlock if t is negative.
	vector<EventType*> returnTrace();

	double getCurrentTime();

private:
	DESP<EventType>* desp;
	double currentTime;
	Node* currentState;
	vector<EventType*> currentTrace;
};

#endif /* STOCHASTICSIMULATOR_H_ */
