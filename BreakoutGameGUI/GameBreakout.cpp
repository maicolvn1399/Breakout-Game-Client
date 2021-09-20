//
// Created by michael on 13/9/21.
//

#include "GameBreakout.h"
#include "GameBar.h"
#include "iostream"
#include "GameBall.h"
using namespace std;
using namespace sf;


SocketClient* client;

void * clientRun(void *){
    try{
        client->conectar();
    }catch (string ex){
        cout << ex << endl;
    }
    pthread_exit(NULL);
}


GameBreakout::GameBreakout(int w,int h, string title) {

    window = new RenderWindow(VideoMode(w,h),title,Style::Close);
    //window->setFramerateLimit(30);

    block.totalBlocks = (800 / block.getBlock().getSize().x) * (600/block.getBlock().getSize().y);
    block.isBlock = new bool[block.totalBlocks];

    block.wordList = new string[block.totalBlocks];
    block.hitsToBlock = new int[block.totalBlocks];
    block.setFalseValuesToArray();
    block.setBlockTypes();

    /**
    json = "Hola desde el cliente";

    client = new SocketClient;
    pthread_t hiloClient;
    pthread_create(&hiloClient,0,clientRun,NULL);
    pthread_detach(hiloClient);

     */

}

GameBreakout::~GameBreakout() {
    delete[] block.isBlock;
    delete window;
}

void GameBreakout::event() {
    if(e.type == Event::Closed){
        window->close();
    }else if(e.type == Event::MouseMoved){
        bar.bar.setPosition(Vector2f(Mouse::getPosition(*window).x - (bar.bar.getSize().x/2),600 - 40));
    }

    //bar.barMove();

    if(e.type == Event::MouseButtonPressed){
        Vector2f position = Vector2f(
                bar.getBar().getPosition().x +(bar.getBar().getSize().x/2) - ball.getBall().getRadius(),
                bar.getBar().getPosition().y - bar.getBar().getSize().y);
        ball.setPosition(position);
        ball.angleMovement();
    }
}

void GameBreakout::update(float dt) {

    //string msn;
    //cin >> msn;
    //if(msn == "salir")
        //break;
    //client->setMensaje(json.c_str());

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

                    //determina el tipo de bloque con el que choca la bola y determina si lo quita si son bloques
                    //dobles o triples según la cantidad de veces que la bola toque el bloque
                    string blocktype;
                    blocktype = block.wordList[(int)(x + (y * 800 / block.getBlock().getSize().x))];
                    cout << blocktype << endl;
                    if(blocktype == "doble" or blocktype == "triple"){
                        if(block.hitsToBlock[(int)(x + (y * 800 / block.getBlock().getSize().x))] <= 0){
                            block.isBlock[(int)(x + (y * 800 / block.getBlock().getSize().x))] = false;
                            ball.speed.y = abs(ball.speed.y);
                            Vector2f vecPosition = Vector2f(ball.getBall().getPosition().x, (y+1) * block.getBlock().getSize().y);
                            ball.setPosition(vecPosition);
                        }else{
                            block.hitsToBlock[(int)(x + (y * 800 / block.getBlock().getSize().x))] = block.hitsToBlock[(int)(x + (y * 800 / block.getBlock().getSize().x))] -1;
                            ball.speed.y = abs(ball.speed.y);
                            Vector2f vecPosition = Vector2f(ball.getBall().getPosition().x, (y+1) * block.getBlock().getSize().y);
                            ball.setPosition(vecPosition);
                        }
                    }else if(blocktype == "sorpresa"){
                        selectSurprise();
                        block.isBlock[(int)(x + (y * 800 / block.getBlock().getSize().x))] = false;
                        ball.speed.y = abs(ball.speed.y);
                        Vector2f vecPosition = Vector2f(ball.getBall().getPosition().x, (y+1) * block.getBlock().getSize().y);
                        ball.setPosition(vecPosition);
                    }else{
                        block.isBlock[(int)(x + (y * 800 / block.getBlock().getSize().x))] = false;
                        block.hitsToBlock[(int)(x + (y * 800 / block.getBlock().getSize().x))];
                        ball.speed.y = abs(ball.speed.y);
                        Vector2f vecPosition = Vector2f(ball.getBall().getPosition().x, (y+1) * block.getBlock().getSize().y);
                        ball.setPosition(vecPosition);
                    }
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

void GameBreakout::selectSurprise() {
    int number = rand()% 4 + 1;

    cout << "selectSurprise method" << endl;
    cout << to_string(number) << endl;

    if(number == 1){

        //Increase bar size
        bar.increaseSize();

    }else if(number == 2){

        //Decrease bar size
        bar.decreaseSize();

    }else if(number == 3){

        //Increase velocity of ball
        ball.increaseVelocity();

    }else{

        //Decrease velocity of ball
        ball.decreaseVelocity();
    }

}
