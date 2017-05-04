#pragma once

#include "shape.h"
#include <iostream>

class tringle : public shape
{
	/*
	nw ---- n ---- ne
	|     /   \     |
	|   /       \   |
	w /     m     \ e
	------------------

	sw ---- s ---- se
	*/
	point n, w, e;


public:
	point north() { return n; }
	point west() { return w; }
	point east() { return e; }
	tringle(point, point, point);
	void draw();

};

class ellipse : public shape
{
	/*
	nw ---- n ---- |ne|
	|               |
	|               |
	w       m       e
	|               |
	|               |
	|sw|---- s ---- se
	*/
	std::vector<point> ni;
	double a, b;
	point sw, ne;
	rectangle *pos;

public:

	point north() { return pos->north(); }
	point neast() { return pos->neast(); }
	point east()  { return pos->east();  }
	point seast() { return pos->seast(); }
	point south() { return pos->south(); }
	point swest() { return pos->swest(); }
	point west()  { return pos->west();  }
	point nwest() { return pos->nwest(); }
	point middle(){ return pos->middle();}

	

	ellipse(double, double, point);
	void draw();

};