#include <iostream>

#include "SocketClient/SocketClient.h"
#include <iostream>
#include "BreakoutGameGUI/GameBreakout.h"
#include "DataStructure/LinkedList.h"

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <string>
#include <iostream>


using namespace sf;
using namespace std;

/**
SocketClient* client;

void * clientRun(void *){
    try{
        client->conectar();
    }catch (string ex){
        cout << ex << endl;
    }
    pthread_exit(NULL);
}
*/

int main(){

    //Client* client = new Client();
    //client->initClient();


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

        string name;
        cout << "Ingrese su nombre: ";
        getline(cin, name);

        string portNumber;
        cout << "Ingrese el puerto a conectarse (4050) : " << endl;
        getline(cin, portNumber);


        GameBreakout game(800,600,"Breakout", name, portNumber);
        game.run();


    return 0;

    //End of application

}