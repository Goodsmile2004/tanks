#pragma once
#include <SFML/Graphics.hpp>
#include "Entity.h"
#include "World.h"
#include "Player.h"
#include "Scene.h"

class Bullet {
public:
	float timer;
	int m_speed;
	float m_angle;
	std::string m_name;
	sf::Vector2f m_coords;
	Bullet(std::string f, std::string n, sf::Vector2f c, int speed, float angle);
	void Update(float time);
	void draw(sf::RenderWindow& w);
private:
	sf::RectangleShape bullet;
	//std::vector<Player*> objects;
};



