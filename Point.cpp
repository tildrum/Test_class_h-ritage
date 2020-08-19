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
//float Point::closest(Point a, Point b) { cout << "COUCOU" << endl; }
