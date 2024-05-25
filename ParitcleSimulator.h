#ifndef PARTICLES_TEST_PARITCLESIMULATOR_H
#define PARTICLES_TEST_PARITCLESIMULATOR_H

#include "Particle.h"
#include <vector>
#include <SFML/Graphics.hpp>


#include "Particle.h"
#include <vector>
#include <SFML/Graphics.hpp>

class ParticleSimulator {
public:
    void addParticle(const Particle& particle);
    void update(double dt);
    void render(sf::RenderWindow& window) const;
    void createParticle(double x, double y);
    void clearParticles();

private:
    std::vector<Particle> particles;
    bool alternateColor = true;
};

#endif //PARTICLES_TEST_PARITCLESIMULATOR_H
