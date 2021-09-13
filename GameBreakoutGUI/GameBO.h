//
// Created by michael on 12/9/21.
//

#ifndef BREAKOUT_GAME_CLIENT_GAMEBO_H
#define BREAKOUT_GAME_CLIENT_GAMEBO_H

#include <iostream>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <math.h>
#include <algorithm>
#include <iostream>
#include <sstream>

#define PI   3.14159265358979323846



using namespace sf;
using namespace std;

class GameBO{

private:
    static const int FRAMES_PER_SECOND = 60;
    static const int MAX_FRAMESKIP = 10;
    static const int width = 640;
    static const int height= 480;
    static const int borderSize= 12;
    static const int margin = 50;
    static const int moveDistance = 40;


    RenderWindow window;
    Font font;

    RectangleShape top;
    RectangleShape left;
    RectangleShape right;
    RectangleShape bottom;


    //RectangleShape ball;
    //Vector2f ballSpeed;
    //RectangleShape player;

    Text title;
    Text start;
    Text won;
    Text lost;
    Text score;
    Text lives;
    Text fps;


    //Grid grid;

    Time time;
    Int32 updateTime;

    unsigned int playerScore;
    unsigned int playerLives;

    enum states {INTRO, PLAYING, GAME_WON, GAME_LOST};

    int gameState;

public:
    GameBO();
    bool init();
    int exec();

private:
    void processEvents();
    void update();
    void setup();
    void display();
    void updatePlayer();
    void updateBall();
    void checkCollisions();
    void resetGame();
    void resetBall();

};


#endif //BREAKOUT_GAME_CLIENT_GAMEBO_H
