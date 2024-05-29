#ifndef PLAYER_H
#define PLAYER_H

#include "bomb.hpp"
#include "fruit.hpp"

class Player
{
private:
    int x, y;
    int size;
    int color;
    int speed;

    Fruit f;
    Bomb *r;

    void _draw(int _color) const;
    
public:
    Player(int _x, int _y, int _size, int _color, int _speed);
    Player();

    void draw() const;
    void undraw() const;

    void movePlayer(int mx, int my);

	bool collide(const Fruit &f) const;
	bool collide(const Bomb *r) const;
};

#endif