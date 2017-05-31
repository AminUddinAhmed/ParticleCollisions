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

using std::endl;
using std::cout;
using std::abs;

void test() {

	//many vectors and floats are declared, in their respective tests

	Vector modulus;
	modulus.x = 3;
	modulus.y = 4;

	float mod2 = mouldusSqr(modulus);//calls function to calculate modulus squared of mod2

	printTest("Modulus Sqr Test", mod2, 25);

	float mod3 = mouldus(modulus);//calls function to calculate the root of modulus squared of mod2

	printTest("Modulus Test 1", mod3, 5);

	Vector vel2;
	vel2.x = -3;
	vel2.y = 4;

	float mod4 = mouldus(vel2);//finds modulus of mod4

	printTest("Modulus Test 2", mod4, 5);


	Vector rA;
	rA.x = 1;
	rA.y = 1;

	Vector rB;
	rB.x = 4;
	rB.y = 5;


	float howfaraway = distance(rA, rB);//finds how far rA is from rB

	printTest("Distance Test", howfaraway, 5);

	Vector dotv1;
	dotv1.x = 1;
	dotv1.y = 1;

	Vector dotv2;
	dotv2.x = -1;
	dotv2.y = 1;

	float dot1 = dotProduct(dotv1, dotv2);//calls function to calculate dotproduct of vectors dotv1 and dotv2

	printTest("dotproduct perpendicular test", dot1, 0);

	Vector dotv3;
	dotv3.x = 3;
	dotv3.y = 4;
	Vector dotv4;
	dotv4.x = 6;
	dotv4.y = 8;

	float dot2 = dotProduct(dotv3, dotv4);//calls function to calculate dotproduct of vectors dotv3 and dotv4

	printTest("dotproduct collinear test", dot2, 50);

	Vector dotv5;
	dotv5.x = 3;
	dotv5.y = 0;
	Vector dotv6;
	dotv6.x = 3;
	dotv6.y = 4;

	float dot3 = dotProduct(dotv5, dotv6);//calls function to calculate dotproduct of vectors dotv5 and dotv6

	printTest("dotproduct collinear test", dot3, 9);

	Vector pos1;
	pos1.x = 0;
	pos1.y = 0;
	Vector vel1;
	vel1.x = 1;
	vel1.y = 0.5;

	float time = 10;//setting time to 10 for moving


	move(pos1, vel1, time);//calling the move function

	printTest("move test x", pos1.x, 10);
	printTest("move test y", pos1.y, 5);

	Vector r1;
	r1.x = 0;
	r1.y = 0;
	Vector v1;
	v1.x = 1;
	v1.y = 0;

	float posidion1 = 100;//wall location

	Wall_e xwall1(XWALL);

	float time1 = timeToWall(r1, v1, xwall1 ,posidion1);//Calls the timeToWall function, calculates the time taken by particle to move toward the positive XWALL

	printTest("timetowall test 1", time1, 100);


	Vector r2;
	r2.x = 0;
	r2.y = 0;
	Vector v2;
	v2.x = 1;
	v2.y = 0;


	float posidion2 = -100;//wall location
	Wall_e xwall2(XWALL);

	float time2 = timeToWall(r2, v2, xwall2 ,posidion2);//Calls the timeToWall function, calculates the time taken by particle to move toward the negative XWALL

	printTest("timetowall test 2", time2, -100);



	Vector r3;
	r3.x = 0;
	r3.y = 0;
	Vector v3;
	v3.x = 1;
	v3.y = 0;


	float posidion3 = -100;//wall location
	Wall_e ywall1(XWALL);

	float time3 = timeToWall(r3, v3, ywall1 ,posidion3);//Calls the timeToWall function, calculates the time taken by particle to move toward the negative yWALL

	printTest("timetowall test 3", time3, -100);


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
