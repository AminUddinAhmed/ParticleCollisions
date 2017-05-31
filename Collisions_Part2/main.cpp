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

	 float position = 100;
	 float radius = 1;
	 Vector v(2, 1);
	 Vector r(0, 0);
	 int collisions = 0;
	 srand(12345);

	 float minirandom = -99;
	 float maxirandom = 198;

	 float therandom = minirandom + maxirandom*float(std::rand())/RAND_MAX;
	 r.x = therandom;
	 therandom = minirandom + maxirandom*float(std::rand())/RAND_MAX;
	 r.y = therandom;
	 cout<<"The initial position is: "<<"("<<r.x<< ", " <<r.y<< ")" << endl;


	 float minirandomvel = -10;
	 float maxirandomvel = 20;

	 float randomvel = minirandomvel + maxirandomvel*float(std::rand())/RAND_MAX;
	 v.x = randomvel;
	 randomvel = minirandomvel + maxirandomvel*float(std::rand())/RAND_MAX;
	 v.y = randomvel;
	 cout<<"The initial velocity is: "<<"("<<v.x<< ", " <<v.y<< ")" << endl;

	 float timetoXwall = 0;
	 float timetoYwall = 0;

	 float Xpositime = timeToWall(r, v, XWALL, position - radius);
	 cout<<"Time until first collision with positive XWALL: "<<Xpositime<<endl;

	 position = -100;
	 float Xnegatime = timeToWall(r, v, XWALL, position - radius);
	 cout<<"Time until first collision with negative XWALL: "<<Xnegatime<<endl;

	 timetoXwall = Xpositime;
	 cout<<"Time to reach the XWALL is: " <<timetoXwall<<endl;



	 float Ypositime = timeToWall(r, v, YWALL, position - radius);
	 cout<<"Time until first collision with positive YWALL: "<<Ypositime<<endl;

	 position = -100;
	 float Ynegatime = timeToWall(r, v, YWALL, position - radius);
	 cout<<"Time until first collision with negative YWALL: "<<Ynegatime<<endl;

	 timetoYwall = Ypositime;
	 cout<<"Time to reach the YWALL is: " <<timetoYwall<<endl;


	 int bouncytimes = 1000;
	 int centurybounce = 0;

	 for(int i = 0; i<bouncytimes;i++){
	 	if(timetoXwall<=0 and timetoYwall<=0){
	 		cout<<"Oh noes!! The particle wont do the bouncy. Error :("<<endl;
	 		exit(0);
	 	}

	 	if (timetoXwall>0 and abs(timetoYwall) < abs(timetoYwall)){
	 		move(r, v,timetoXwall);
	 		wallCollision(v,XWALL);
	 		timetoYwall = timetoYwall-timetoXwall;
	 	}

	 	if(v.x > 0){
	 			position = 100;
	 			timetoXwall = timeToWall(r, v,XWALL,position-radius);
	 		}else if (v.y > 0){
	 			timetoYwall = timeToWall(r, v,YWALL,position-radius);
	 		}else if (v.x < 0){
	 			position = -100;
	 			timetoXwall = timeToWall(r, v,XWALL,position-radius);
	 		}else if(v.y <0){
	 			timetoYwall = timeToWall(r, v,YWALL,position-radius);
	 		}else if (v.x ==0){
	 			cout<<"The particle stopped, no more collidings"<<endl;
	 			timetoXwall = timeToWall(r, v,XWALL,position-radius);
	 			timetoYwall = timeToWall(r, v,YWALL,position-radius);
	 		}

		collisions ++;
		if (collisions % 100==0){//checking if particle has collided the next hundredth bounce, should be no remainder
			centurybounce+=100;//adding a hundred to the bouncecounter if above condition met
			float mass = 1;//the particles mass is 1
			float velosquared = v.mouldusSqr();//calculating the particles speed
			float kineticenergy = (float(1)/2)*mass*velosquared;//calculating the particles kinetic energy
			float momentum = mass*v.mouldus();//calculating the particles momentum
			cout.precision(4);//make the console print out values in four sig figs
			cout<<centurybounce<<" collisions have been done, "<<" the particles kinetic energy and momentum is: "<<kineticenergy<<" and "<<momentum<<" "<<"respectively"<<endl;
		}

	 }


	 return 0;


}


