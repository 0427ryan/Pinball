#include "Board.h"
#define PI acos(-1)

void drawArc(MyVector center, float radius, int slice, float angle1 = 0, float angle2 = 360) {
	
	float step = (angle2 - angle1) / slice;
	glBegin(GL_LINE_STRIP);
	for (int i = 0; i <= slice; i++) {
		float theta = (step * i + angle1) * (PI / 180);
		glVertex3f(center.x + cos(theta) * radius, center.y + sin(theta) * radius, 0);
	}
	glEnd();
}

void Board::step() {
	
	this->ball.setLocation(ball.getLocation() + ball.getSpeed());
	for (auto o : ov) {
		if (o->isBump(&ball)) {
			do_reflect(&ball, o);
			this->ball.setLocation(ball.getLocation() + ball.getSpeed());
			this->ball.setSpeed(ball.getSpeed() * decrease);
		}
	}

	for (int i = 0; i < 7 ; i++) {
		if (border[i].isBump(&ball)) {
			border[i].reflect(&ball);
			this->ball.setLocation(ball.getLocation() + ball.getSpeed());
			this->ball.setSpeed(ball.getSpeed() * decrease);
		}
	}

	if (left_panel.isBump(&ball)) {
		left_panel.reflect(&ball);
		this->ball.setLocation(ball.getLocation() + ball.getSpeed());
		this->ball.setSpeed(ball.getSpeed() * decrease);
	}

	if (right_panel.isBump(&ball)) {
		right_panel.reflect(&ball);
		this->ball.setLocation(ball.getLocation() + ball.getSpeed());
		this->ball.setSpeed(ball.getSpeed() * decrease);
	}

	this->ball.setSpeed(ball.getSpeed() + gravity);
}

void kick() {
	
}

void drawBoard(Board* b) {
	glColor3f(0, 0, 1.0);
	glBegin(GL_LINES);
	for (auto &&i : b->border) {
		glVertex3d(i.v1.x, i.v1.y, 0);
		glVertex3d(i.v2.x, i.v2.y, 0);
	}
	glEnd();
	for (auto o : b->ov) {
		drawObstacle(o);
	}
	glColor3f(1, 0, 0);
	drawPanel(&(b->left_panel));
	drawPanel(&(b->right_panel));
}

void drawPanel(Panel* p) {
	glColor3f(1, 1, 0);
	glBegin(GL_LINES);
	Line l = p->getLine();
	glVertex3f(l.v1.x, l.v1.y, 0);
	glVertex3f(l.v2.x, l.v2.y, 0);
	glEnd();
}

void drawObstacle(Obstacle* o) {
	glColor3f(1, 0, 0);
	drawArc(o->getLocation(), o->getRadius(), 10);
}

void drawBall(Ball* b) {
	glColor3f(0, 1, 1);
	drawArc(b->getLocation(), b->getRadius(), 10);
}

void Board::kickRight() {
	if (right_panel.isCatch(&ball)) {
		right_panel.kick(&ball);
	}
}

void Board::kickLeft() {
	if (left_panel.isCatch(&ball)) {
		left_panel.kick(&ball);
	}
}