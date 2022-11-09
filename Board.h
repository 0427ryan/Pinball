#pragma once

#include <math.h>
#include <vector>
#include "ball.h"
#include "Obstacle.h"
#include "Panel.h"
#include "util.h"
#include "Include/freeglut.h"
#include "Line.h"

class Board
{
public:
	Board() {
		this->ball.setLocation({ 380, 300 });
		this->ball.setRadius(10);
		this->ball.setSpeed({ 0, 0 });

		this->ov.push_back(new Obstacle(200, 200, 10));
		this->ov.push_back(new Obstacle(200, 400, 10));
		this->ov.push_back(new Obstacle(250, 300, 10));
		this->ov.push_back(new Obstacle(300, 400, 10));
		this->ov.push_back(new Obstacle(300, 200, 10));
	}

	~Board() {
		for (auto o : ov) {
			delete o;
		}
	}

	Ball ball;
	MyVector gravity = { 0, -0.1 };
	float decrease = 0.8;

	Panel left_panel = { {{200, 50}, {240, 40}}, 20 , 0.8, COUNTERCLOCKWISE };
	Panel right_panel = { {{300, 50}, {260, 40}}, 20 , 0.8, CLOCKWISE};
	std::vector<Obstacle*> ov;
	Line border[7] = {
		{ {300, 50},{400, 100}},
		{ {400, 100},{400, 400}},
		{ {400, 400},{300, 500}},
		{ {300, 500},{200, 500}},
		{ {200, 500},{100, 400}},
		{ {100, 400},{100, 100}},
		{ {100, 100},{200, 50} }
	};

	void step();

	void addObstacle(Obstacle* o) {
		this->ov.push_back(o);
	}
	void kickRight();
	void kickLeft();
};

void drawBoard(Board* b);


void drawBall(Ball* b);
void drawPanel(Panel* p);
void drawObstacle(Obstacle* o);
