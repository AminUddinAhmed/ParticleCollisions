/*
 * Vector.hpp
 *
 *  Created on: 2 Mar 2015
 *      Author: ap14080
 */

#ifndef VECTOR_HPP_
#define VECTOR_HPP_
#include<cmath>


class Vector {
public:
	Vector(float a = 0, float b = 0) : x(a), y(b) {;}
	~Vector() {;}

	float x;
	float y;

	Vector operator+(const Vector &a){
		Vector answer(*this);
		answer.x += a.x;
		answer.y += a.y;
		return answer;
	}

	Vector operator-(const Vector &b){
		Vector answer(*this);
		answer.x -= b.x;
		answer.y -= b.y;
		return answer;
	}

	Vector operator-(){
		Vector answer;
		answer.x = -x;
		answer.y = -y;
		return answer;
	}


	float mouldusSqr() const{
		return(x*x) + (y*y);
	}

	float mouldus() const{
		return sqrt((x*x) + (y*y));
	}

	float dotProduct(const Vector &v){
		Vector answer(*this);
		return (v.x*answer.x)+(v.y*answer.y);
	}

	float distance(Vector &v){
		Vector answer(*this);
		answer = answer.operator -(v);
		return answer.mouldus();
	}

};



#endif /* VECTOR_HPP_ */
