//
// Created by maxgm on 4/9/21.
//

#include "Ball.h"

void Ball::initVariables() {

    //this->ballsMovementSpeed = 10.f;

}

void Ball::initShape(const sf::RenderWindow& window) {
    this->circleShape.setRadius(10.f);
    sf::Color color(rand()%255 + 1, rand()%255 + 1, rand()%255 +1);
    this->circleShape.setFillColor(color);
    this->circleShape.setPosition(sf::Vector2f(500.f, 700.f));

}

Ball::Ball(const sf::RenderWindow& window) {
    this->initShape(window);

    this->initVariables();

}

Ball::~Ball() {

}

void Ball::updateInput() {

    }


void Ball::update() {


}

void Ball::render(sf::RenderTarget &target) {
    target.draw(this->circleShape);

}




