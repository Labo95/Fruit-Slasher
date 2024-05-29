#include <graphics.h>
#include "object.hpp"

Object::Object(int _x, int _y, int _color) : x(_x), y(_y), color(_color) {}

void Object::setLocation(int _x, int _y)
{
	x = _x;
	y = _y;
}

void Object::setCol(int c) { color = c; }

int Object::getX() const { return x; }
int Object::getY() const { return y; }
int Object::getCol() const{ return color; }

int Object::left() const {return x - 25;}
int Object::right() const {return x + 25;}
int Object::top() const {return y - 25;}
int Object::bottom() const {return y + 25;}

void Object::reverseX() {dx = -dx;}
void Object::reverseY() {dy = -dy;}

void Object::setMovement(int _dx, int _dy)
{
	dx = _dx;
	dy = _dy;
}

void Object::setRandomMovement()
{
	int dirX = rand() % 2 ? -1 : 1;
	int dirY = rand() % 2 ? -1 : 1;
	setMovement(dirX * (rand() % 30), dirY * (rand() % 30));
}

void Object::bounce(int mx, int my)
{
	if((left() < 0) || (right() > mx))
		reverseX();
	if((top() < 0) || (bottom() > my))
		reverseY();
}

void Object::move()
{
    x += dx;
    y += dy;
}