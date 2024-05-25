#include "ParitcleSimulator.h"
#include <iostream>

void ParticleSimulator::addParticle(const Particle &particle) {
    particles.push_back(particle);
}

void ParticleSimulator::clearParticles() {
    particles.clear();
}

void ParticleSimulator::update(double dt) {
    for (size_t i = 0; i < particles.size(); ++i) {
        particles[i].update(dt);

        for (size_t j = i + 1; j < particles.size(); ++j) {
            particles[i].checkCollision(particles[j]);
        }
    }
}

void ParticleSimulator::render(sf::RenderWindow &window) const {
    for (const auto &particle: particles) {
        particle.draw(window);
    }
}

void ParticleSimulator::createParticle(double x, double y) {
    sf::Color color = alternateColor ? sf::Color::Red : sf::Color::Green;
    alternateColor = !alternateColor;
    double vx = (rand() % 200 - 100) / 10.0;
    double vy = (rand() % 200 - 100) / 10.0;
    Particle newParticle(x, y, vx, vy, color);
    addParticle(newParticle);
}