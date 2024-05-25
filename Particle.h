#ifndef PARTICLES_TEST_PARTICLE_H
#define PARTICLES_TEST_PARTICLE_H

#include <SFML/Graphics.hpp>

class Particle {
public:
    Particle(double x, double y, double vx, double vy, sf::Color color);
    void update(double dt);
    void draw(sf::RenderWindow& window) const;
    void checkCollision(Particle& other);
    double getX() const;
    double getY() const;
    double getVX() const;
    double getVY() const;
    double getRadius() const;
    void setPosition(double newX, double newY);
    void setVelocity(double newVX, double newVY);

private:
    double x, y;  // Position
    double vx, vy;  // Velocity
    sf::CircleShape shape;
    double radius;
};

#endif //PARTICLES_TEST_PARTICLE_H
