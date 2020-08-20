#include "Unit.h"

#include <iostream>

using namespace std;

Unit::Unit(float x, float y, int id, float r) : Point(x, y), id(id), m_r(r) {
    cout << "Constructeur de Unit (version faible)" << endl;
}

Unit::Unit(float x, float y, int id ,float r, float vx, float vy): Point(x,y), id(id), m_r(r), m_vx(vx), m_vy(vy) {
    cout << "Constructeur de Unit" << endl;
}
//Colision colision(Unit u) {}

void Unit::debug(){
    cout << "Petit Test depuis Unit" << endl;
    cout << " Est-ce que j'ai accès aux attributs Point ? : " << m_x << " : " << m_y << endl;
}
void Unit::bounce() {}

