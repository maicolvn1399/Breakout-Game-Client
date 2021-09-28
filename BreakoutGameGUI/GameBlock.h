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
#include "DataStructure/LinkedList.h"

using namespace sf;
using namespace std;

/**
 * @file GameBlock.h
 * @authors Michael Valverde Navarro y Max Garro Mora
 * @brief Clase que se encarga de crear los diferentes tipos bloques y posicionarlos en la parte superior de la pantalla
 * @version 2.0
 * @date 13/09/2021
 */

class GameBlock{

public:
    /**
     * @brief constructor de la clase GameBlock
     */
    GameBlock();

    RectangleShape block;
    string* wordList;
    bool* isBlock;
    int* hitsToBlock;
    int* blockColorList;


    /**
     * @brief metodo encargado de ingresar todos los valores en true o en false mediante dos for.
     */
    void setFalseValuesToArray();
    int totalBlocks;

public:

    /**
     * @brief metodo encargado de retornar block, que funciona para obtener los atributos de este en caso que se llame en otra clase
     * @return block, representa el objeto block
     */
    const RectangleShape &getBlock() const;

    /**
     * @brief metodo encargado de retornar el valor isBlock, este tiene el proposito de marcar el valor en true o false si el bloque fue tocado por la bola
     * @return isBlock, representa el booleano que determina la colision entre la bola y un bloque
     */
    bool *getIsBlock() const;

    /**
     * @brief metodo encargado de establecer los colores de los bloques en pantalla
     */
    void setBlockColors();

    /**
     * @brief metodo encargado de establecer la posicion de cada bloque en pantalla
     * @param positions, representa las posiciones de los bloques
     */
    void setBlocksPositions(Vector2f positions);

    /**
     * @brief metodo encargado de contener los tipos de bloques y establece la cantidad de bloques de cada tipo
     */
    void setBlockTypes();

    void setBlockColorsDoble();
};


#endif //BREAKOUT_GAME_CLIENT_GAMEBLOCK_H
