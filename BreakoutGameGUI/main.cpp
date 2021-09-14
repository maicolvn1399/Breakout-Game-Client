#include <iostream>

#include "SocketClient/SocketClient.h"
#include <iostream>
#include "BreakoutGameGUI/GameBreakout.h"
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>


using namespace sf;
using namespace std;


SocketClient* client;

void * clientRun(void *){
    try{
        client->conectar();
    }catch (string ex){
        cout << ex << endl;
    }
    pthread_exit(NULL);
}

int main(){

    //client = new SocketClient;
    //pthread_t hiloClient;
    //pthread_create(&hiloClient,0,clientRun,NULL);
    //pthread_detach(hiloClient);

    //string json = "Hola desde el cliente";

    //while(1){
        //string msn;
        //cin >> msn;
        //if(msn == "salir")
            //break;
        //client->setMensaje(json.c_str());

    //}

    //delete client;


    //init srand
    //srand(static_cast<unsigned>(time(NULL)));

    //Init game engine
    //Game game;


    //Game loop
    //while (game.running()){


        //Update
        //game.update();

        //Render
        //game.render();

        GameBreakout game(800,600,"Breakout");
        game.run();







    //End of application
    return 0;
}

