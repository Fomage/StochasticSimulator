/*
 * Node.cpp
 *
 *  Created on: 27 May 2015
 *      Author: Fomage
 */

#include "Node.h"

Node::Node(double is){
	if(is>=0)
		initialState=is;
	else
		initialState=0;
}

Node::~Node() {
	// TODO Auto-generated destructor stub
}

