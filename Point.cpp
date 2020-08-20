#include "Point.h"

#include <iostream>

using namespace std;


Point::Point(): m_x(0), m_y(0) {}
Point::Point(float x, float y) : m_x(x), m_y(y) {

    cout << "Constructeur de Point" << endl;
}

float Point::getX()
{
    return m_x;
}
float Point::getY()
{
    return m_y;
}
void Point::debug(){
    cout << "Point avec x = " << m_x << " et y = " << m_y << endl;
}
float Point::distance1(Point a) {
    return (this->m_x - a.m_x) * (this->m_x - a.m_x) + (this->m_y - a.m_y) * (this->m_y - a.m_y);
}
float Point::distance2(Point a) {
    return sqrt(this->distance1(a));
}
Point* Point::closest(Point a, Point b) { 

    float da = b.m_y - a.m_y;
    float db = a.m_x - b.m_x;
    float c1 = da * a.m_x + db * a.m_y;
    float c2 = -db * this->m_x + da * this->m_y;
    float det = da * da + db * db;
    float cx = 0;
    float cy = 0;

    if (det != 0) {
        cx = (da * c1 - db * c2) / det;
        cy = (da * c2 + db * c1) / det;
    }
    else {
        // Le point est déjà sur la droite
        cx = this->m_x;
        cy = this->m_y;
    }

    return new Point(cx, cy);

}
