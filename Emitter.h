#pragma once
#include <list>
#include <iostream>
#include "Particle.h"
#include "Config.h"

class Emitter
{
public:
	float m_x, m_y;
	float m_gravityX, m_gravityY;
	std::list<Particle*> particles;
	Emitter(float x, float y);
	void virtual UpdateState(float time);
	void virtual Render(sf::RenderWindow& w);
	virtual void ResetParticle(Particle& particle);
	~Emitter();
};



