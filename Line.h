#pragma once

#include <math.h>
#include <algorithm>

#include "ball.h"
#include "MyVector.h"

class Line
{
public:
	MyVector v1, v2;
	Line() = default;
	Line(MyVector v1, MyVector v2) :v1(v1), v2(v2) {};
	bool isBump(Ball* b);
	void reflect(Ball* b);
	float length();
};

