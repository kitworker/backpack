#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "shape.h"
#include <vector>
#include <algorithm>


class rectangle : public shape
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
		point sw, ne;
		 char color;

	public:

		point north() { return point((sw.x + ne.x) / 2, ne.y); }
		point neast() { return ne; }
		point east()  { return point(ne.x, (sw.y + ne.y) / 2); }
		point seast() { return point(ne.x, sw.y); }
		point south() { return point((sw.x + ne.x) / 2, sw.y); }
		point swest() { return sw; }
		point west()  { return point(sw.x, (sw.y + ne.y) / 2); }
		point nwest() { return point(sw.x, ne.y); }
		point middle(){ return point((sw.x + ne.x) / 2, (sw.y + ne.y) / 2); }

		void move(int a, int b) { sw.x += a; sw.y += b; ne.x += a; ne.y += b; }
		void draw();

		rectangle(point, point);
		rectangle(point, point, char);
};



class MyClass: public  rectangle
{


	
public:

	line* l_eye;
	line* r_eye;
	line* mouth;

	MyClass(point a, point b) : rectangle(a, b){
	
		int ll = neast().x - swest().x + 1;
		int hh = neast().y - swest().y + 1;
		l_eye = new line(point(swest().x + 2, swest().y + hh * 3 / 4) , 2);
		r_eye = new line(point(swest().x + ll - 4, swest().y + hh * 3 / 4), 2);
		mouth = new line(point(swest().x + 2, swest().y + hh / 4) , ll - 4);
	};
	
	void draw()
	{
		rectangle::draw();
		put_point(point((swest().x + neast().x) / 2, (swest().y + neast().y) / 2));
	
	}



	void move(int a, int b)
	{
		rectangle::move(a, b);
		l_eye->move(a, b);
		r_eye->move(a, b);
		mouth->move(a, b);	
	}



private:

};

class Bee : public  MyClass
{
	std::vector<line*> del;
public:
	Bee(point a, point b) :MyClass(a, b){

	/*	int ll = neast().x - swest().x + 1;
		int hh = neast().y - swest().y + 1;
		l_eye = new line(point(swest().x + 2, swest().y + hh * 3 / 4), 2);
		r_eye = new line(point(swest().x + ll - 4, swest().y + hh * 3 / 4), 2);
		mouth = new line(point(swest().x + 2, swest().y + hh / 4), ll - 4);*/

		for (int yi = 0; yi < 20; yi += 3){
			del.push_back(new line(point(nwest().x, yi), seast().x - south().x));
		}
	}


	void move(int a, int b)
	{
		rectangle::move(a, b);
		l_eye->move(a, b);
		r_eye->move(a, b);
		mouth->move(a, b);

//		for (auto i : del)
//			i->move(a, b);
		
	}
};




#endif
