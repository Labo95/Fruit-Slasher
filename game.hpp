// ? Group project  Example of Starter Project or Codebase

// Programming Technique II
// Semester 1, 2021/2022
#include <graphics.h>
#include <cmath>
#include <stdlib.h>
#include <time.h>
#include <mmsystem.h>

#include "bomb.hpp"
#include "fruit.hpp"
#include "player.hpp"

using namespace std;

#define COUNT 20

int randX()
{
	int n = 50 + rand() % (getmaxwidth()-100);
	return n;
}

int randY()
{
	int n = 50 + rand() % (getmaxheight()-100);
	return n;
}

void game()
{
	int width = getmaxwidth();
	int height = getmaxheight();
	int random;
	int check = 0;
	int all = 0;

	initwindow(width, height, "Fruit Slasher");

	/* initialize random seed: */

	srand(time(NULL));

	Object *o[COUNT];
	Bomb bombs[COUNT];
	Fruit fruits[COUNT];
	Player player(width / 2, height - 100, 10, YELLOW, 75);

	for(int i = 0; i < COUNT; i++)
	{
		random = rand() % 10;

		if(random <= 6)
		{ 
			fruits[i] = Fruit(randX(), randY(), 30, GREEN);
			o[i] = &fruits[i];
			all++;
			continue;
		}

		else
		{
			bombs[i] = Bomb(randX(), randY(), 40, 40, RED);
			o[i] = &bombs[i];
			continue;
		}
	}

	for (int i = 0; i < COUNT; i++)
    	o[i]->setRandomMovement();
	
	char key = 0;

	while (true)
	{
		if (kbhit())
			key = getch();
		if (key == 27) // 27 ==ESC key
			break;

		POINT p;
		GetCursorPos(&p);
		player.movePlayer(p.x, p.y);

		for (int i = 0; i < COUNT; i++)
		{
			fruits[i].undraw();
			bombs[i].undraw();
			o[i]->bounce(width, height);
			o[i]->move();

			if(player.collide(&bombs[i]))
			{
				setcolor(WHITE);
				settextstyle(BOLD_FONT, HORIZ_DIR, 10);
				bgiout << "Game Over";
				outstreamxy(width / 2 - 270, height / 2 - 100);
				system("pause");
			}

			fruits[i].draw();
			bombs[i].draw();

			if(player.collide(fruits[i]))
			{
				fruits[i].undraw();
				fruits[i].set(0, 0, 0, 0, 0, 0);
				check++;
			}

			if(check == all)
			{
				setcolor(WHITE);
				settextstyle(BOLD_FONT, HORIZ_DIR, 10);
				bgiout << "You Won";
				outstreamxy(width / 2 - 280, height / 2 - 100);
				system("pause");
			}
		}
		delay(40);
	}
}