//
// Created by michael on 13/9/21.
//

#ifndef BREAKOUT_GAME_CLIENT_GAMEBLOCK_H
#define BREAKOUT_GAME_CLIENT_GAMEBLOCK_H

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
using namespace sf;
using namespace std;

class GameBlock{


public:
    GameBlock();

    RectangleShape block;
    bool* isBlock;
    void setFalseValuesToArray();
    int totalBlocks;

public:
    const RectangleShape &getBlock() const;
    bool *getIsBlock() const;

    void setBlockColors();

    void setBlocksPositions(Vector2f positions);
};



#endif //BREAKOUT_GAME_CLIENT_GAMEBLOCK_H
