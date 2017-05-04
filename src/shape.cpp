#include "shape.h"
#include "screen.h"
#include <math.h>

//shape_lst shape_list;

rectangle::rectangle(point a, point b) {
	if (a.x <= b.x) {
		if (a.y <= b.y) {
			sw = a;
			ne = b;
		}
		else {
			sw = point(a.x, b.y);
			ne = point(b.x, a.y);
		}
	}
	else {
		if (a.y <= b.y) {
			sw = point(b.x, a.y);
			ne = point(a.x, b.y);
		}
		else {
			sw = b;
			ne = a;
		}
	}
}

rectangle::rectangle(point a, point b, char _color) {
	this->color = _color;
	if (a.x <= b.x) {
		if (a.y <= b.y) {
			sw = a;
			ne = b;
		}
		else {
			sw = point(a.x, b.y);
			ne = point(b.x, a.y);
		}
	}
	else {
		if (a.y <= b.y) {
			sw = point(b.x, a.y);
			ne = point(a.x, b.y);
		}
		else {
			sw = b;
			ne = a;
		}
	}
}

tringle::tringle(point t1, point t2, point t3)
{
	n = t1;
	w = t2;
	e = t3;

}

ellipse::ellipse(double r1 , double r2, point _sw)
{

	a = r1;
	b = r2;
	pos = new rectangle(point(_sw.x - a, _sw.y - a), point(_sw.x + a, _sw.y + a), '*');

	for (double rad = 0; rad < 2*M_PI; rad += 0.1*M_PI) {
		double x = a * cos(rad) + _sw.x;
		double y = a * sin(rad) + _sw.y;
		ni.push_back(point(x, y));

	}

}

void ellipse::draw()
{
	point begin = ni.back();
	ni.pop_back();
	point end = begin;
	//point tmp;
	//while(!ni.empty()) {
	//	tmp = ni.back();
	//	put_line(end, tmp);
	//	
	//	end = tmp;
	//	ni.pop_back();
	//}

//	for (auto i : ni) {
//		put_line(end, i);
//		end = i;
//	}

	for(std::vector<point>::iterator it = ni.begin() ; it != ni.end(); ++it){
		put_line(end, *it);
		end = *it;
	}
//
//	for (std::vector<point>::iterator it = ni.begin() ; it != ni.end(); ++it)
//	    std::cout << ' ' << *it;

	put_line(end, begin);

}


//char rectangle::color = '+';
void rectangle::draw()
{
	/*
	nw ---- n ---- ne
	|               |
	|               |
	w       m       e
	|               |
	|               |
	sw ---- s ---- se
	*/
    point nw(sw.x, ne.y);
    point se(ne.x, sw.y);
    put_line(nw,ne, color);
    put_line(ne,se, color);
    put_line(se,sw, color);
    put_line(sw,nw, color);
}

void tringle::draw()
{
	/*
	nw ---- n ---- ne
	|     /   \     |
	|   /       \   |
	w /     m     \ e
	------------------

	sw ---- s ---- se
	*/
    put_line(n,e);
    put_line(e,w);
    put_line(w,n);
}


shape* shape::list = new shape();
void shape_refresh()
{
    screen_clear();

	//shape* p = shape::list;
	//while (p = p->next) p->draw(); 

	for (shape* p = shape::list; p; p=p->next) p->draw();

    screen_refresh();
}
/*
nw ---- n ---- ne
|               |
|               |
w       m       e
|               |
|               |
sw ---- s ---- se
*/
void stack(shape* down_mov, shape* up) // put p on top of q
{
	static int delt = 1;
    point n_up = up->north();
    point s_down = down_mov->south();
	down_mov->move(n_up.x - s_down.x , n_up.y - s_down.y );
	//down_mov->move(delt % 2 ? 2 : -2, delt % 2 ? 3 : -3);
	delt++ ;
}

void stackWE(shape* down_mov, shape* up) // put p on top of q
{
	static int delt = 1;
	point n_up = up->east();
	point s_down = down_mov->west();
	down_mov->move(n_up.x - s_down.x, n_up.y - s_down.y);
	//down_mov->move(delt % 2 ? 2 : -2, delt % 2 ? 3 : -3);
	delt++;
}
