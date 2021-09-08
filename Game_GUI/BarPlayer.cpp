//
// Created by maxgm on 4/9/21.
//

#include "BarPlayer.h"

void BarPlayer::initVariables() {

    this->movementSpeed = 10.f;

}

void BarPlayer::initShape() {
    this->shape.setFillColor(sf::Color::Black);
    this->shape.setSize(sf::Vector2f(150.f, 25.f));

}

void BarPlayer::resizeBarShape() {

}

BarPlayer::BarPlayer(float x, float y) {
    this->shape.setPosition(x, y);

    this->initVariables();
    this->initShape();

}

BarPlayer::~BarPlayer() {

}

void BarPlayer::updateInput() {
    //Keyboard input
    //Left
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
        this->shape.move(-this->movementSpeed, 0.f);

    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
        this->shape.move(this->movementSpeed, 0.f);

    }
}

void BarPlayer::updateWindowBoundsCollision(const sf::RenderTarget *target) {

    //Left
    if (this->shape.getGlobalBounds().left <= 0.f)
        this->shape.setPosition(0.f, this->shape.getGlobalBounds().top);
    //Right
    else if(this->shape.getGlobalBounds().left + this->shape.getGlobalBounds().width >= target->getSize().x)
        this->shape.setPosition(target->getSize().x - this->shape.getGlobalBounds().width, this->shape.getGlobalBounds().top);
    //Top
    if (this->shape.getGlobalBounds().top <= 0.f)
        this->shape.setPosition(this->shape.getGlobalBounds().left,0.f) ;
    //Bottom
    else if(this->shape.getGlobalBounds().top + this->shape.getGlobalBounds().height >= target->getSize().y)
        this->shape.setPosition(this->shape.getGlobalBounds().left, target->getSize().y - this->shape.getGlobalBounds().height);

}

void BarPlayer::update(const sf::RenderTarget* target) {

    this->updateInput();

    //Window bounds collision
    this->updateWindowBoundsCollision(target);

}

void BarPlayer::render(sf::RenderTarget *target) {
    target->draw(this->shape);

}






