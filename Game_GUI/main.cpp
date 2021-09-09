#include <iostream>

#include "SocketClient/SocketClient.h"
#include "ListaSimple.h"
#include <iostream>
#include "Game.h"
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>


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

    //Init game engine
    Game game;


    //Game loop
    while (game.running()){


        //Update
        game.update();

        //Render
        game.render();


    }
    //End of application
    return 0;
}
