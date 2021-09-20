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
    //RenderWindow* window = NULL;
    int width;
    int height;

    const RectangleShape &getBar() const;
    void barMove(Event e, int width, int height, RenderWindow *window);
    void increaseSize();
    void decreaseSize();
};


#endif //BREAKOUT_GAME_CLIENT_GAMEBAR_H
