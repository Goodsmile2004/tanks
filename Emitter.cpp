#include "Emitter.h"

Emitter::Emitter(float x, float y)
{
    m_x = x, m_y = y;
    m_gravityX = 0; m_gravityY = 0;
}

void Emitter::UpdateState(float time)
{
    
}

void Emitter::Render(sf::RenderWindow& w)
{
}

void Emitter::ResetParticle(Particle& particle)
{
}

Emitter::~Emitter()
{
}


