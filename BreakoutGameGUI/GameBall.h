//
// Created by michael on 13/9/21.
//

#ifndef BREAKOUT_GAME_CLIENT_GAMEBALL_H
#define BREAKOUT_GAME_CLIENT_GAMEBALL_H

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include "GameBar.h"
using namespace sf;
using namespace std;

class GameBall{
public:
    CircleShape ball;
    float defaultSpeed;
    float angle;
    float speedFactor;
    Vector2f speed;

public:
    GameBall();

    const CircleShape &getBall() const;
    void setPosition(Vector2f pos);
    void angleMovement();
    void boundariesCollision(GameBar bar);
    void increaseVelocity();
    void decreaseVelocity();
    void moveFaster();



    float getDefaultSpeed() const;

    float getAngle() const;

    const Vector2f &getSpeed() const;

};

#endif //BREAKOUT_GAME_CLIENT_GAMEBALL_H
