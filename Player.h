#pragma once
#include <SFML/Graphics.hpp>
#include "Entity.h"

class Player : public Entity
{
public:
	Player(std::string f, std::string n, sf::Vector2f c, float w, float h, int s, float sR);
	void Update(float time);
	void control(sf::RenderWindow& w);
	void draw(sf::RenderWindow& w);
	sf::Vector2f getCoords();
private:
	sf::Vector2f m_coords;
	bool m_move, m_dir;
	int m_changeDir;
};

