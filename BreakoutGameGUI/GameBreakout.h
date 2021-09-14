//
// Created by michael on 13/9/21.
//

#ifndef BREAKOUT_GAME_CLIENT_GAMEBREAKOUT_H
#define BREAKOUT_GAME_CLIENT_GAMEBREAKOUT_H

#include "GameBall.h"
#include "GameBar.h"
#include "GameBlock.h"

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
using namespace sf;
using namespace std;

class GameBreakout{


public:
    GameBreakout(int w,int h, string title);
    ~GameBreakout();

    void event();
    void update(float dt);
    void render();
    void run();

private:
    RenderWindow* window = NULL;
    Event e;
    int width;
    int height;
    GameBall ball;
    GameBar bar;
    GameBlock block;
    bool* isBlock;


};

#endif //BREAKOUT_GAME_CLIENT_GAMEBREAKOUT_H
