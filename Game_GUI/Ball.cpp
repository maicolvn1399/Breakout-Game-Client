//
// Created by maxgm on 4/9/21.
//

#include "Ball.h"

void Ball::initVariables() {

    this->ballsMovementSpeedX = 10.f;
    this->ballsMovementSpeedY = 10.f;

}

void Ball::initShape() {
    this->circleShape.setRadius(10.f);
    sf::Color color(rand()%255 + 1, rand()%255 + 1, rand()%255 +1);
    this->circleShape.setFillColor(color);
    this->circleShape.setPosition(sf::Vector2f(500.f, 700.f));

}

Ball::Ball(float  x, float y){
    this->circleShape.setPosition(x, y);

    this->initVariables();
    this->initShape();

}

Ball::~Ball() {

}

void Ball::updateWindowBoundsCollision(const sf::RenderTarget *target) {

    //Left
    if (this->circleShape.getGlobalBounds().left <= 0.f)
        this->circleShape.setPosition(0.f, this->circleShape.getGlobalBounds().top);
        //Right
    else if(this->circleShape.getGlobalBounds().left + this->circleShape.getGlobalBounds().width >= target->getSize().x)
        this->circleShape.setPosition(target->getSize().x - this->circleShape.getGlobalBounds().width, this->circleShape.getGlobalBounds().top);
    //Top
    if (this->circleShape.getGlobalBounds().top <= 0.f)
        this->circleShape.setPosition(this->circleShape.getGlobalBounds().left,0.f) ;
        //Bottom
    else if(this->circleShape.getGlobalBounds().top + this->circleShape.getGlobalBounds().height >= target->getSize().y)
        this->circleShape.setPosition(this->circleShape.getGlobalBounds().left, target->getSize().y - this->circleShape.getGlobalBounds().height);

}


void Ball::update(sf::RenderTarget* target) {


    //Window bounds collision
    this->updateWindowBoundsCollision(target);

}

void Ball::render(sf::RenderTarget *target) {
    target->draw(this->circleShape);

}






