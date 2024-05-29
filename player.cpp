#include <graphics.h>
#include <cmath>

#include "player.hpp"
#include "bomb.hpp"
#include "fruit.hpp"

Player::Player(int _x, int _y, int _size, int _color, int _speed)
        : x(_x), y(_y), size(_size), color(_color), speed(_speed) {}
Player::Player() : Player(0, 0, 0, 0, 0) {}

void Player::_draw(int _color) const
{
    setcolor(_color);
    circle(x, y, size);
}

void Player::draw() const { _draw(color); }
void Player::undraw() const { _draw(BLACK); }

void Player::movePlayer(int mx, int my)
{
	undraw();
	x = mx, y = my;
	draw();
}

bool Player::collide(const Fruit &f) const
{
	bool value;
	double distance = sqrt(pow((f.getX() - x), 2) + pow((f.getY() - y), 2));
	double sumR = f.getR() + size;

	if (distance <= sumR)
		value = true;
	else
		value = false;

	return value;
}

bool Player::collide(const Bomb *r) const
{
    bool b;

    if( (r->getX() <= x) && (x<= (r->getX()+ r->getW())) && (r->getY() <= y) && (y<= (r->getY() + r->getH())) )
	{
        b = true;
    }
	else { b = false; }

    return b;
}