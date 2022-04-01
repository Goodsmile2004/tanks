#include <SFML/Graphics.hpp>
#include "Bullet.h"
#include "Config.h"

Bullet::Bullet(std::string f, std::string n, sf::Vector2f c, int speed, float a) {
	m_coords = c;
	m_angle = a;
	timer = 5;
	bullet.setSize(sf::Vector2f(10, 5));
	bullet.setFillColor(sf::Color::Black);
	bullet.setRotation(m_angle);
	bullet.setPosition(c);
	m_speed = speed;
	m_name = n;
	/*
	for (auto& p : lvl->players) {
		objects.push_back(p);
	}*/
}

void Bullet::Update(float time)
{
	float lenght = sqrt(cos(m_angle * DEGTORAD) * cos(m_angle * DEGTORAD) + sin(m_angle * DEGTORAD) * sin(m_angle * DEGTORAD));
	m_coords += m_speed * time * sf::Vector2f(cos(m_angle * DEGTORAD) / lenght, sin(m_angle * DEGTORAD) / lenght);
	bullet.setPosition(m_coords);
	timer -= time;
	/*
	for (auto& p : objects) {
		if (p && m_coords == p->m_coords && m_name != p->m_name) {
			delete p;
			p = nullptr;
		}
	}*/
}
void Bullet::draw(sf::RenderWindow& w) {
	w.draw(bullet);
}
