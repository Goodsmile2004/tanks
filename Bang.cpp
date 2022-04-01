#include "Bang.h"

Bang::Bang(float x, float y) : Emitter(x, y)
{
	m_lenParticles = 0; m_maxLenParticles = 50;
}

void Bang::UpdateState(float time)
{
    for (auto i = particles.begin(); i != particles.end();) {
        auto p = *i;
        if (p->m_life > 0) {
            p->m_speedX += m_gravityX;
            p->m_speedY += m_gravityY;
            p->m_x += p->m_speedX * std::min(1.f, p->m_life / 100.f);
            p->m_y += p->m_speedY * std::min(1.f, p->m_life / 100.f);
            p->m_particle.setPosition(p->m_x, p->m_y);
            ++i;
        }
        else {
            i = particles.erase(i);
            delete p;
        }
        p->m_life -= time;
    }
    for (; m_lenParticles < m_maxLenParticles; ++m_lenParticles) {
        //if (particles.size() < 500) {
        Particle* p = new Particle(m_x, m_y, 10);
        particles.push_back(p);
        //}
    }
}

void Bang::Render(sf::RenderWindow& w)
{
    for (auto& p : particles) {
        p->Draw(w);
    }
}
