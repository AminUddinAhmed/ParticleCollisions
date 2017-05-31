/*
 * test.cpp
 *
 *  Created on: 3 Mar 2015
 *      Author: ap14080
 */

#include "test.hpp"
#include "Walls.hpp"
#include "functions.hpp"
#include <iostream>
#include <cmath>
#include <string>
#include "Vector.hpp"

using std::cin;
using std::cout;
using std::endl;
using std::abs;

void test(){


Vector mod1(3, 4);
float mouldusSquare = mod1.mouldusSqr();
printTest("Modulus Sqr Test", mouldusSquare, 25);


Vector mod2(3, 4);
float modtest1 = mod2.mouldus();
printTest("Modulus Test 1", modtest1, 5);


Vector mod3(-3, 4);
float modtest2 = mod3.mouldus();
printTest("Modulus Test 2", modtest2, 5);

Vector rA(1, 1);
Vector rB(4, 5);

float howfaraway = rA.distance(rB);
printTest("Distance Test", howfaraway, 5);

Vector dotv1(1, 1);
Vector dotv2(-1, 1);

float dot1 = dotv1.dotProduct(dotv2);
printTest("dotproduct perpendicular test", dot1, 0);


Vector dotv3(3, 4);
Vector dotv4(6, 8);

float dot2 = dotv3.dotProduct(dotv4);
printTest("dotproduct collinear test", dot2, 50);


Vector dotv5(3, 0);
Vector dotv6(3, 4);

float dot3 = dotv5.dotProduct(dotv6);
printTest("dotproduct test 3", dot3, 9);

Vector pos1(0, 0);
Vector vel1(1, 0.5);
Particle part1(1,pos1,vel1);

part1.move(10);
printTest("move test x", part1.r.x, 10);
printTest("move test y", part1.r.y, 5);



Vector r1(0, 0);
Vector v1(1, 0);
Particle part2(0,r1,v1);

float posidion1 = 100;
Wall_e xwall1(XWALL);
float time1 = part2.timeToWallCollision(r1, v1, xwall1,posidion1);
printTest("timetowall test 1", time1, 100);


Vector r2(0, 0);
Vector v2(1, 0);
Particle part3(0, r2, v2);

float posidion2 = -100;
Wall_e xwall2(XWALL);
float time2 = part3.timeToWallCollision(r2, v2, xwall2, posidion2);
printTest("timeToWall test 2", time2, FLT_MAX);


Vector r3(0, 0);
Vector v3(1, 0);
Particle part4(0, r3, v3);

float posidion3 = -100;
Wall_e ywall1 = YWALL;
float time3 = part4.timeToWallCollision(r3, v3, ywall1, posidion3);
printTest("timeToWall test 3", time3, FLT_MAX);


Vector r4;
Vector v4(1,0);
Particle part5(0, r4, v4);

float time4 = setParticleWallCollisionTime(part5 ,100);
part5.move(time4);//Calls the void move function. This will change the current position vector of the particle accordingly.
part5.wallCollision();
printTest("collision 1", part5.v.x, -1);
float time5 = setParticleWallCollisionTime(part5, 100.0);
part5.move(time5);//Calls the void move function. This will change the current position vector of the particle accordingly.
part5.wallCollision();//Cause the velocity of the particle to change sign, due to the elastic collision w. the walls, again.
printTest("collision 2", part5.v.x, 1);
printTest("collision 3", part5.v.y, 0);
}

void printTest(const std::string &message, float value, float test) {
	float delta = 0.0000001;
	cout << message << " ";
	if (abs(value - test) < delta) {
		cout << "PASSED" << endl;
	} else {
		cout << "FAILED : " << value << " " << test << " " << delta << endl;
	}

}
