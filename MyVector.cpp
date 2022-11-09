#include "MyVector.h"
#include <cmath>

MyVector::MyVector(std::initializer_list<float> list) {
	this->x = *list.begin();
	this->y = *(list.begin() + 1);
}

float MyVector::cross(MyVector v) {
	return this->x * v.x + this->y * v.y;
}

float MyVector::cosine() {
	return this->normalize().x;
}

float MyVector::sine() {
	return this->normalize().y;
}

MyVector MyVector::normalize() {
	float length = sqrt(cross(*this));
	return { x / length, y / length };
}

MyVector MyVector::rotate(MyVector v) {
	v = v.normalize();
	return {
		this->x * v.x - this->y * v.y,
		this->x * v.y + this->y * v.x
	};
}

MyVector MyVector::mirror(MyVector v) {
	v = v.normalize();
	v = { 1 - 2 * v.x * v.x, 2 * v.x * v.y };
	return {
		this->x * v.x + this->y * v.y,
		this->x * v.y - this->y * v.x
	};
}

float MyVector::length() {
	return sqrt(this->cross(*this));
}

MyVector MyVector::operator+ (MyVector v) {
	return { this->x + v.x, this->y - v.y };
}

MyVector MyVector::operator-(MyVector v) {
	return { this->x - v.x, this->y - v.y };
}

MyVector MyVector::operator*(float f) {
	return { this->x * f, this->y * f };
}

MyVector MyVector::operator/(float f) {
	return { this->x / f, this->y / f };
}

float MyVector::l2d_distance(MyVector v) {
	return abs(this->normalize().rotate({ 0, 1 }).cross(v));
}