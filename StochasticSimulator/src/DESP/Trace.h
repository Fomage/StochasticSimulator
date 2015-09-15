/*
 * Trace.h
 *
 *  Created on: 15 Sep 2015
 *      Author: Fomage
 */

#ifndef TRACE_H_
#define TRACE_H_

#include "Step.h"
#include "Node.h"
#include "DESP.h"

#include <vector>
#include <map>
#include <cstdlib>
using std::vector;
using std::map;

template <class EventType> class Trace {
public:

	vector<Step<EventType>*> trace;

	Trace<EventType>(){
		trace=vector<Step<EventType>*>();
	}
	virtual ~Trace<EventType>(){}

	double getStayTime(int i){
		if((i>=trace.size())||(i<0))
			throw "Invalid index";
		return trace[i]->getTimeOut()-trace[i]->getTimeIn();
	}

	map<Node*,double>* getSpentTimeRepartition(DESP<EventType>* desp){
		map<Node*,double>* res = new map<Node*,double>();
		for(int i=0;i<desp->getNodes().size();i++)
			(*res)[desp->getNodes()[i]]=0;
		for(int i=0;i<trace.size();i++)
			(*res)[trace[i]->getEdge()->getSource()]+=getStayTime(i);
		return res;
	}
};

#endif /* TRACE_H_ */
