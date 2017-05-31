/*
 * functions.cpp
 *
 *  Created on: 2 Mar 2015
 *      Author: ap14080
 */

#include "functions.hpp"
#include <iostream>
#include <string>
#include <cmath>
#include "Vector.hpp"
using namespace std;

float mouldusSqr(const Vector &v) {

	float square =(v.x*v.x) + (v.y*v.y);//calculates the sum of the squares of x and y vector components
	return square;
}

float mouldus (const Vector &v){

	float root = sqrt(mouldusSqr(v));//square rooting the squared sums
	return root;
}


float distance (const Vector &r1, const Vector &r2){

	//calculates difference between two points, and assigns it to the components of vector r
	Vector r;
	r.x =r2.x-r1.x;
	r.y =r2.y-r1.y;
	float distance=	mouldus(r);//calling mouldus function to find the absolute distance from the x and y differences
	return distance;
}


float dotProduct (const Vector &v1, const Vector &v2){

	float dot = (v1.x*v2.x) + (v1.y*v2.y);
	return dot;
}


void move (Vector &r, const Vector &v, float time){

	//moves the particles components by velocity*time .... no return
	r.x=r.x + v.x*time;
	r.y=r.y + v.y*time;
}


float timeToWall (const Vector &r, const Vector &v, Wall_e wall , float position){

	float time = 0.0;
	if(wall==XWALL){//checks if particle heading to xwall
		if (v.x == 0) {
			return -999;//returns -999 if moving away from xwall
		}
		float xwalltime = (position -r.x)/v.x;//calculating time to reach xwall
		time = xwalltime;
	}

	if(wall==YWALL){//checks if particle heading to ywall
		if (v.y == 0) {
			return -999;//returns -999 if moving away from ywall
		}
		float ywalltime = (position -r.y)/v.y;//calculating time to reach ywall
		time = ywalltime;
	}


	return time;

}



