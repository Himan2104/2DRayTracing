#include"pch.h"
#include<iostream> 
#include<SFML/Graphics.hpp>
#include"Defs.hpp"
#include"Ray.hpp"
#include"Wall.hpp"


sf::Vector2f Mpos = sf::Vector2f(0, 0);

void generateRandomWalls(std::vector<Wall>&  Walls)
{
	Walls.clear();
	srand(time(NULL));
	for (int i = 0; i < randomWallCount; i++)
	{
		sf::Vector2f ptA(rand() % Vmode.width, rand() % Vmode.height);
		sf::Vector2f ptB(rand() % Vmode.width, rand() % Vmode.height);
		Walls.push_back(Wall(ptA, ptB));
	}
}

int main()
{
	sf::RenderWindow window(Vmode, "2DRayTracing");
	window.setFramerateLimit(frameRateCap);

	std::vector<Wall> Walls;
	generateRandomWalls(Walls);

	std::vector<Ray> Rays;
	float loopFactor = 1.0f / intensity;
	for (float a = 0; a < TwoPi; a += loopFactor)
	{
		const float x = cos(a);
		const float y = sin(a);
		Rays.push_back(Ray(x, y));
	}

	sf::VertexArray rayLine(sf::Lines, 2);
	rayLine[0].color = rayColor;
	rayLine[1].color = rayColor;

	sf::VertexArray wallLine(sf::Lines, 2);
	wallLine[0].color = wallColor;
	wallLine[1].color = wallColor;

	sf::Font font;
	font.loadFromFile("C:/Windows/Fonts/arial.ttf");
	sf::Text stats;
	stats.setFont(font);
	stats.setPosition(10.0f, 10.0f);
	stats.setCharacterSize(15);

	sf::Clock clk;
	float frameTime;

	while (window.isOpen())
	{
		frameTime = clk.restart().asSeconds();
		Mpos = sf::Vector2f(sf::Mouse::getPosition(window));

		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed) window.close();
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) generateRandomWalls(Walls);

	

		rayLine[0].position = Mpos;

		window.clear();

	
		
		for (auto& currentRay : Rays)
		{
			currentRay.reset();
			for (auto& currentWall : Walls) currentRay.hitCal(currentWall.ptA, currentWall.ptB);
			rayLine[1].position = currentRay.endPoint;
			window.draw(rayLine);
		}

		for (auto& val : Walls)
		{
			wallLine[0].position = val.ptA;
			wallLine[1].position = val.ptB;
			window.draw(wallLine);
		}
		

		stats.setString("FPS : " + std::to_string(1.0f / frameTime)
			+ "\nWalls : " + std::to_string(Walls.size())
			+ "\nRays : " + std::to_string(Rays.size())
			+ "\nPhotonDensity/Intensity : " + std::to_string(intensity));

		window.draw(stats);

		window.display();
	}

	return 0;
}