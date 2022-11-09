#pragma once

#include <algorithm>
#include <math.h>
#include "ball.h"
#include "Line.h"

enum dir {
	CLOCKWISE, COUNTERCLOCKWISE
};

class Panel
{
	Line l;
	
	
	float power;
	float cos;
public:
	bool isActive = false;
	dir direction;
	Panel() = default;
	Panel(Line l,
		float power,
		float cosine, dir direction) 
		:l(l), power(power),
		cos(cosine),
		direction(direction){};
	Line getLine() {
		if (not isActive) {
			return l;
		}
		MyVector v2;
		if (direction == CLOCKWISE) {
			v2 = (l.v2 - l.v1).rotate({ cos * cos, 1 });
		}
		else {
			v2 = (l.v2 - l.v1).rotate({ cos * cos, -1 });
		}
		Line l2 = { l.v1, l.v1 + v2 };
		return l2;
	};

	void kick(Ball* ball);
	bool isCatch(Ball* ball);
	bool isBump(Ball* ball);
	void reflect(Ball* ball);
};

