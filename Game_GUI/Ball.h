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
    void initShape(const sf::RenderWindow& window);

public:
    Ball(const sf::RenderWindow& window);
    virtual ~Ball();

    //Functions
    void collision();
    void updateInput();
    void update();
    void render(sf::RenderTarget& target);

};


#endif //BREAKOUT_GAME_BALL_H
