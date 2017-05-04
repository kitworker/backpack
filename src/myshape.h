#ifndef MYSHAPE_H
#define MYSHAPE_H

#include "shape.h"

class myshape : public rectangle
{
	line* l_eye;
	line* r_eye;
	line* mouth;

public:
	myshape(point, point);

	void draw();
	void move(int, int);
};
#endif

