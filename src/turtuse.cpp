//============================================================================
// Name        : Buro.cpp
// Author      : Kasianov
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <vector>
using namespace std;

#include "turtuse.h"




char int2char(int i){
	switch(i){
		case 0: return '0'; break;
		case 1: return '1'; break;
		case 2: return '2'; break;
		case 3: return '3'; break;
		case 4: return '4'; break;
		case 5: return '5'; break;
		case 6: return '6'; break;
		case 7: return '7'; break;
		case 8: return '8'; break;
		case 9: return '9'; break;
		case 10: return 'a'; break;


		default: return '?';
	}

}

const int n = 3, m = 4;

void prints (string dir, int val, int x, int y ){
	cout << dir << "[" <<  val << "]"  << " x = " << x << " y= " << y <<  endl;
	point pos = point( x,m - y)*point(2, 2) ;
	new rectangle(pos , pos, int2char(val) );
	shape_refresh();
}


int main() {



    int map[n][m] =
    {
        { 1, 8, 3, 4},
        { 2, 7, 5, 6},
        { 0, 10, 1, 6}
    };

    int j = 0, i = n - 1;
	while (i > 0 || j < m) {
		if (i == 0 && j == m - 1)
			break;
		// Up Right
		if (i > 0) {
			if (map[i - 1][j] >= map[i][j + 1]) {
				prints(" Up ", map[i - 1][j], j, i - 1);
				i--;
				continue;
			}
		} else {
			prints(" Right ", map[i][j + 1], j + 1, i);
			j++;
			continue;
		};

		// Right Up
		if (j != m - 1) {
			if (map[i - 1][j] <= map[i][j + 1]) {
				prints(" Right ", map[i][j + 1], j + 1, i);
				j++;
				continue;
			}
		} else {
			prints(" Up ", map[i - 1][j], j, i - 1);
			i--;
			continue;
		};
	};
}





