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

    window->setFramerateLimit(60);



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

void GameBreakout::update() {

    if(ball.getSpeed().y == 0.0f){
        Vector2f position = Vector2f(
                bar.getBar().getPosition().x +(bar.getBar().getSize().x/2) - ball.getBall().getRadius(),
                bar.getBar().getPosition().y - bar.getBar().getSize().y);
        ball.setPosition(position);
    }else{
        Vector2f position = Vector2f(
                ball.getBall().getPosition().x + ball.getSpeed().x,
                ball.getBall().getPosition().y + ball.getSpeed().y
                );
        ball.setPosition(position);

    }



}

void GameBreakout::render() {

    window->draw(bar.getBar());
    window->draw(ball.getBall());



}

void GameBreakout::run() {

    while(window->isOpen()){
        while(window->pollEvent(e)){
            event();
        }
        update();
        window->clear(Color::White);
        render();
        window->display();
    }


}