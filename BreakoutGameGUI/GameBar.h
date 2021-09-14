//
// Created by michael on 13/9/21.
//

#ifndef BREAKOUT_GAME_CLIENT_GAMEBAR_H
#define BREAKOUT_GAME_CLIENT_GAMEBAR_H

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
using namespace sf;
using namespace std;


class GameBar{

public:
    RectangleShape bar;

public:
    GameBar();

    const RectangleShape &getBar() const;
    void barMove();
};


#endif //BREAKOUT_GAME_CLIENT_GAMEBAR_H
