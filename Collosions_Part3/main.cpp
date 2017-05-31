/*
 * main.cpp
 *
 *  Created on: 2 Mar 2015
 *      Author: ap14080
 */

#include <iostream>
#include <string>
#include <cstdlib>
#include <iomanip>
#include "functions.hpp"
#include "test.hpp"
#include "Vector.hpp"
using std::cin;
using std::cout;
using std::endl;


int main() {

	cout << "Starting" << endl;

	 test ();

	 //declaring variables
	 float position = 100;
	 float radius = 1;
	 Vector v(2, 1);
	 Vector r(0, 0);
	 int collisions = 0;

	 srand(12345);//random seed 12345 to be used in generation

	 float minirandom = -99;//minimal value
	 float maxirandom = 198;//maximum value that can be added to minimum

	 float therandom = minirandom + maxirandom*float(std::rand())/RAND_MAX;//random number generation between minimum and maximum values (-99 to 99)
	 r.x = therandom;//assigning the random number to x position
	 therandom = minirandom + maxirandom*float(std::rand())/RAND_MAX;//random number generation between minimum and maximum values(-99 to 99)
	 r.y = therandom;//assigning the random number to y position
	 cout<<"The initial position is: "<<"("<<r.x<< ", " <<r.y<< ")" << endl;//outputs initial position to console


	 float minirandomvel = -10;
	 float maxirandomvel = 20;

	 float randomvel = minirandomvel + maxirandomvel*float(std::rand())/RAND_MAX;//random number generation between minimum and maximum values(-10 to 10)
	 v.x = randomvel; //assigning the random number to x velocity
	 randomvel = minirandomvel + maxirandomvel*float(std::rand())/RAND_MAX;//random number generation between minimum and maximum values(-10 to 10)
	 v.y = randomvel;//assigning the random number to y velocity
	 cout<<"The initial velocity is: "<<"("<<v.x<< ", " <<v.y<< ")" << endl;//outputs initial velocity to console


		Particle p(1,r,v);//creates particle p
		float collisionTime = setParticleWallCollisionTime(p,position);//calling setParticleWallCollisionTime function
		int bouncytimes = 10000;//there will be 10000 bounces
		int centurybounce = 0;
		for(int i=0;i<bouncytimes;i++){
			if(collisionTime==FLT_MAX){
				cout<<"will take way too long to collide"<<endl;
				return 0;
			}
			p.move(collisionTime);//making the particle move towards a wall
			p.wallCollision();
			collisionTime = setParticleWallCollisionTime(p, position);
			collisions ++;

				if (collisions % 100==0){//checking if particle has collided the next hundredth bounce, should be no remainder
					centurybounce+=100;//adding a hundred to the bouncecounter if above condition met
					float mass = 1;//the particles mass is 1
					float velosquared = p.v.mouldusSqr();//calculating the particles speed
					float kineticenergy = (float(1)/2)*mass*velosquared;//calculating the particles kinetic energy
					float momentum = mass*p.v.mouldus();//calculating the particles momentum
					cout.precision(4);//make the console print out values in four sig figs
					cout<<centurybounce<<" collisions have been done"<<" The kinetic energy and momentum of the particle is: "<<kineticenergy<<"and "<<momentum<<endl;
				}


		}

		test();
	return 0;


}


