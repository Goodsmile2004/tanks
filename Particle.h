#pragma once
#include <SFML/Graphics.hpp>
#include "Config.h"
class Particle
{
public:
	int m_life, m_radius;
	float m_speedX, m_speedY;
	float m_x, m_y;
	sf::CircleShape m_particle;
	Particle(float x, float y, int r);
	void Draw(sf::RenderWindow& w);
};

