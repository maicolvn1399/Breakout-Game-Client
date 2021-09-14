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

    int totalBlocks = static_cast <int>((w /  block.getBlock().getSize().x) * (h / block.getBlock().getSize().y));
    isBlock = new bool[totalBlocks];
    for(int i = 0; i < totalBlocks; i++){
        isBlock[i] = false;
    }
    for(int i = 0; i < 160; i++){
        isBlock[i] = true;
    }
}

GameBreakout::~GameBreakout() {


    delete[] isBlock;
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
        ball.boundariesCollision();
    }
}

void GameBreakout::render() {

    for(int y = 0; y < height; y += block.block.getSize().y){
        for(int x = 0; x < width; x += block.block.getSize().x){
            if(isBlock[(int)((x / block.block.getSize().x) + ((y / block.block.getSize().y) * (width / block.getBlock().getSize().x)))]){

                block.block.setFillColor(Color(255, 100, 50));
                block.block.setOutlineColor(Color(255, 255, 255));

                block.block.setPosition(Vector2f(x, y));
                window->draw(block.getBlock());

            }
            else{
                block.block.setFillColor(Color(rand() % (10 + (y/16)), rand() % (10 + (y/16)), rand()%10));
                block.block.setOutlineColor(Color(40, 40, 40));
            }
            block.block.setPosition(Vector2f(x, y));
            window->draw(block.getBlock());
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