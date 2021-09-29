//
// Created by michael on 13/9/21.
//

#include "GameBall.h"
#include "math.h"
#include "iostream"

GameBall::GameBall() {
    ball.setRadius(5.0f);
    ball.setFillColor(Color::White);
    ball.setOutlineColor(Color::Cyan);
    ball.setOutlineThickness(1.0f);

    defaultSpeed = 400.0f;
    angle = 0.0f;
    speed = Vector2f(0.0f,0.0f);
    speedFactor = 2.0f;
    profundidad = 0;
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

void GameBall::boundariesCollision(GameBar bar, vector<GameBall> gameBalls) {

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
        ball.setPosition(Vector2f(bar.getBar().getPosition().x, bar.getBar().getPosition().y));
        //speed.y = -abs(speed.y);
        gameBalls.pop_back();
    }
}

void GameBall::increaseVelocity() {
    cout << "Increase ball velocity" << endl;
    speed.x += 2.0f;
    speed.y += 2.0f;
}

void GameBall::decreaseVelocity() {
    cout << "Decrease ball velocity" << endl;
    speed.x -= 1.0f;
    speed.y -= 1.0f;
}

void GameBall::moveFaster() {
    float speedFactor = 4.f;
    float ratio = abs(speed.x)/abs(speed.y);

    if(speed.x < 0.0f)
        speed.x -= speedFactor;
    else
        speed.x += speedFactor;

    if(speed.y < 0.0f)
        speed.y -= speedFactor * ratio;
    else
        speed.y += speedFactor * ratio;

}
