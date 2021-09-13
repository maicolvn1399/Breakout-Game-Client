//
// Created by michael on 12/9/21.
//

#ifndef BREAKOUT_GAME_CLIENT_BRICK_H
#define BREAKOUT_GAME_CLIENT_BRICK_H

#include <iostream>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <math.h>
#include <algorithm>
#include <iostream>
#include <sstream>
#define PI   3.14159265358979323846
using namespace sf;
using namespace std;

class Brick : public RectangleShape{

public:
    unsigned int armor;

    Brick():RectangleShape()
    {
        armor=2;
    }

    Brick(const Vector2f & size):RectangleShape(size)
    {
        armor=2;
    }

    bool collide(RectangleShape & ball, Vector2f & ballSpeed);

};





#endif //BREAKOUT_GAME_CLIENT_BRICK_H
