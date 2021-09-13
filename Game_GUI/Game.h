//
// Created by maxgm on 3/9/21.
//

#pragma once
#ifndef BREAKOUT_GAME_GAME_H
#define BREAKOUT_GAME_GAME_H
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <vector>
#include <ctime>
#include <time.h>
#include "Game_GUI/BarPlayer.h"
#include "Game_GUI/Ball.h"
#include "ListaSimple.h"
using namespace sf;
using namespace std;

//Class that acts as the game engine wrapper class

class Game {
private:
    //Variables
    //Window
    sf::RenderWindow* window;
    sf::VideoMode videoMode;
    sf::Event event;

    //Game objects
    BarPlayer barPlayer;
    //ListaSimple<Ball> balls;
    std::vector<Ball> balls; //Ball Class is store on a vector named balls
    float ballsMS;

    float spawnTimerMax;
    float spawnTimer;
    int maxBalls;



    float movingBallsSpawnTimer;
    float movingBallsSpawnTimerMax;
    int maxMovingBalls;


    vector<CircleShape> movingBalls;
    CircleShape ball;




    //Private functions
    void initializeVariables();
    void initWindow();
    void initBalls();

public:
    //Constructos / Destructors
    Game();
    virtual ~Game();


    //Accessors
    const bool running() const;

    //Functions
    void pollEvents();
    void spawnBalls();
    void spawnMovingBalls();
    void updateMovingBalls();
    void renderMovingBalls();
    void updateCollision();
    void checkCollision();
    void update();
    void render();

};


#endif //BREAKOUT_GAME_GAME_H
