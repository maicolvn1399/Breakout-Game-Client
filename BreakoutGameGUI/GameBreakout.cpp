//
// Created by michael on 13/9/21.
//

#include "GameBreakout.h"
#include "GameBar.h"
#include "iostream"
#include <cstdio>
#include <jsoncpp/json/value.h>
#include <jsoncpp/json/json.h>
#include <jsoncpp/json/reader.h>
#include <jsoncpp/json/writer.h>


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

GameBreakout::GameBreakout(int w,int h, string title, string name, string portNumber) {



    window = new RenderWindow(VideoMode(w,h),title,Style::Close);

    //window->setFramerateLimit(30);
    //#######

    block.totalBlocks = (800 / block.getBlock().getSize().x) * (600/block.getBlock().getSize().y);
    block.isBlock = new bool[block.totalBlocks];

    block.wordList = new string[block.totalBlocks];
    block.hitsToBlock = new int[block.totalBlocks];
    block.blockColorList = new int[block.totalBlocks];
    block.setFalseValuesToArray();
    block.setBlockTypes();

    font.loadFromFile("../hinted-CelloSans-Regular.ttf");
    score.setFont(font);
    score.setOutlineThickness(2.0f);
    score.setOutlineColor(Color::Black);
    score.setPosition(Vector2f(0,0));

    score.setString("0");

    //font2.loadFromFile("../hinted-CelloSans-Regular.ttf");
    nombre.setFont(font);
    nombre.setOutlineThickness(2.0f);
    nombre.setOutlineColor(Color::Black);
    nombre.setPosition(Vector2f(500, 0));
    playerName = name;

    nombre.setString(playerName);


    textureImage.loadFromFile("../bg_2.jpg");
    spriteImage.setTexture(textureImage);

    ballsList = new GameBall[3];
    for(int i = 0; i < 3; i++ ){
        ballsList[i] = ball;
    }


    int portInInteger = stoi(portNumber);

    //rotate condition
    rotateCondition = false;


    client = new SocketClient;
    client->port = portInInteger;
    pthread_t hiloClient;
    pthread_create(&hiloClient,0,clientRun,NULL);
    pthread_detach(hiloClient);
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

        if(bar.bar.getPosition().x < 0)
            bar.bar.setPosition(Vector2f(0, bar.bar.getPosition().y));
        else if(bar.bar.getPosition().x > 800 - bar.bar.getSize().x)
            bar.bar.setPosition(Vector2f(800 - bar.bar.getSize().x, bar.bar.getPosition().y));
    }

    bar.rotateBar();

    if(e.type == Event::MouseButtonPressed){
        for(int i = 0; i < 3; i++){
            Vector2f position = Vector2f(
                    bar.getBar().getPosition().x +(bar.getBar().getSize().x/2) - ballsList[i].getBall().getRadius(),
                    bar.getBar().getPosition().y - bar.getBar().getSize().y);
            ballsList[i].setPosition(position);
            ballsList[i].angleMovement();
        }
    }
}

