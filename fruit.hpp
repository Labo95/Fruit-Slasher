#ifndef FRUIT_H
#define FRUIT_H

#include "object.hpp"

class Fruit : public Object
{
private:
	int radius;

public:
    Fruit(int _x = 0, int _y = 0, int _radius = 0, int _color = 0);

    int getX() const;
	int getY() const;
	int getR() const;

    void set(int _x, int _y, int _radius, int _color, int _dx, int _dy);

	void draw() const;
	void undraw() const;
};

#endif