#pragma once
#include <unordered_map>
#include "Ship.h"

namespace GameRules
{
	constexpr std::size_t BOARD_SIZE = 10;

    inline const std::unordered_map<ShipType, int> SHIP_COUNTS = {
        {ShipType::FRIGATE,4},
        {ShipType::DESTROYER,3},
        {ShipType::CRUISER, 2},
        {ShipType::LINKOR, 1}
    };

}