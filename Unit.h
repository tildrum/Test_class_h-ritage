#pragma once
#include "Point.h"
class Unit :
    public Point
{
protected :
    int id;
    float m_r;
    float m_vx;
    float m_vy;

public:

    Unit(int x, int y, int id, float r, float vx, float vy);

    void debug();
    void bounce();
};

