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
    //window->setFramerateLimit(30);

    block.totalBlocks = (800 / block.getBlock().getSize().x) * (600/block.getBlock().getSize().y);
    block.isBlock = new bool[block.totalBlocks];

    block.setFalseValuesToArray();
}

GameBreakout::~GameBreakout() {
    delete[] block.isBlock;
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

        //Ball boundaries collision
        ball.boundariesCollision(bar);
    }
    //Ball-Bar collision
    if(ball.getBall().getPosition().x + (ball.getBall().getRadius() * 2.0f) >= bar.getBar().getPosition().x
    && ball.getBall().getPosition().y + (ball.getBall().getRadius() * 2.0f) >= bar.getBar().getPosition().y
    && ball.getBall().getPosition().x < bar.getBar().getPosition().x + bar.getBar().getSize().x
    && ball.getBall().getPosition().y < bar.getBar().getPosition().y + bar.getBar().getSize().y)
    {
        ball.setPosition(Vector2f(ball.getBall().getPosition().x, bar.getBar().getPosition().y - (ball.getBall().getRadius() * 2.0f)));
        ball.speed.y = -(abs(ball.getSpeed().y));

    }



    //Ball-Block Collision
    for(int y = 0; y < 600/block.getBlock().getSize().y; y++){
        for(int x = 0; x < 800 / block.getBlock().getSize().x; x++){
            if(block.isBlock[(int)(x + (y * (800 / block.getBlock().getSize().x)))]){

                if(ball.getBall().getPosition().x + (ball.getBall().getRadius() * 2.0f) >= x * block.getBlock().getSize().x
                   && ball.getBall().getPosition().y + (ball.getBall().getRadius() * 2.0f) >= y * block.getBlock().getSize().y
                   && ball.getBall().getPosition().x < (x+1) * (block.getBlock().getSize().x)
                   && ball.getBall().getPosition().y < (y+1) * (block.getBlock().getSize().y)){

                    block.isBlock[(int)(x + (y * 800 / block.getBlock().getSize().x))] = false;
                    ball.speed.y = abs(ball.speed.y);
                    Vector2f vecPosition = Vector2f(ball.getBall().getPosition().x, (y+1) * block.getBlock().getSize().y);
                    ball.setPosition(vecPosition);

                }
            }

        }
    }

}

void GameBreakout::render() {

    for(int y = 0; y < 600; y += block.getBlock().getSize().y){
        for(int x = 0; x < 800; x += block.getBlock().getSize().y){
            if(block.isBlock[(int)(((x / block.getBlock().getSize().x)) + ((y/block.getBlock().getSize().y) * (800 / block.getBlock().getSize().x)))]){

                block.setBlockColors();
                Vector2f blockPosition = Vector2f(x,y);
                block.setBlocksPositions(blockPosition);
                window->draw(block.getBlock());
            }
        }
    }

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