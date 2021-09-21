//
// Created by michael on 13/9/21.
//

#ifndef BREAKOUT_GAME_CLIENT_GAMEBALL_H
#define BREAKOUT_GAME_CLIENT_GAMEBALL_H

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include "GameBar.h"
using namespace sf;
using namespace std;

/**
 * @file GameBall.h
 * @authors Michael Valverde Navarro y Max Garro Mora
 * @brief Clase que se encarga de crear la bola, establecer su posicion inicial y velocidad durante el juego.
 * @version 2.0
 * @date 13/09/2021
 */

class GameBall{
public:
    CircleShape ball;
    float defaultSpeed;
    float angle;
    float speedFactor;
    Vector2f speed;

public:
    /**
     * @brief Constructor de la clase GameBall
     */
    GameBall();

    /**
     * @brief metodo que se encarga de retornar el objeto ball
     * @return ball, representa el objeto bola
     */
    const CircleShape &getBall() const;

    /**
     * @brief metodo encargado de establecer la posicion de la bola
     * @param pos, representa la posicion de la bola
     */
    void setPosition(Vector2f pos);

    /**
     * @brief metodo que utiliza algebra y trigonometria para el movimiento angular de la bola
     */
    void angleMovement();

    /**
     * @brief metodo encargado de establecer la accion que hara la bola cuando haya colisionado en cierto lugar de la pantalla
     * @param bar, se le ingresa la barra para que establezca sus limites
     */
    void boundariesCollision(GameBar bar);

    /**
     * @brief metodo encargado de aumentar en 2 a la velocidad
     */
    void increaseVelocity();

    /**
     * @brief metodo encargado de disminuir en 2 a la velocidad de la bola
     */
    void decreaseVelocity();

    /**
     * @brief metodo encargado de aumentar la velocidad, es usado en la colision bola-barra porque con la intencion que cada vez que haya una colision entre ellos dos, la velocidad aumente
     */
    void moveFaster();

    /**
     * @brief metodo encargado de retornar la velocidad inicial establecida
     * @return defaultSpeed, representa la velocidad con la que empieza la bola
     */
    float getDefaultSpeed() const;

    /**
     * @brief metodo encargado de retornar el angulo establecido
     * @return angle, representa el angulo establecido
     */
    float getAngle() const;

    /**
     * @brief metodo encargado de retornar la velocidad de la bola
     * @return speed, representa la velocidad de la bola
     */
    const Vector2f &getSpeed() const;

};

#endif //BREAKOUT_GAME_CLIENT_GAMEBALL_H
