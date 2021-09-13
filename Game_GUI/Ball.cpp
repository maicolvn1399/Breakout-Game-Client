//
// Created by maxgm on 4/9/21.
//

#include <iostream>
#include "Ball.h"


void Ball::initVariables() {

    ballsMovementSpeedY = 5.f;
    ballsMovementSpeedX = 5.f;
    this->movTimer = 600;
    time = sf::seconds(30);
    flag = sf::seconds(0);
    juanSecond = sf::seconds(1);
    //sf::Vector2f ballSpeed(-ballsMovementSpeedX, -ballsMovementSpeedY);

}

void Ball::initShape(const sf::RenderWindow& window) {
    this->circleShape.setRadius(10.f);
    sf::Color color(rand()%255 + 1, rand()%255 + 1, rand()%255 +1);
    this->circleShape.setFillColor(color);
    this->circleShape.setPosition(sf::Vector2f(500.f,725.f));

}

Ball::Ball(const sf::RenderWindow& window){
    this->initShape(window);

    this->initVariables();
    this->initShape(window);

}

Ball::~Ball() {

}
const sf::CircleShape & Ball::getShape() const {
    return this->circleShape;
}

void Ball::updateWindowBoundsCollision(sf::RenderTarget &target) {

    //Left
    if (this->circleShape.getGlobalBounds().left <= 0.f)
        this->circleShape.setPosition(0.f, this->circleShape.getGlobalBounds().top);
        //Right
    else if(this->circleShape.getGlobalBounds().left + this->circleShape.getGlobalBounds().width >= target.getSize().x)
        this->circleShape.setPosition(target.getSize().x - this->circleShape.getGlobalBounds().width, this->circleShape.getGlobalBounds().top);
    //Top
    if (this->circleShape.getGlobalBounds().top <= 0.f)
        this->circleShape.setPosition(this->circleShape.getGlobalBounds().left,0.f) ;
        //Bottom
    else if(this->circleShape.getGlobalBounds().top + this->circleShape.getGlobalBounds().height >= target.getSize().y)
        this->circleShape.setPosition(this->circleShape.getGlobalBounds().left, target.getSize().y - this->circleShape.getGlobalBounds().height);

}


void Ball::update(sf::RenderTarget& target) {
    //Window bounds collision
    this->updateWindowBoundsCollision(target); //Verificar colisiones con los bordes de la pantalla.
    this->moveBall();

}

void Ball::moveBall() {
    while(time > flag){
        circleShape.move(0.f, -this->ballsMovementSpeedY);
        time -= juanSecond;
    }



}

void Ball::render(sf::RenderTarget &target) {
    target.draw(this->circleShape);

}










