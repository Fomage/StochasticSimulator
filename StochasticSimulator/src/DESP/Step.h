/*
 * Step.h
 *
 *  Created on: 15 Sep 2015
 *      Author: Fomage
 */

#ifndef STEP_H_
#define STEP_H_

#include "Edge.h"

template <class EventType> class Step {
public:
	Step<EventType>(double timeIn, double timeOut, Edge<EventType>* edge):
	timeIn(timeIn),timeOut(timeOut),edge(edge)
	{}
	virtual ~Step<EventType>(){}

	Edge<EventType>* getEdge() const {
		return edge;
	}

	void setEdge(Edge<EventType>* edge) {
		this->edge = edge;
	}

	double getTimeIn() const {
		return timeIn;
	}

	void setTimeIn(double timeIn) {
		this->timeIn = timeIn;
	}

	double getTimeOut() const {
		return timeOut;
	}

	void setTimeOut(double timeOut) {
		this->timeOut = timeOut;
	}

private:
	double timeIn, timeOut;
	Edge<EventType>* edge;
};

#endif /* STEP_H_ */
