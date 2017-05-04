#ifndef SHAPE_H
#define SHAPE_H
#include "screen.h"

#include "gslist.h"

struct shape;

typedef shape* sp;

finIn(show_,handl);
// //typedef declare(gslist,sp) my1;
// typedef void declare(gslist,sp);
//
//
//
//typedef gslist(sp) shape_lst;
////typedef void gslist_iterator(sp);  ///!!!
//typedef gslist_iterator(sp) sl_iterator;
//extern shape_lst shape_list;

struct shape
{

	//shape() { /*shape_list.append(this);*/ }  ///!!!

	 static shape* list;
	 shape* next;

public:
	shape() {
		next = list;
		list = this;		
	}

    virtual point north() { return point(0,0); }
    virtual point neast() { return point(0,0); }
    virtual point east()  { return point(0,0); }
    virtual point seast() { return point(0,0); }
    virtual point south() { return point(0,0); }
    virtual point swest() { return point(0,0); }
    virtual point west()  { return point(0,0); }
    virtual point nwest() { return point(0,0); }
    virtual point middle(){ return point(0,0); }

    virtual void draw() {};
    virtual void move(int, int) {};
	friend void shape_refresh();
    friend void stack(shape*, shape*);
};

extern void shape_refresh();
extern void stack(shape*, shape*);
extern void stackWE(shape*, shape*);

#ifdef RECTFIRST
# include <rectangle.h>
# include <line.h>
#else
# include "line.h"
# include "rectangle.h"
# include "trangle.h"
#endif

#endif
