#include <iostream>
#include <vector>
#include <assert.h>
#include <cmath>

#include "myshape.h"
#include "shape.h"

using namespace std;

enum { ONE, TOW, THREE };

struct Node{ // Node
	Node(int _ver );
	int color;
	int name; // re number
	vector<Node*> output;
	vector<Node*> input;


	void  Print(vector<Node*> *nodes);



	int num;
	static int all;
};
