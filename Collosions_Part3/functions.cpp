/*
 * functions.cpp
 *
 *  Created on: 2 Mar 2015
 *      Author: ap14080
 */
#include "functions.hpp"
#include "Walls.hpp"
#include "Vector.hpp"
#include "Particle.hpp"
#include <iostream>
#include <cmath>

using std::cin;
using std::cout;
using std::endl;
using std::abs;

float setParticleWallCollisionTime(Particle &p,float position){

	float xwalltime1 = p.timeToWallCollision(p.r,p.v,p.wallToHit,position);
	float xwalltime2 = p.timeToWallCollision(p.r,p.v,p.wallToHit,-position);
	p.wallToHit = YWALL;
	float ywalltime1 = p.timeToWallCollision(p.r,p.v,p.wallToHit,position);
	float ywalltime2 = p.timeToWallCollision(p.r,p.v,p.wallToHit,-position);
	p.wallToHit = XWALL;//Change back to its initial value.
	float xwalltime;
//runs tests to select to shortest time possible using absolute values (both x and y walls), and then assigns it to their respective times
	if(abs(xwalltime1)-abs(xwalltime2)<0){
		xwalltime = xwalltime1;
	}else if (abs(xwalltime1)-abs(xwalltime2)>0){
		xwalltime = xwalltime2;
	}else if(abs(xwalltime1)-abs(xwalltime2)==0){
		xwalltime =FLT_MAX;
	}

	float ywalltime;
	if(abs(ywalltime1)-abs(ywalltime2)<0){
		ywalltime = ywalltime1;
	}else if (abs(ywalltime1)-abs(ywalltime2)>0){
		ywalltime = ywalltime2;
	}else if (abs(ywalltime1)-abs(ywalltime2)==0){
		ywalltime = FLT_MAX;
	}

	if(abs(xwalltime)-abs(ywalltime)<0){
		p.timeToWall = xwalltime;
		return xwalltime;
	}else if(abs(xwalltime)-abs(ywalltime)>0){
		p.timeToWall = ywalltime;
		return ywalltime;
	}

return 0;
}
