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

void test() {


	Vector mod1(3, 4);
	float mouldusSquare = mod1.mouldusSqr();//uses mouldussquare member function to calculate the modulus squared of mod1
	printTest("Modulus Sqr Test", mouldusSquare, 25);


	Vector mod2(3, 4);
	float modtest1 = mod2.mouldus();//uses mouldus member function to calculate the modulus of mod2
	printTest("Modulus Test 1", modtest1, 5);


	Vector mod3(-3, 4);
	float modtest2 = mod3.mouldus();//uses mouldus member function to calculate the modulus of mod3
	printTest("Modulus Test 2", modtest2, 5);


	Vector rA(1, 1);
	Vector rB(4, 5);

	float howfaraway = rA.distance(rB);//uses distance member function to calculate the distance between rA and rB
	printTest("Distance Test", howfaraway, 5);


	Vector dotv1(1, 1);
	Vector dotv2(-1, 1);

	float dot1 = dotv1.dotProduct(dotv2);//uses dotproduct member function to calculate the dotproduct of dotv1 and dotv2
	printTest("dotproduct perpendicular test", dot1, 0);


	Vector dotv3(3, 4);
	Vector dotv4(6, 8);

	float dot2 = dotv3.dotProduct(dotv4);//uses dotproduct member function to calculate the dotproduct of dotv3 and dotv4
	printTest("dotproduct collinear test", dot2, 50);


	Vector dotv5(3, 0);
	Vector dotv6(3, 4);

	float dot3 = dotv5.dotProduct(dotv6);//uses dotproduct member function to calculate the dotproduct of dotv5 and dotv6
	printTest("dotproduct test 3", dot3, 9);


	Vector pos1(0, 0);
	Vector vel1(1, 0.5);
	float tim1 = 10;

	move(pos1, vel1, tim1);
	printTest("move test x", pos1.x, 10);
	printTest("move test y", pos1.y, 5);


	Vector r1(0, 0);
	Vector v1(1, 0);

	float posidion1 = 100;
	Wall_e xwall1(XWALL);
	float time1 = timeToWall(r1, v1, xwall1 ,posidion1);
	printTest("timetowall test 1", time1, 100);


	Vector r2(0, 0);
	Vector v2(1, 0);

	float posidion2 = -100;
	Wall_e xwall2(XWALL);
	float time2 = timeToWall(r2, v2, xwall2 ,posidion2);
	printTest("timetowall test 2", time2, -100);


	Vector r3(0, 0);
	Vector v3(1, 0);

	float posidion3 = -100;
	Wall_e ywall1(XWALL);
	float time3 = timeToWall(r3, v3, ywall1 ,posidion3);
	printTest("timetowall test 3", time3, -999);


	Vector r(0, 0);
	Vector v(1, 0);

	float position = 100;
	float radius = 1;

	float time = timeToWall(r, v, XWALL, (position-radius));
	move(r, v, time);
	wallCollision(v, XWALL);


	position = -100;
	time = timeToWall(r, v, XWALL, (position-radius));
	move(r, v, time);
	wallCollision(v, XWALL);
	printTest("collision1", v.x, 1);
}


void printTest(const std::string &message, float value, float test) {
	float delta = 0.0000001;//maximum difference between values calculated by program, and the actual value
	cout << message << " ";
	if (abs(value - test) < delta) {//checking if difference is less then delta
		cout << "PASSED" << endl;//passes if difference is less then delta
	} else {
		cout << "FAILED : " << value << " " << test << " " << delta << endl;//passes if difference is more then delta
	}

}
