/*
 * DESP.h
 *
 *  Created on: 27 May 2015
 *      Author: Fomage
 */

#ifndef DESP_H_
#define DESP_H_

#include <vector>
using std::vector;

#include "Edge.h"
#include "Node.h"

template <class EventType> class DESP {
public:
	DESP<EventType>(){
		nodes=vector<Node*>();
		edges=vector<Edge<EventType>*>();
	}
	virtual ~DESP<EventType>(){
		for(int i=0;i<nodes.size();i++)
			delete nodes[i];
		for(int i=0;i<edges.size();i++)
			delete edges[i];
	}

	vector<Edge<EventType> *>& getEdges() {
		return edges;
	}

	void setEdges(vector<Edge<EventType> *>& edges) {
		delete this->edges;
		this->edges = edges;
	}

	vector<Node*>& getNodes() {
		return nodes;
	}

	void setNodes(vector<Node*>& nodes) {
		delete this->nodes;
		this->nodes = nodes;
	}

	//Utilities
	vector<Edge<EventType>*>* getTransitions(Node* n){
		vector<Edge<EventType>*>* res = new vector<Edge<EventType>*>();
		for(int i=0;i<edges.size();i++){
			if(edges[i]->getSource()==n)
				res->push_back(edges[i]);
		}
		return res;
	}

private:
	vector<Node*> nodes;
	vector<Edge<EventType>*> edges;
};

#endif /* DESP_H_ */
