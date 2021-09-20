//
// Created by michael on 13/9/21.
//

#include "GameBar.h"
#include <iostream>
using namespace sf;

GameBar::GameBar() {
    bar.setSize(Vector2f(100.0f,20.0f));
    bar.setFillColor(Color::Black);
    bar.setOutlineThickness(1.0f);
    bar.setOutlineColor(Color::Yellow);
    bar.setPosition(300,560);

}

const RectangleShape &GameBar::getBar() const {
    return bar;
}

void GameBar::barMove() {
    if(Keyboard::isKeyPressed(Keyboard::Left)){
        bar.move(-20.f * 1.5f,0.f);

        if(bar.getPosition().x < 0) {
            bar.setPosition(Vector2f(0, bar.getPosition().y));
        }
    }else if(Keyboard::isKeyPressed(Keyboard::Right)){
        bar.move(20.f * 1.5f,0.f);

        if(bar.getPosition().x > 800 - bar.getSize().x){
            bar.setPosition(Vector2f(800 - bar.getSize().x, bar.getPosition().y));

        }
    }


}

void GameBar::increaseSize() {
    cout << "Increase bar size" << endl;
     bar.setSize(Vector2f(bar.getSize().x + 10, bar.getSize().y));
}

void GameBar::decreaseSize() {
    cout << "Decrease bar size" << endl;
    if(bar.getSize().x > 80){
        bar.setSize(Vector2f(bar.getSize().x - 10, bar.getSize().y));
    }

}
