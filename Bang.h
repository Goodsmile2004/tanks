#pragma once
#include "Emitter.h"
class Bang : public Emitter
{
public:
	int m_lenParticles, m_maxLenParticles;
	Bang(float x, float y);
	void UpdateState(float time);
	void Render(sf::RenderWindow& w);
};

