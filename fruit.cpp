#include <graphics.h>
#include<cmath>

#include "fruit.hpp"
#include "object.hpp"

Fruit::Fruit(int _x, int _y, int _radius, int _color): Object(_x, _y, _color), radius(_radius) {}

int Fruit::getX() const { return x; }
int Fruit::getY() const { return y; }
int Fruit::getR() const { return radius; }

void Fruit::set(int _x, int _y, int _radius, int _color, int _dx, int _dy)
{
	x = _x;
	y = _y;
	radius = _radius;
	color = _color;
	dx = _dx;
	dy = _dy;
}

void Fruit::draw() const
{
	setcolor(color);
	setfillstyle(SOLID_FILL, color);
    fillellipse(x, y, radius, radius);
}

void Fruit::undraw() const
{
	setcolor(BLACK);
	setfillstyle(SOLID_FILL, BLACK);
    fillellipse(x, y, radius, radius);
}