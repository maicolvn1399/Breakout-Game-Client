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

/**
 * @file GameBar.h
 * @authors Michael Valverde Navarro y Max Garro Mora
 * @brief clase que se encarga de crear la barra y establecer su tamano, velocidad de movimiento, posicion inicial, entre otros
 * @version 2.0
 * @date 13/09/2021
 */

class GameBar{

public:
    RectangleShape bar;

public:

    /**
     * @brief constructor de la clase GameBar
     */
    GameBar();
    //RenderWindow* window = NULL;
    int width;
    int height;

    /**
     * @brief metodo encargado de retornar la barra
     * @return bar, representa la barra
     */
    const RectangleShape &getBar() const;

    /**
     * @brief metodo encargado de detectar un evento en el que se mueve el mouse, para asi mover la barra
     * @param e, representa el evento
     * @param width, representa el ancho de la pantalla
     * @param height, representa la altura de la pantalla
     * @param window, representa la direccion de memoria de la pantalla
     */
    void barMove(Event e, int width, int height, RenderWindow *window);

    /**
     * @brief metodo encargado de aumentar el tamano de la barra, este se llama cuando se destruye un bloque sorpresa
     */
    void increaseSize();

    /**
     * @brief metodo encargado de disminuir el tamano de la barra, este se llama cada vez que una bola cae en la parte inferior de la pantalla
     */
    void decreaseSize();

    void rotateBar();
};


#endif //BREAKOUT_GAME_CLIENT_GAMEBAR_H
