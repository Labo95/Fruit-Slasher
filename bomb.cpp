#include <graphics.h>

#include "object.hpp"
#include "bomb.hpp"

Bomb::Bomb(int _x, int _y,  int _width, int _height, int _color) : Object(_x, _y, _color), width(_width), height(_height) {}

void Bomb::draw() const
{
	setcolor(color);
    setfillstyle(SOLID_FILL, color);
    bar(x, y, x + width, y + height);
}

void Bomb::undraw() const
{
	setcolor(BLACK);
    setfillstyle(SOLID_FILL, BLACK);
    bar(x, y, x + width, y + height);
}


int Bomb::getX() const { return x; }
int Bomb::getY() const { return y; }
int Bomb::getW() const { return width; }
int Bomb::getH() const { return height; }