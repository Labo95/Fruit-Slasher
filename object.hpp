#ifndef OBJECT_H
#define OBJECT_H

class Object
{
protected:
	int x, y;
	int dx, dy;
	int color;
	
public:
	Object(int _x = 0, int _y = 0, int _color = 0);
	void setLocation(int _x, int _y);
	void setCol(int c);

	int getX() const;
	int getY() const;
	int getCol() const;
    
    int left() const;
	int right() const;
	int top() const;
	int bottom() const;

    void reverseX();
	void reverseY();

    void setMovement(int _dx, int _dy);

	void setRandomMovement();
    void bounce(int mx, int my);
	
	void move();
};

#endif