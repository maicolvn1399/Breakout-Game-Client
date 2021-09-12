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

}

void Game::initWindow() {
    this->videoMode.height = 800;
    this->videoMode.width = 1000;
    this->window = new sf::RenderWindow(this->videoMode, "Breakout", sf::Style::Titlebar | sf::Style::Close); //Ventana que tiene un tamana de 800x600, titulo Breakout, que tiene boton de cierre y puede ser expandida
    this->window->setFramerateLimit(60);
}

//Constructors / Destructors
Game::Game() {
    this->initializeVariables();
    this->initWindow();

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
    this->pollEvents();

    this->spawnBalls();
    this->barPlayer.update(this->window);
    this->updateCollision();
    for(auto i : this->balls){
        i.update(*this->window);
    }

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
    this->window->display();

}












