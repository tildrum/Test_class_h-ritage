#pragma once
#include "Unit.h"
class Pod :
    public Unit
{
protected:

    float m_angle;
    int m_nextCheckPointid;
    int m_checked;
    int m_timeout;
    bool m_shield;

public:

    Pod(float x, float y, int id, float r, float vx, float vy, float angle, int nextCheckPointid, int checked, int timeout);

    void debug();
    float getAngle(Point p);
    float diffAngle(Point p);
    void rotate(Point p);
    void boost(int thrust);
    void move(float u);
    void end();
    void play(Point p, int thrust);
    void bounce(Unit u);
    //void output(Move move);

};

