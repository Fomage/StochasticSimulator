/*
 * Node.h
 *
 *  Created on: 27 May 2015
 *      Author: Fomage
 */

#ifndef NODE_H_
#define NODE_H_

class Node {
public:
	Node(double initialState=0);
	virtual ~Node();

	double getInitialState() const {
		return initialState;
	}

	void setInitialState(double initialState) {
		this->initialState = initialState;
	}

private:
	double initialState;
};

#endif /* NODE_H_ */
