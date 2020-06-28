#pragma once
#include<SFML/Graphics.hpp>

const double TwoPi = 2 * 3.14159;
extern sf::Vector2f Mpos;


const sf::VideoMode Vmode(800, 600, 32); //resolution and colorspace
const unsigned int frameRateCap = 90; //frame rate limiter 

const float intensity = 200; //intensity/density of rays. suggested values(200, 10000)
const sf::Color rayColor(255,0,255); //color of ray
const sf::Color wallColor(0,255,0); // color of walls
const unsigned int randomWallCount = 7; // number of randomly generated walls
