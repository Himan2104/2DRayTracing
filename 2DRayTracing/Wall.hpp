#pragma once
#include"Defs.hpp"

class Wall
{
public:
	sf::Vector2f ptA, ptB;
	Wall(sf::Vector2f ptA, sf::Vector2f ptB);
};