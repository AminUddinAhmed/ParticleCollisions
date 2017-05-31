/*
 * functions.hpp
 *
 *  Created on: 2 Mar 2015
 *      Author: ap14080
 */

#ifndef FUNCTIONS_HPP_
#include "Vector.hpp"
#include "Walls.hpp"
#define FUNCTIONS_HPP_

float mouldusSqr(const Vector &v);
float mouldus (const Vector &v);
float distance (const Vector &r1, const Vector &r2);
float dotProduct (const Vector &v1, const Vector &v2);
void move (Vector &r, const Vector &v, float time);
float timeToWall (const Vector &r, const Vector &v, Wall_e wall, float position);

#endif /* FUNCTIONS_HPP_ */


/*
float a = 100;
float *b = &a;
float c = *b;

cout << c << endl;



int main();
float *pointer1;
{float pointer2 = new float;
*pointer2 = 100;
pointer1 = pointer2;
*pointer2 = 200;
}
cout << pointer1 << endl;
delete pointer1;
}

*/
