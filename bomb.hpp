#ifndef BOMB_H
#define BOMB_H

#include "object.hpp"

class Bomb : public Object
{
protected:
    int width, height;

public:
    Bomb(int _x = 0, int _y = 0, int _width = 0, int _height = 0, int _color = 0);

	void draw() const;
	void undraw() const;

    int getX() const;
	int getY() const;
    int getW() const;
    int getH() const;
};

#endif