#ifndef LINE_H
#define LINE_H

#include "shape.h"

class line: public shape {
	/*
	 line from "w" to "e"

	 north() is defined as `above the middle as
	 far north as the northernmost point'

	 nw ---- n ---- ne    nw ---- n ---- ne
	 |            *  |    |  *            |
	 |         *     |    |    *          |
	 w       m       e    w       m       e
	 |    *          |    |         *     |
	 | *             |    |            *  |
	 sw ---- s ---- se    sw ---- s ---- se
	 */
	point w, e;

public:

	point
		north()
	{
			return point((w.x + e.x) / 2, e.y < w.y ? w.y : e.y);
		}

	point
		neast()
	{
			return point(e.x, e.y < w.y ? w.y : e.y);
		}

	point
		east()
	{
			return point(e.x, (w.y + e.y) / 2);
		}

	point
		seast()
	{
			return point(e.x, e.y < w.y ? e.y : w.y);
		}

	point
		south()
	{
			return point((w.x + e.x) / 2, e.y < w.y ? e.y : w.y);
		}

	point
		swest()
	{
			return point(w.x, e.y < w.y ? e.y : w.y);
		}
	point
		west()
	{
			return point(w.x, (w.y + e.y) / 2);
		}
	point
		nwest()
	{
			return point(w.x, e.y < w.y ? w.y : e.y);
		}
	point
		middle()
	{
			return point((w.x + e.x) / 2, (w.y + e.y) / 2);
		}

	void move(int a, int b) {
		w.x += a;
		w.y += b;
		e.x += a;
		e.y += b;
	}
    void draw() { put_line(w, e); }

	line(point a, point b) {
		if (a.x < b.x) {
			w = a;
			e = b;
		} else {
			w = b;
			e = a;
		}
	}

	line(point a, int len) {
		if (len >= 0) {
			w = point(a.x + len - 1, a.y);
			e = a;
		} else {
			w = a;
			e = point(a.x + len - 1, a.y);
		}
	}
};
#endif
