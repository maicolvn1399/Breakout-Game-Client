//
// Created by maxgm on 12/9/21.
//

#pragma once
#ifndef BREAKOUT_GAME_CLIENT_GRID_H
#define BREAKOUT_GAME_CLIENT_GRID_H
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <math.h>
#include <algorithm>
#include <iostream>
#include <sstream>
//#include "Brick.h"
using namespace sf;

class Grid : public FloatRect {
private:
    unsigned int rows;
    unsigned int columns;

    std::vector<Brick> * bricks;

public:
    Grid();
    virtual ~Grid();

    void setDimensions(unsigned int col, unsigned int row);
    void init();
    void display(RenderWindow & window);
    bool collide(RectangleShape & ball, Vector2f & ballSpeed, unsigned int & score);
    bool isGameWon();

};


#endif //BREAKOUT_GAME_CLIENT_GRID_H
