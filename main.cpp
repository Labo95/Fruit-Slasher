// ? Group project  Example of Starter Project or Codebase

// Programming Technique II
// Semester 1, 2021/2022

#include <graphics.h>

#include "game.hpp"

using namespace std;

//! Choose the debug mode "Multi-File Graphic Project" to run this program.
//! Only one main.cpp file should be available. If not using it, move the main file the folder "mains"

//! Example testing the class:
//! description: This testing is to show the bombs fall down

int main()
{
	initwindow(getmaxwidth(), getmaxheight(), "Fruit Slasher");

	readimagefile("Image/f2.jpg", 0, 0, getmaxwidth(), getmaxheight());
	
	char ab = 0;

	while (ab != 27)  // 27 is ESC key
	{
		setcolor(12);
		settextstyle(BOLD_FONT, HORIZ_DIR, 10);
		bgiout << "Fruit Slasher";
		outstreamxy(300, getmaxheight() / 2 - 200);

		setcolor(15);
		settextstyle(SIMPLEX_FONT, HORIZ_DIR, 7);
		bgiout << "Press any key to play the game";
		outstreamxy(200, getmaxheight() / 2 - 50);

		if (kbhit())
		{
			closegraph();
			game();
		}
	}

	return 0;
}