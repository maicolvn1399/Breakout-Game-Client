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
#include <math.h>
#include <algorithm>
#include <iostream>
#include <sstream>
using namespace sf;

class Ball {
private:
    CircleShape circleShape;
    Time time;
    Int32 updateTime;

    Vector2f ballSpeed;

    void initVariables();
    void initShape(const sf::RenderWindow& window);

public:
    Ball(const sf::RenderWindow& window);
    virtual ~Ball();

    const sf::CircleShape & getShape() const;
    void updateWindowBoundsCollision(sf::RenderTarget& target); //se usa & para pasar el objeto por referencia(direccion de memoria), no por valor.
    void updateBall();
    void render(sf::RenderTarget& target);

};


#endif //BREAKOUT_GAME_BALL_H
