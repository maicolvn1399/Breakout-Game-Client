//
// Created by maxgm on 4/9/21.
//

#pragma once
#ifndef BREAKOUT_GAME_BARPLAYER_H
#define BREAKOUT_GAME_BARPLAYER_H
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>


class BarPlayer {
private:
    sf::RectangleShape shape;

    float movementSpeed;

    void initVariables();
    void initShape();
    void resizeBarShape();

public:
    BarPlayer(float x = 0.f, float y = 725.f); //Initial player position
    virtual ~BarPlayer();

    void updateInput();
    void updateWindowBoundsCollision(const sf::RenderTarget* target);
    void update(const sf::RenderTarget* target);
    void render(sf::RenderTarget* target);
};


#endif //BREAKOUT_GAME_BARPLAYER_H
