#ifndef PARTICLE_HPP_
#define PARTICLE_HPP_
#include <cfloat>
#include "Vector.hpp"
#include "Walls.hpp"

//Declaring the new class 'Particle'
class Particle{
public:
	//Constructor of particle class
	Particle(float radius = 1, const Vector &r = Vector(0,0), const Vector &v = Vector(0,0)) :
		radius(radius),  r(r),  v(v),timeToWall(FLT_MAX), wallToHit(XWALL)  {;}

	~Particle() {;}//destructor

	//member datas below
	float radius;
	Vector r;
	Vector v;
	float timeToWall;
	enum Wall_e wallToHit;

	void move(float time){

		r.x=r.x + v.x*time;//moves the particle in x direction with velocity multiplied by time
		r.y=r.y + v.y*time;//moves the particle in y direction with velocity multiplied by time
			timeToWall -=time;
	}

	void wallCollision(){//declaring wallcollision member function

		if(wallToHit==XWALL){
			v.x = -v.x;
		}
		if(wallToHit==YWALL){
			v.y = -v.y;
		}//function reverses velocity sign depending on which wall is being hit
	}

	float timeToWallCollision(const Vector &r, const Vector &v, Wall_e wall, float position){//timetowallcollision member function

	position -= radius;

	float time = 0;

		if(wall==XWALL){
			if (v.x==0){
				return FLT_MAX; //returns biggest floating number if no velocity in x direction
			}

		float xwalltime = (position-r.x)/v.x;//Calculates the time taken by the particle to move to one of the XWALL
		if(xwalltime < 0){
			return FLT_MAX;//returns biggest floating number provided the time is negative
			}
		time = xwalltime;
	}

		if(wall==YWALL){
			if (v.y==0){
				return FLT_MAX;//returns biggest floating number if no velocity in y direction
			}

		float ywalltime = (position-r.y)/v.y;//Calculates the time taken by the particle to move to one of the YWALLs
		if (ywalltime <0){
			return FLT_MAX;//returns the biggest floating number if the time is negative.
			}
		time = ywalltime;
	}

	return time;
}

};


#endif /* PARTICLE_HPP_ */
