//
// Created by michael on 13/9/21.
//

#ifndef BREAKOUT_GAME_CLIENT_GAMEBREAKOUT_H
#define BREAKOUT_GAME_CLIENT_GAMEBREAKOUT_H

#include "GameBall.h"
#include "GameBar.h"
#include "GameBlock.h"
#include <jsoncpp/json/value.h>
#include <jsoncpp/json/json.h>
#include <jsoncpp/json/reader.h>
#include <jsoncpp/json/writer.h>
#include "SocketClient/SocketClient.h"
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
using namespace sf;
using namespace std;

/**
 * @file GameBreakout.h
 * @authors Michael Valverde Navarro y Max Garro Mora
 * @brief Clase que se encarga de mostrar los objetos en la ventana y contiene toda la logica de la interfaz grafica
 * @version 2.0
 * @date 13/09/2021
 */

class GameBreakout{


public:

    /**
     * @brief constructor de la clase GameBreakout, en el que se inicializan la ventana, los bloques, el puntaje, entre  otros
     * @param w, representa el ancho de la ventana del programa
     * @param h, reoresenta la altura de la ventana del programa
     * @param title, representa el titulo del juego
     */
    GameBreakout(int w,int h, string title, string name, string portNumber);

    /**
     * @brief destructor de la clase GameBreakout, encargado de borrar los bloques y cerrar la ventana
     */
    ~GameBreakout();

    /**
     * @brief metodo encargado de detectar los eventos sucedidos en el juego, para asi mover el mouse o impulsar la bola con un click al principio
     */
    void event();

    /**
     * @brief metodo encargado de detectar las colisiones entre bola-limites de pantalla, barra-bola y barra-bloque
     * @param dt, representa el deltaTime
     */
    void update(float dt);

    /**
     * @brief metodo encargado de mostrar los bloques, la barra, la bola y el puntaje
     */
    void render();

    /**
     * @brief metodo encargado de ejecutar todos los metodos del juego mientras que la ventana este abierta
     */
    void run();

    /**
     * @brief metodo encargado de seleccionar aleatoriamente las sorpresas: incrementar el tamano de la barra, disminuir el tamano de la barra, auemntar la velocidad de la bola y disminuir la velocidad de la bola
     */
    void selectSurprise();

private:

    RenderWindow* window = NULL;
    Event e;
    int width;
    int height;
    Font font;
    String playerName;
    int port;
    bool rotateCondition;
    Text nombre;
    Text score;
    GameBall ball;
    GameBar bar;
    GameBlock block;
    string json;
    Json::Value root;
    Texture textureImage;
    Sprite spriteImage;
    GameBall * ballsList;

};

#endif //BREAKOUT_GAME_CLIENT_GAMEBREAKOUT_H
