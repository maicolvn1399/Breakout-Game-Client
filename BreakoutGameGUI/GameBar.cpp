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
    //bar.setOrigin(Vector2f (50.f, 10.f));

}

const RectangleShape &GameBar::getBar() const {
    return bar;
}

void GameBar::barMove(Event e, int width, int height, RenderWindow *window) {
    //if(Keyboard::isKeyPressed(Keyboard::Left)){
        //bar.move(-20.f * 1.5f,0.f);

        //if(bar.getPosition().x < 0) {
            //bar.setPosition(Vector2f(0, bar.getPosition().y));
        //}
    //}else if(Keyboard::isKeyPressed(Keyboard::Right)){
        //bar.move(20.f * 1.5f,0.f);

        //if(bar.getPosition().x > 800 - bar.getSize().x){
            //bar.setPosition(Vector2f(800 - bar.getSize().x, bar.getPosition().y));

        //}
        if(e.type == Event::MouseMoved) {
            bar.setPosition(Vector2f(Mouse::getPosition(*window).x - (bar.getSize().x/2), height - 40));

            if(bar.getPosition().x < 0)
                bar.setPosition((Vector2f(0, bar.getPosition().y)));
            else if(bar.getPosition().x > width - bar.getSize().x)
                bar.setPosition(Vector2f(width - bar.getSize().x, bar.getPosition().y));


        }
    }


void GameBar::increaseSize() {
    cout << "Increase bar size" << endl;
     bar.setSize(Vector2f(bar.getSize().x + 15, bar.getSize().y));
}

void GameBar::decreaseSize() {
    cout << "Decrease bar size" << endl;
    if(bar.getSize().x > 70){
        bar.setSize(Vector2f(bar.getSize().x - 15, bar.getSize().y));
    }
}

/*
void GameBar::rotateBar() {
    int contador = 0;
    //if(Keyboard::isKeyPressed(Keyboard::A)){
        //contador += 1;
        //if(contador <= 1){
            //bar.setRotation(-20.f);
        //}else{
            //bar.setRotation(0.f);
            //contador = 0;
        //}
}
 */

void GameBar::rotateBar() {
    cout << "******Rotate bar*******" << endl;

    if(Keyboard::isKeyPressed(Keyboard::A)){
        bar.rotate(-10.f);
    }else if(Keyboard::isKeyPressed(Keyboard::D)){
        bar.rotate(10.f);
    }else{
        bar.setRotation(0.f);
    }



}