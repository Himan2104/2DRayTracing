#pragma once
#include<SFML/Graphics.hpp>
#include"Defs.hpp"

class Ray
{
public:
	sf::Vector2f endPoint;

	Ray() {};
	Ray(float x, float y);
	void hitCal(sf::Vector2f ptA, sf::Vector2f ptB);
	void reset();
private:
	sf::Vector2f relEnd;
};