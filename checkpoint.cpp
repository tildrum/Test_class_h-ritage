#include "checkpoint.h"

#include <iostream>

using namespace std;

checkpoint::checkpoint(float x, float y, int id, float r): Unit(x,y,id,r) {

	cout << " Constructeur du checkpoint " << endl;
}

void checkpoint::bounce(Unit u) {}
