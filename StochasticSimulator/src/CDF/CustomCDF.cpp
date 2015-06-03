/*
 * CustomCDF.cpp
 *
 *  Created on: 3 Jun 2015
 *      Author: Fomage
 */

#include "CustomCDF.h"
#include <cstdlib>

CustomCDF::CustomCDF(double(*func)(double arg), double inf, double sup, int n) {
	weights=vector<double>();
	args=vector<double>();

	double step=(sup-inf)/n;
	double current=inf;
	for(int i=0;i<n+1;i++){
		args.push_back(current);
		weights.push_back(func(current));
		current+=step;
	}
	//changing the values into weights
	weights.push_back(1-weights[n]);
	args.push_back(current);
	maxArg=current;
	for(int i=n;i>0;i--){
		weights[i]=weights[i]-weights[i-1];
	}
	//sorting
	quicksort(0,n+1);
	if(!isSorted())
		throw "Sort isn't working.";
	//convert weights into cumulated weights
	for(int i=1;i<weights.size();i++){
		weights[i]+=weights[i-1];
	}
	if(weights[n+1]!=1)
		throw "the sum isn't 1 anymore !!!";
}

CustomCDF::~CustomCDF() {
	// TODO Auto-generated destructor stub
}

void CustomCDF::switch2(int i, int j){
	double ow=weights[i];
	double oa=args[i];
	weights[i]=weights[j];
	args[i]=args[j];
	weights[j]=ow;
	args[j]=oa;
}

void CustomCDF::quicksort(int l, int u){
	if(l<u-1){
		int pivot=rand()%(u-l+1)+l;
		switch2(u,pivot);
		int k=l;
		int a=u-1;
		for(int i=0;i<u-l;i++){
			if(weights[k]<weights[u]){
				switch2(k,a);
				a--;
			}else{
				k++;
			}
		}
		switch2(k,u);
		quicksort(l,k-1);
		quicksort(k+1,u);
	}
}

bool CustomCDF::isSorted(){
	for(int i=1;i<weights.size();i++){
		if(weights[i-1]<weights[i])
			return false;
	}
	return true;
}

double CustomCDF::getValue(double p){
	if((p>0)&&(p<1)){
		for(int i=0;i<weights.size();i++){
			if(p<weights[i]){
				if(args[i]==maxArg)
					return 1;
				else
					return args[i];
			}
		}
		throw "No value found in CustomCDF::getValue ?!?";
	}
	else
		return 0;
}


