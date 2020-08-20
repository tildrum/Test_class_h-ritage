#pragma once
#include "Unit.h"
class checkpoint :
    public Unit
{
public:

    checkpoint(float x, float y, int id, float r);
    void bounce(Unit u);
};

