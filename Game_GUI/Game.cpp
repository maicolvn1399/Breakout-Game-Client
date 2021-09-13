//
// Created by maxgm on 3/9/21.
//

#include <iostream>
#include "Game.h"
#include "Ball.h"
#include "BarPlayer.h"
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

//Private functions
void Game::initializeVariables() {
    this->window = nullptr;
    this->spawnTimerMax = 600; //8,36 seconds
    this->spawnTimer = this->spawnTimerMax;
    this->maxBalls = 5;
    this->ballsMS = 5.f;


    this->movingBallsSpawnTimerMax = 10.f;
    this->movingBallsSpawnTimer = this->movingBallsSpawnTimerMax;
    this->maxMovingBalls = 3;

}

void Game::initWindow() {
    this->videoMode.height = 500;
    this->videoMode.width = 800;
    this->window = new sf::RenderWindow(this->videoMode, "Breakout", sf::Style::Titlebar | sf::Style::Close); //Ventana que tiene un tamana de 800x600, titulo Breakout, que tiene boton de cierre y puede ser expandida
    this->window->setFramerateLimit(60);
}

//Constructors / Destructors
Game::Game() {
    this->initializeVariables();
    this->initWindow();
    this->initBalls();

}

Game::~Game() {
    delete this->window;

}

//Accesors
const bool Game::running() const {
    return this->window->isOpen();
}

//Functions
void Game::pollEvents() { //getIsOpen
    //Event polling
    while (this->window->pollEvent(this->event)){
        switch (this->event.type) {
            case sf::Event::Closed:
                this->window->close();
                break;

        }
    }
}

void Game::spawnBalls() {
    //timer
    if(this->spawnTimer < this->spawnTimerMax)
        this->spawnTimer += 1.f;
    else{
        if(this->balls.size() < this->maxBalls){
            this->balls.push_back(Ball(*this->window));

            this->spawnTimer = 0.f;
        }

    }

}

void Game::updateCollision() { //Check if there is a collision between the ball and the bar.

    //Check the collision
    for (size_t i = 0; i < this->balls.size(); i++){
        if (this->barPlayer.getShape().getGlobalBounds().intersects(this->balls[i].getShape().getGlobalBounds())){
            this->checkCollision();
        }
    }
}
void Game::checkCollision() {
    for (size_t i = 0; i < balls.size(); i++) {
        balls[i].moveBall();
    }

}

void Game::update() {
    /**
     *
     * -Called on main.cpp
     * -Keeps the methods in the mainloop.
     */
    this->pollEvents();

    this->spawnBalls();
    this->barPlayer.update(this->window);
    this->updateCollision();
    for(auto i : this->balls){
        i.update(*this->window);
    }

    this->updateMovingBalls();

}

void Game::render() {
    /*
     * @return void
     * -Clear old frame
     * -render objects
     * -display frame in window
     *
     * Renders the game objects
     */
    this->window->clear(sf::Color::White);

    //Render stuff
    this->barPlayer.render(this->window);

    for(auto i : this->balls){
        i.render(*this->window);
    }

    //Draw game objects

    this->renderMovingBalls();

    this->window->display();

}

void Game::initBalls() {
    this->ball.setPosition(10.f,10.f);
    this->ball.setRadius(20.f);
    this->ball.setFillColor(Color::Cyan);
    this->ball.setOutlineColor(Color::Black);
    this->ball.setOutlineThickness(1.f);

}

void Game::spawnMovingBalls() {

    /**
     * spawn moving balls and set their colors and positions
     * sets a random position
     * sets a random color
     */

    this->ball.setPosition(
            static_cast<float>(rand() % static_cast<int>(this->window->getSize().x - this->ball.getRadius())),
            0.f
            );

    this->ball.setFillColor(Color::Red);
    //Spawn ball
    this->movingBalls.push_back(this->ball);
}

void Game::updateMovingBalls() {

    /**
     * update the moving ball spawn timer and spawn balls
     * when the total amount of ball is smaller than the max
     * moves the balls
     */

    //Updating the timer for moving balls spawning
    if(this->movingBalls.size() < this->maxMovingBalls){
        if(this->movingBallsSpawnTimer>=this->movingBallsSpawnTimerMax){
            //Spawn the ball and set the timer
            this->spawnMovingBalls();
            this->movingBallsSpawnTimer = 0.f;
        }
        else
            this->movingBallsSpawnTimer += 1.f;
    }

    //Moving balls

    float xstep = 2.f;
    float ystep = 2.f;

    for(auto &e : this->movingBalls) {
        e.move(xstep, ystep);
        if(e.getPosition().x >760){
            xstep = -2.f;
        }else if(e.getPosition().x < 0){
            xstep = 2.f;
        }

        if(e.getPosition().y > 480){
            ystep = -2.f;
        }else if(e.getPosition().y < 0){
            ystep = 2.f;
        }
    }
}

void Game::renderMovingBalls() {
    //Rendering balls
    for(auto &e : this->movingBalls){
        this->window->draw(e);
    }

}












