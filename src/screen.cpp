#include "screen.h"
#include <iostream>

using namespace std;

char screen[XMAX][YMAX];

void screen_init()
{
    for (int y = 0; y < YMAX; y++)
	for (int x=0; x < XMAX; x++)
	    screen[x][y] = white;
}

inline int on_screen(int a, int b)
{
    return 0 <= a && a < XMAX && 0 <= b && b < YMAX;
}

void put_point(int a, int b)
{
    if (on_screen(a,b)) screen[a][b] = black;
}

void put_point(int a, int b, char color)
{
	if (on_screen(a, b)) screen[a][b] = color;
}

void screen_clear()
{
     screen_init();
}

void screen_refresh() {
	for (int y = YMAX - 1; 0 <= y; y--) {
		for (int x = 0; x < XMAX; x++)
			cout << screen[x][y];
		cout << endl;

	}
}

void screen_end() { }
