#ifndef DEF_POINT
#define DEF_POINT

#pragma once
class Point
{
protected :
	float m_x;
	float m_y;

public :

	Point();
	Point(float x, float y);

	float getX();
	float getY();
	void debug();
	float distance1(Point p);
	float distance2(Point p);
	Point* closest(Point a, Point b);



};

#endif

