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


void move (Vector &r, const Vector &v, float time){

	r.x=r.x + v.x*time;
	r.y=r.y + v.y*time;
}



float timeToWall (const Vector &r, const Vector &v, Wall_e wall , float position){

	float time = 0.0;
	if(wall==XWALL){
		if (v.x == 0) {
			return -999;
		}
		float xwalltime = (position -r.x)/v.x;
		time = xwalltime;
	}

	if(wall==YWALL){
		if (v.y == 0) {
			return -999;
		}

		float ywalltime = (position -r.y)/v.y;
		time = ywalltime;
	}
	return time;
}



void wallCollision (Vector &v, enum Wall_e wall){
	if(wall==XWALL){
		v.x = -v.x;
	}
	if(wall==YWALL){
		v.y = -v.y;
	}

}

