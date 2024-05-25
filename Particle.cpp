#include "Particle.h"
#include <cmath>

Particle::Particle(double x, double y, double vx, double vy, sf::Color color)
        : x(x), y(y), vx(vx), vy(vy), shape(5), radius(5.0) {
    shape.setFillColor(color);
    shape.setPosition(x, y);
}

void Particle::update(double dt) {
    x += vx * dt;
    y += vy * dt;
    shape.setPosition(x, y);
}

void Particle::draw(sf::RenderWindow& window) const {
    window.draw(shape);
}

void Particle::checkCollision(Particle& other) {
    double dx = other.x - x;
    double dy = other.y - y;
    double distance = std::sqrt(dx * dx + dy * dy);

    if (distance < radius + other.radius) {
        // Simple elastic collision response
        double nx = dx / distance;
        double ny = dy / distance;
        double p = 2 * (vx * nx + vy * ny - other.vx * nx - other.vy * ny) / 2;

        vx = vx - p * nx;
        vy = vy - p * ny;
        other.vx = other.vx + p * nx;
        other.vy = other.vy + p * ny;

        // Move particles apart to avoid sticking
        double overlap = 0.5 * (radius + other.radius - distance);
        x -= overlap * nx;
        y -= overlap * ny;
        other.x += overlap * nx;
        other.y += overlap * ny;
    }
}

double Particle::getX() const {
    return x;
}

double Particle::getY() const {
    return y;
}

double Particle::getVX() const {
    return vx;
}

double Particle::getVY() const {
    return vy;
}

double Particle::getRadius() const {
    return radius;
}

void Particle::setPosition(double newX, double newY) {
    x = newX;
    y = newY;
    shape.setPosition(x, y);
}

void Particle::setVelocity(double newVX, double newVY) {
    vx = newVX;
    vy = newVY;
}
