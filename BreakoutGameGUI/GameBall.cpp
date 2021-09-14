//
// Created by michael on 13/9/21.
//

#include "GameBall.h"
#include "math.h"

GameBall::GameBall() {
    ball.setRadius(8.0f);
    ball.setFillColor(Color::Magenta);
    ball.setOutlineColor(Color::Red);
    ball.setOutlineThickness(1.0f);

    defaultSpeed = 400.0f;
    angle = 0.0f;
    speed = Vector2f(0.0f,0.0f);
}

const CircleShape &GameBall::getBall() const {
    return ball;
}

void GameBall::setPosition(Vector2f pos) {
    ball.setPosition(pos);
}

void GameBall::angleMovement() {

    angle = (-20 -(rand() % 140))*(M_PI/180.0);
    speed.x = cos(angle) * defaultSpeed;
    speed.y = sin(angle) * defaultSpeed;
}

float GameBall::getDefaultSpeed() const {
    return defaultSpeed;
}

float GameBall::getAngle() const {
    return angle;
}

const Vector2f &GameBall::getSpeed() const {
    return speed;
}

void GameBall::boundariesCollision() {

    if(ball.getPosition().x <= 0.0f){
        ball.setPosition(Vector2f(0.0f,ball.getPosition().y));
        speed.x = abs(speed.x);
    }else if(ball.getPosition().x + (ball.getRadius() * 2.0f) >= 800){
        ball.setPosition(Vector2f(800 - (ball.getRadius() * 2.0f),ball.getPosition().y));
        speed.x = -abs(speed.x);
    }

    if(ball.getPosition().y <= 0.f){
        ball.setPosition(Vector2f(ball.getPosition().x,0.0f));
        speed.y = abs(speed.y);
    }else if(ball.getPosition().y + (ball.getRadius() * 2.0f) >= 600){
        ball.setPosition(Vector2f(ball.getPosition().x, 600 - (ball.getRadius() * 2.0f)));
        speed.y = abs(speed.y);
    }
}
