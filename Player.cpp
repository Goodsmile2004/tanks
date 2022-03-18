#include "Player.h"
#include <iostream>
#include "Config.h"

Player::Player(std::string f, std::string n, sf::Vector2f c, float w, float h, int s, float sR) :
	Entity(f, n, c, w, h, s, sR)
{
	m_sprite.setTextureRect(sf::IntRect(0, 0, w, h));
	m_sprite.setOrigin(w / 2, h / 2);
	m_sprite.setPosition(m_coords);
	m_move = false;
	m_dir = true;
	m_changeDir = 1;
}

sf::Vector2f Player::getCoords()
{
	return m_coords;
}

void Player::Update(float time)
{
	float lenght = sqrt(cos(m_angle * DEGTORAD) * cos(m_angle * DEGTORAD) + sin(m_angle * DEGTORAD) * sin(m_angle * DEGTORAD));
	if (m_move) {
		m_coords += m_speed * time * sf::Vector2f(cos(m_angle * DEGTORAD) / lenght, sin(m_angle * DEGTORAD) / lenght) * 0.01f;
	}

	if (m_dir && !m_move) {
		m_angle += -0.005f * time * m_speedRotate;
	}
	if (!m_dir && !m_move) {
		m_angle += 0.005f * time * m_speedRotate;
	}

	m_sprite.setRotation(m_angle);
	m_sprite.setPosition(m_coords);
	m_move = false;
}

void Player::control(sf::RenderWindow& w)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
		m_move = true;
		if (m_changeDir == 1) {
			m_dir = !m_dir;
			m_changeDir = 0;
		}
	}
	else {
		m_changeDir = 1;
	}
}

void Player::draw(sf::RenderWindow& w)
{
	w.draw(m_sprite);
}
