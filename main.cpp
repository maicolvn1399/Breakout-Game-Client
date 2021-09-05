#include <iostream>

#include "SocketClient/SocketClient.h"

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

    client = new SocketClient;
    pthread_t hiloClient;
    pthread_create(&hiloClient,0,clientRun,NULL);
    pthread_detach(hiloClient);

    string json = "Hola desde el cliente";

    while(1){
        string msn;
        cin >> msn;
        if(msn == "salir")
            break;
        client->setMensaje(json.c_str());

    }

    delete client;
    return 0;
}
