#include "myshape.h"

myshape::myshape(point a, point b)  : rectangle::rectangle(a, b, 'n')
{
	//rectangle * rec = new rectangle(a, b, 'n');

    int ll = neast().x - swest().x + 1;
    int hh = neast().y - swest().y + 1;
    l_eye = new line(point(swest().x + 2, swest().y + hh * 3 / 4) , 2);
    r_eye = new line(point(swest().x + ll - 4, swest().y + hh * 3 / 4), 2);
    mouth = new line(point(swest().x + 2, swest().y + hh / 4) , ll - 4);
}


void myshape::draw()
{
	rectangle::draw();
	put_point(point((swest().x + neast().x) / 2, (swest().y + neast().y) / 2));
}

void myshape::move(int a, int b)
{
	rectangle::move(a, b);
	l_eye->move(a, b);
	r_eye->move(a, b);
	mouth->move(a, b);
}
