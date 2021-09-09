//
// Created by maxgm on 4/9/21.
//

#pragma once
#ifndef BREAKOUT_GAME_BALL_H
#define BREAKOUT_GAME_BALL_H
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

class Ball {
private:
    sf::CircleShape circleShape;

    float ballsMovementSpeedX;

    float ballsMovementSpeedY;

    void initVariables();
    void initShape();

public:
    Ball(float x = 0.f, float y = 700.f);
    virtual ~Ball();

    void updateWindowBoundsCollision(const sf::RenderTarget* target);
    void updateObjectCollision(const sf::RenderTarget* target);
    void update(sf::RenderTarget* target);
    void render(sf::RenderTarget* target);

};


#endif //BREAKOUT_GAME_BALL_H
