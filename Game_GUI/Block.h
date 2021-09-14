//
// Created by maxgm on 11/9/21.
//

/**
#pragma once
#ifndef BREAKOUT_GAME_CLIENT_BLOCK_H
#define BREAKOUT_GAME_CLIENT_BLOCK_H
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>


class Block {
private:
    sf::RectangleShape blockShape;

    void initVariables();
    void initShape(const sf::RenderWindow& window);

public:
    Block(const sf::RenderWindow& window);
    virtual ~Block();

    const sf::RectangleShape & getShape() const;
    void update(sf::RenderTarget& target);
    void render(sf::RenderTarget& target);


};


#endif //BREAKOUT_GAME_CLIENT_BLOCK_H
**/