void GameBreakout::update(float dt) {

    for(int i = 0; i < 3; i++){
        if(ballsList[i].getSpeed().y == 0.0f){
            Vector2f position = Vector2f(
                    bar.getBar().getPosition().x +(bar.getBar().getSize().x/2) - ballsList[i].getBall().getRadius(),
                    bar.getBar().getPosition().y - bar.getBar().getSize().y);
            ballsList[i].setPosition(position);

        }else{
            Vector2f position = Vector2f(
                    ballsList[i].getBall().getPosition().x + (ballsList[i].getSpeed().x * dt),
                    ballsList[i].getBall().getPosition().y + (ballsList[i].getSpeed().y * dt)
            );
            ballsList[i].setPosition(position);

            //Ball boundaries collision
            ballsList[i].boundariesCollision(bar); //kk
            //bar.decreaseSize();
        }
    }
    //Ball-Bar collision
    for(int i = 0; i < 3; i++) {
        if (ballsList[i].getBall().getPosition().x + (ballsList[i].getBall().getRadius() * 2.0f) >= bar.getBar().getPosition().x
            && ballsList[i].getBall().getPosition().y + (ballsList[i].getBall().getRadius() * 2.0f) >= bar.getBar().getPosition().y
            && ballsList[i].getBall().getPosition().x < bar.getBar().getPosition().x + bar.getBar().getSize().x
            && ballsList[i].getBall().getPosition().y < bar.getBar().getPosition().y + bar.getBar().getSize().y) {
            ballsList[i].moveFaster();

            ballsList[i].setPosition(Vector2f(ballsList[i].getBall().getPosition().x,
                                      bar.getBar().getPosition().y - (ballsList[i].getBall().getRadius() * 2.0f)));
            ballsList[i].speed.y = -(abs(ballsList[i].getSpeed().y));

            //En caso de tocar la sorpresa rotate
        } else if (bar.getBar().getGlobalBounds().intersects(ballsList[i].getBall().getGlobalBounds()) and
                   rotateCondition == true) {
            ballsList[i].setPosition(Vector2f(ballsList[i].getBall().getPosition().x,
                                      bar.getBar().getPosition().y - (ballsList[i].getBall().getRadius() * 2.0f)));
            ballsList[i].speed.y = -(abs(ballsList[i].getSpeed().y));
        }
    }


    //Ball-Block Collision
    for(int i = 0; i < 3; i++) {
        for (int y = 0; y < 600 / block.getBlock().getSize().y; y++) {
            for (int x = 0; x < 800 / block.getBlock().getSize().x; x++) {
                if (block.isBlock[(int) (x + (y * (800 / block.getBlock().getSize().x)))]) {

                    if (ballsList[i].getBall().getPosition().x + (ballsList[i].getBall().getRadius() * 2.0f) >=
                        x * block.getBlock().getSize().x
                        && ballsList[i].getBall().getPosition().y + (ballsList[i].getBall().getRadius() * 2.0f) >=
                           y * block.getBlock().getSize().y
                        && ballsList[i].getBall().getPosition().x < (x + 1) * (block.getBlock().getSize().x)
                        && ballsList[i].getBall().getPosition().y < (y + 1) * (block.getBlock().getSize().y)) {

                        //Score
                        int scoreInInterger = std::stoi(((std::string) (score.getString())).c_str());

                        //determina el tipo de bloque con el que choca la bola y determina si lo quita si son bloques
                        //dobles o triples según la cantidad de veces que la bola toque el bloques
                        string blocktype;

                        blocktype = block.wordList[(int) (x + (y * 800 / block.getBlock().getSize().x))];

                        cout << blocktype << endl;

                        string blocktype_json = "\"" + blocktype + "\"";
                        string json_;
                        Json::Reader reader;

                        json_ = "{\"info\" : " + blocktype_json + "}";
                        reader.parse(json_.c_str(), root);
                        //cout << "Blocktype json: " << root["blocktype"] << endl;
                        //cout << json_ << endl;
                        //client->setMensaje(json_.c_str());
                        //cout << "Client get message : " << client->getMessageInfo()<< endl;

                        if (blocktype == "doble" or blocktype == "triple") {
                            if (block.hitsToBlock[(int) (x + (y * 800 / block.getBlock().getSize().x))] <= 0) {
                                block.isBlock[(int) (x + (y * 800 / block.getBlock().getSize().x))] = false;
                                ballsList[i].speed.y = abs(ballsList[i].speed.y);
                                Vector2f vecPosition = Vector2f(ballsList[i].getBall().getPosition().x,
                                                                (y + 1) * block.getBlock().getSize().y);
                                ballsList[i].setPosition(vecPosition);

                                cout << to_string((int) (x + (y * 800 / block.getBlock().getSize().x))) << endl;

                                //Send to the server
                                string blocktype_json = "\"" + blocktype + "\"";
                                string json_;
                                Json::Reader reader;

                                json_ = "{\"info\" : " + blocktype_json + "}";
                                reader.parse(json_.c_str(), root);
                                //cout << "Blocktype json: " << root["blocktype"] << endl;
                                //###
                                cout << json_ << endl;

                                client->setMensaje(json_.c_str());

                                cout << "Client get message : " << client->getMessageInfo() << endl;

                                string receivedMessage;

                                receivedMessage = client->getMessageInfo();

                                reader.parse(receivedMessage, root);


                                cout << root["block_points"].asString() << endl;

                                //scoreInInterger += stoi(root["block_points"].asString());
                                //score.setString(std::to_string(scoreInInterger));

                                //if (blocktype == "doble") {

                                //scoreInInterger += 15;
                                //score.setString(std::to_string(scoreInInterger));
                                //} else {

                                //scoreInInterger += 20;
                                //score.setString(std::to_string(scoreInInterger));
                                //}
                            } else {
                                block.hitsToBlock[(int) (x + (y * 800 / block.getBlock().getSize().x))] =
                                        block.hitsToBlock[(int) (x + (y * 800 / block.getBlock().getSize().x))] - 1;
                                ballsList[i].speed.y = abs(ballsList[i].speed.y);
                                Vector2f vecPosition = Vector2f(ballsList[i].getBall().getPosition().x,
                                                                (y + 1) * block.getBlock().getSize().y);
                                ballsList[i].setPosition(vecPosition);
                            }
                        } else if (blocktype == "sorpresa") {
                            selectSurprise();
                            block.isBlock[(int) (x + (y * 800 / block.getBlock().getSize().x))] = false;
                            ballsList[i].speed.y = abs(ballsList[i].speed.y);
                            Vector2f vecPosition = Vector2f(ballsList[i].getBall().getPosition().x,
                                                            (y + 1) * block.getBlock().getSize().y);
                            ballsList[i].setPosition(vecPosition);

                            cout << to_string((int) (x + (y * 800 / block.getBlock().getSize().x))) << endl;


                            string blocktype_json = "\"" + blocktype + "\"";
                            string json_;
                            Json::Reader reader;

                            json_ = "{\"info\" : " + blocktype_json + "}";
                            reader.parse(json_.c_str(), root);
                            //cout << "Blocktype json: " << root["blocktype"] << endl;
                            cout << json_ << endl;

                            client->setMensaje(json_.c_str());

                            cout << "Client get message : " << client->getMessageInfo() << endl;

                            string receivedMessage;

                            receivedMessage = client->getMessageInfo();

                            reader.parse(receivedMessage, root);

                            cout << root["block_points"].asString() << endl;

                            //scoreInInterger += stoi(root["block_points"].asString());
                            //score.setString(std::to_string(scoreInInterger));


                        } else if (blocktype == "interno") {
                            ballsList[i].speed.y = abs(ballsList[i].speed.y);
                            Vector2f vecPosition = Vector2f(ballsList[i].getBall().getPosition().x,
                                                            (y + 1) * block.getBlock().getSize().y);
                            ballsList[i].setPosition(vecPosition);

                            if (ballsList[i].profundidad > 0) {
                                //scoreInInterger += 30;
                                //score.setString(std::to_string(scoreInInterger));
                                block.isBlock[(int) (x + (y * 800 / block.getBlock().getSize().x))] = false;


                            }
                            cout << to_string((int) (x + (y * 800 / block.getBlock().getSize().x))) << endl;

                            string blocktype_json = "\"" + blocktype + "\"";
                            string json_;
                            Json::Reader reader;

                            json_ = "{\"info\" : " + blocktype_json + "}";
                            reader.parse(json_.c_str(), root);
                            //cout << "Blocktype json: " << root["blocktype"] << endl;
                            cout << json_ << endl;

                            client->setMensaje(json_.c_str());
                            cout << "Client get message : " << client->getMessageInfo() << endl;

                            string receivedMessage;
                            receivedMessage = client->getMessageInfo();
                            reader.parse(receivedMessage, root);
                            cout << root["block_points"].asString() << endl;

                            //scoreInInterger += stoi(root["block_points"].asString());
                            //score.setString(std::to_string(scoreInInterger));

                        } else if (blocktype == "profundo") {
                            ballsList[i].profundidad += 1;
                            ballsList[i].speed.y = abs(ballsList[i].speed.y);
                            Vector2f vecPosition = Vector2f(ballsList[i].getBall().getPosition().x,
                                                            (y + 1) * block.getBlock().getSize().y);
                            ballsList[i].setPosition(vecPosition);
                            if (ballsList[i].profundidad >= 2) {
                                block.isBlock[(int) ((x + (y * 800 / block.getBlock().getSize().x)) -
                                                     26 * ballsList[i].profundidad)] = false;
                                ballsList[i].speed.y = abs(ballsList[i].speed.y);
                                Vector2f vecPosition = Vector2f(ballsList[i].getBall().getPosition().x,
                                                                (y + 1) * block.getBlock().getSize().y);
                                ballsList[i].setPosition(vecPosition);
                                ballsList[i].profundidad = 0;
                            }
                            cout << to_string((int) (x + (y * 800 / block.getBlock().getSize().x))) << endl;

                        } else {
                            block.isBlock[(int) (x + (y * 800 / block.getBlock().getSize().x))] = false;
                            block.hitsToBlock[(int) (x + (y * 800 / block.getBlock().getSize().x))];
                            ballsList[i].speed.y = abs(ballsList[i].speed.y);
                            Vector2f vecPosition = Vector2f(ballsList[i].getBall().getPosition().x,
                                                            (y + 1) * block.getBlock().getSize().y);
                            ballsList[i].setPosition(vecPosition);

                            cout << to_string((int) (x + (y * 800 / block.getBlock().getSize().x))) << endl;

                            string blocktype_json = "\"" + blocktype + "\"";
                            string json_;
                            Json::Reader reader;
                            Json::Value root;

                            json_ = "{\"info\" : " + blocktype_json + "}";
                            reader.parse(json_.c_str(), root);
                            //cout << "Blocktype json: " << root["blocktype"] << endl;
                            cout << json_ << endl;
                            string receivedMessage;
                            client->setMensaje(json_.c_str());
                            cout << "Client get message : " << client->getMessageInfo() << endl;
                            receivedMessage = client->getMessageInfo();

                            reader.parse(receivedMessage, root);
                            cout << root["block_points"].asString() << endl;

                            //scoreInInterger += stoi(root["block_points"].asString());
                            //score.setString(std::to_string(scoreInInterger));
                        }
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

                switch (block.blockColorList[(int)(((x / block.getBlock().getSize().x)) + ((y/block.getBlock().getSize().y) * (800 / block.getBlock().getSize().x)))]) {
                    case 1:
                        block.setBlockColors();
                        break;
                    case 2:
                        block.block.setFillColor(Color(166,45,65));
                        block.block.setOutlineColor(Color(255,255,255));
                        break;
                    case 3:
                        block.block.setFillColor(Color(47,166,45));
                        block.block.setOutlineColor(Color(255,255,255));
                        break;
                    case 4:
                        block.block.setFillColor(Color(45,51,166));
                        block.block.setOutlineColor(Color(255,255,255));
                        break;
                    case 5:
                        block.block.setFillColor(Color(93,94,107));
                        block.block.setOutlineColor(Color(255,255,255));
                        break;
                    case 6:
                        block.block.setFillColor(Color(110,22,130));
                        block.block.setOutlineColor(Color(255,255,255));
                        break;
                }


                Vector2f blockPosition = Vector2f(x,y);
                block.setBlocksPositions(blockPosition);
                window->draw(block.getBlock());
            }
        }
    }
    window->draw(bar.getBar());
    for(int i = 0; i < 3; i++){
        window->draw(ballsList[i].getBall());
    }
    window->draw(score);
    window->draw(nombre);
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
        window->draw(spriteImage);
        render();
        window->display();

        deltaTime = gameClock.getElapsedTime().asSeconds();
    }
}

void GameBreakout::selectSurprise() {

    int number = rand() % 5 + 1;
    cout << "selectSurprise method" << endl;
    cout << to_string(number) << endl;

    if (number == 1) {
        //Increase bar size
        bar.increaseSize();
        rotateCondition = false;
    } else if (number == 2) {
        //Decrease bar size
        bar.decreaseSize();
        rotateCondition = false;
    } else if (number == 3) {
        //Increase velocity of ball
        ball.increaseVelocity();
        rotateCondition = false;
    }else if(number == 4){
        //rotate bar
        bar.rotateBar();
        rotateCondition = true;
    }else{
        //Decrease velocity of ball
        ball.decreaseVelocity();
        rotateCondition = false;
    }
}
