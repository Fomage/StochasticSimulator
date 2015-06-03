/*
 * StochasticSimulator.h
 *
 *  Created on: 27 May 2015
 *      Author: Fomage
 */

#ifndef STOCHASTICSIMULATOR_H_
#define STOCHASTICSIMULATOR_H_

#include "DESP/DESP.h"
#include "RandomGenerator/RandomGenerator.h"
#include <vector>
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

	void step(){
		vector<Edge<int>*> *exits=desp->getTransitions(currentState);
		if(exits->empty())
			throw "Deadlock state reached.";
		//choose a transition : the lowest transition time
		int chosenExit=0;
		double transitionTime=RandomGenerator::sample((*exits)[0]->getCdf());
		if(transitionTime<0)
			throw "Negative time !!!";
		for(int i=1;i<exits->size();i++){
			int t=RandomGenerator::sample((*exits)[i]->getCdf());
			if(t<0)
				throw "Negative time !";
			if(t<transitionTime){
				transitionTime=t;
				chosenExit=i;
			}
		}

		currentTrace.push_back((*exits)[chosenExit]->getEvent());
		currentTime+=transitionTime;
		currentState=(*exits)[chosenExit]->getTarget();
	}

	void run(double t=0){//runs until currentTime reaches t, or until deadlock if t is negative.
		if(t>0){
			while(currentTime<t)
				step();
		}else{
			try{
				while(true)
					step();
			}catch (char* e){}
		}
	}

	vector<EventType*>& getTrace(){
		return currentTrace;
	}

	double getCurrentTime(){
		return currentTime;
	}

private:
	DESP<EventType>* desp;
	double currentTime;
	Node* currentState;
	vector<EventType*> currentTrace;
};

#endif /* STOCHASTICSIMULATOR_H_ */
