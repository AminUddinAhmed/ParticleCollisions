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


void move (Vector &r, const Vector &v, float time);
float timeToWall (const Vector &r, const Vector &v, Wall_e wall, float position);
void wallCollision (Vector &v, Wall_e wall);



#endif /* FUNCTIONS_HPP_ */

/*
 *
 *
float a = 100;
float *b = &a;
float c = *b;




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
