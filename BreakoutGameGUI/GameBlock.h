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
/**
 * @authors Michael Valverde Navarro y Max Garro Mora
 * @brief Clase que se encarga de crear los diferentes tipos bloques y posicionarlos en la parte superior de la pantalla
 * @version 2.0
 * @date 13/09/2021
 */

class GameBlock{


public:
    GameBlock();

    RectangleShape block;
    string* wordList;
    bool* isBlock;
    int* hitsToBlock;
    void setFalseValuesToArray();
    int totalBlocks;

public:
    const RectangleShape &getBlock() const;
    bool *getIsBlock() const;

    void setBlockColors();

    void setBlocksPositions(Vector2f positions);

    void setBlockTypes();
};



#endif //BREAKOUT_GAME_CLIENT_GAMEBLOCK_H
