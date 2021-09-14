//
// Created by michael on 13/9/21.
//

#include "GameBreakout.h"
#include "GameBar.h"
#include "GameBall.h"
using namespace std;
using namespace sf;


GameBreakout::GameBreakout(int w,int h, string title) {
    window = new RenderWindow(VideoMode(w,h),title,Style::Close);
    window->setFramerateLimit(30);
}

GameBreakout::~GameBreakout() {

    delete window;
}

void GameBreakout::event() {
    if(e.type == Event::Closed)
        window->close();

    bar.barMove();

    if(e.type == Event::MouseButtonPressed){
        Vector2f position = Vector2f(
                bar.getBar().getPosition().x +(bar.getBar().getSize().x/2) - ball.getBall().getRadius(),
                bar.getBar().getPosition().y - bar.getBar().getSize().y);
        ball.setPosition(position);
        ball.angleMovement();
    }



}

void GameBreakout::update(float dt) {

    if(ball.getSpeed().y == 0.0f){
        Vector2f position = Vector2f(
                bar.getBar().getPosition().x +(bar.getBar().getSize().x/2) - ball.getBall().getRadius(),
                bar.getBar().getPosition().y - bar.getBar().getSize().y);
        ball.setPosition(position);
    }else{
        Vector2f position = Vector2f(
                ball.getBall().getPosition().x + (ball.getSpeed().x * dt),
                ball.getBall().getPosition().y + (ball.getSpeed().y * dt)
                );
        ball.setPosition(position);

    }



}

void GameBreakout::render() {

    window->draw(bar.getBar());
    window->draw(ball.getBall());



}

void GameBreakout::run() {

    Clock gameClock;
    float deltaTime = 0.0f;

    while(window->isOpen()){
        gameClock.restart();
        while(window->pollEvent(e)){
            event();
        }
        update(deltaTime);
        window->clear(Color::White);
        render();
        window->display();

        deltaTime = gameClock.getElapsedTime().asSeconds();
    }


}