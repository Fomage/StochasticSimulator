/*
 * Edge.h
 *
 *  Created on: 27 May 2015
 *      Author: Fomage
 */

#ifndef EDGE_H_
#define EDGE_H_

#include "Node.h"
#include "../CDF/CDF.h"

template <class EventType> class Edge {
public:
	Edge<EventType>(Node* source, Node* target, CDF* cdf, EventType* event):
	source(source),target(target),cdf(cdf),event(event){}
	virtual ~Edge<EventType>(){}//Warning : nothing is deleted. Everything is left to the user.

	const CDF*& getCdf() const {
		return cdf;
	}

	void setCdf(const CDF*& cdf) {
		this->cdf = cdf;
	}

	EventType* getEvent() const {
		return event;
	}

	void setEvent(EventType* event) {
		this->event = event;
	}

	const Node*& getSource() const {
		return source;
	}

	void setSource(const Node*& source) {
		this->source = source;
	}

	const Node*& getTarget() const {
		return target;
	}

	void setTarget(const Node*& target) {
		this->target = target;
	}

private:
	Node *source, *target;
	CDF *cdf;
	EventType *event;
};

#endif /* EDGE_H_ */
