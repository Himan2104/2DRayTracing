#include"pch.h"
#include "Ray.hpp"

Ray::Ray(float x, float y)
{
	relEnd = sf::Vector2f(x, y) * 5000.f;
}

void Ray::reset()
{
	endPoint = Mpos + relEnd;
}

void Ray::hitCal(sf::Vector2f ptA, sf::Vector2f ptB)
{
	const sf::Vector2f pRS = Mpos;
	const sf::Vector2f pRE = endPoint;

	float D = (pRS.x - pRE.x) * (ptA.y - ptB.y) - (pRS.y - pRE.y) * (ptA.x - ptB.x);
	if (D == 0)
		return;
	float t = ((pRS.x - ptA.x) * (ptA.y - ptB.y) - (pRS.y - ptA.y) * (ptA.x - ptB.x)) / D;
	float u = -((pRS.x - pRE.x) * (pRS.y - ptA.y) - (pRS.y - pRE.y) * (pRS.x - ptA.x)) / D;

	if (t > 0 && t < 1 && u > 0 && u < 1)
	{
		endPoint.x = pRS.x + t * (pRE.x - pRS.x);
		endPoint.y = pRS.y + t * (pRE.y - pRS.y);
	}
}