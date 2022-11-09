#pragma once
#include <initializer_list>


class MyVector
{

public:

	float x = 0;
	float y = 0;

	MyVector() = default;
	MyVector(float x, float y) :x(x), y(y) {};
	MyVector(std::initializer_list<float> list);
	
	float cross(MyVector v);
	float length();
	float cosine();
	float sine();
	MyVector normalize();
	MyVector rotate(MyVector v);
	MyVector mirror(MyVector v);

	MyVector operator-(MyVector v);
	MyVector operator+(MyVector v);
	MyVector operator*(float f);
	MyVector operator/(float f);

	float l2d_distance(MyVector v);
};

