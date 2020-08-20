#pragma once
#include "Solution.h"
class Move :
    public Solution
{
public:

    Move();
    void mutate(float amplitude);
};

