#include <iostream>

#include "SocketClient/SocketClient.h"
#include <iostream>
#include "BreakoutGameGUI/GameBreakout.h"

#include "SocketClient/Client.h"
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

    /**
    TcpSocket socket;
    char connectionType, mode;
    IpAddress ip = IpAddress::getLocalAddress();
    char buffer[2000];
    size_t received;
    string text = "Connected to: ";

    cout << "Enter (s) for server, enter (c) for client : " << endl;
    cin >> connectionType;

    if(connectionType == 's'){
        TcpListener listener;
        listener.listen(2000);
        listener.accept(socket);
        text += "Server";
        mode = 's';

    }else if(connectionType == 'c'){
        socket.connect(ip,2000);
        text += "Client";
        mode = 'r';

    }
    socket.send(text.c_str(),text.length() +1);

    socket.receive(buffer,sizeof(buffer),received);

    cout << buffer << endl;

    bool done = false;

    while(!done){
        if(mode == 's'){
            getline(cin,text);
            socket.send(text.c_str(),text.length() +1);
            mode = 'r';
        }else if(mode == 'r'){
            socket.receive(buffer, sizeof(buffer), received);
            if(received > 0){
                cout << "Received: " << buffer << endl;
                mode = 's';
            }
        }
    }

    system("pause");
     */




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

        GameBreakout game(800,600,"Breakout");
        game.run();

    return 0;

    //End of application

}

