#include "screen.h"

void put_line(point a, point b)
{
    put_line(a.x, a.y, b.x, b.y);
}

void put_line(int x0, int y0, int x1, int y1)
{
    int dx = 1;
    int a = x1 - x0;
    if (a < 0) dx = -1, a = -a;
    int dy = 1;
    int b = y1 - y0;
    if (b < 0) dy = -1, b = -b;
    int two_a = 2 * a;
    int two_b = 2 * b;
    int xcrit = -b + two_a;
    int eps = 0;
    for (;;)
	{
		put_point(x0, y0);
		if (x0 == x1 && y0 == y1) break;
		if (eps <= xcrit)      x0 += dx, eps += two_b;
		if (eps>= a || a <= b) y0 += dy, eps -= two_a;
	}
}

void put_line(point a, point b, char color)
{
	put_line(a.x, a.y, b.x, b.y, color);
}

void put_line(int x0, int y0, int x1, int y1, char color)
{
	int dx = 1;
	int a = x1 - x0;
	if (a < 0) dx = -1, a = -a;
	int dy = 1;
	int b = y1 - y0;
	if (b < 0) dy = -1, b = -b;
	int two_a = 2 * a;
	int two_b = 2 * b;
	int xcrit = -b + two_a;
	int eps = 0;
	for (;;)
	{
		put_point(x0, y0, color);
		if (x0 == x1 && y0 == y1) break;
		if (eps <= xcrit)      x0 += dx, eps += two_b;
		if (eps >= a || a <= b) y0 += dy, eps -= two_a;
	}
}
