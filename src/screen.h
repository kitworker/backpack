#ifndef SCREEN_H
#define SCREEN_H
// file screen.h

const int XMAX = 40, YMAX = 10;

struct point {
    int x, y;
    point() {}
    point(int a, int b) { x = a; y = b; }
    point operator+(point t){
    	point tmp;
    	tmp.x = this->x + t.x;
    	tmp.y = this->y + t.y;
    	return tmp;
    }

    point operator-(point t){
    	point tmp;
    	tmp.x = this->x - t.x;
    	tmp.y = this->y - t.y;
    	return tmp;
    }

    point operator*(point t){
    	point tmp;
    	tmp.x = this->x * t.x;
    	tmp.y = this->y * t.y;
    	return tmp;
    }

};


extern void put_point(int a, int b);
extern void put_point(int a, int b, char color);
inline void put_point(point p) { put_point(p.x, p.y); }


extern void put_line(int, int, int, int);
extern void put_line(point a, point b);
extern void put_line(int, int, int, int, char);
extern void put_line(point a, point b, char);

extern void screen_init();
extern void screen_refresh();
extern void screen_clear();
extern void screen_end();

enum color { black = '#', white = ' ' };


#endif
