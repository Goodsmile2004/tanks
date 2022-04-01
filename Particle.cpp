#include "Particle.h"

Particle::Particle(float x, float y, int r)
{
	m_radius = r + rand() % 20;
	m_particle.setRadius(m_radius);
	m_particle.setFillColor(sf::Color(105, 105, 105));
	m_x = x, m_y = y;
	m_particle.setPosition(m_x, m_y);
	int direction = rand() % 360;
	float speed = 0.1 + rand() % 5;
	m_speedX = cos(direction * DEGTORAD) * speed;
	m_speedY = sin(direction * DEGTORAD) * speed;
	m_life = 5 + rand() % 75;
}

void Particle::Draw(sf::RenderWindow& w)
{
	float k = std::min(1.f, m_life / 100.f);
	int alpha = (int)255 * k;
	sf::Color color = m_particle.getFillColor();
	color.a = alpha;
	m_particle.setFillColor(color);
	w.draw(m_particle);
}
