#pragma once
#include <unordered_map>
#include "Ship.h"

namespace GameRules
{
	constexpr std::size_t BOARD_SIZE = 10;

	inline const std::vector<ShipType> shipsToPlace = {
		ShipType::LINKOR,
		ShipType::CRUISER, ShipType::CRUISER,
		ShipType::DESTROYER, ShipType::DESTROYER, ShipType::DESTROYER,
		ShipType::FRIGATE, ShipType::FRIGATE, ShipType::FRIGATE, ShipType::FRIGATE
	};
	
};
