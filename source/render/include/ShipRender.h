#pragma once 
#include "Ship.h"
#include <raylib.h>




class ShipRender
{
public:
    void DrawShips(const std::vector<Ship>& ships);
};