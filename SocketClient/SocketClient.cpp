//
// Created by michael on 4/9/21.
//

#include "SocketClient.h"


SocketClient::SocketClient(){

}

void SocketClient::conectar() {
    //Crear descriptor
    descriptor = socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
    if(descriptor < 0) //valida creación de socket
        cout << "Error al crear el socket " << endl;


    info.sin_family = AF_INET;// tipo de conexion ipv4
    info.sin_addr.s_addr = inet_addr("127.0.0.1"); //aceptamos a cualquier cliente
    info.sin_port = ntohs(port);//define el puerto
    memset(&info.sin_zero,0,sizeof(info.sin_zero)); //limpia la estructura

    if(connect(descriptor,(sockaddr *)&info,(socklen_t)sizeof(info)) < 0){
        cout << "Error al conectarse con el servidor" << endl;

    }
    cout << "Se ha conectado correctamente" << endl;
    //pthread_t hilo;
    //pthread_create(&hilo,0,SocketClient::Contolador,(void *)this);
    //pthread_detach(hilo);
    Contolador((void *)this);
}

void *SocketClient::Contolador(void *obj) {
    SocketClient *c = (SocketClient *)obj;
    while(true){

        string mensaje;
        char buffer[1024] = {0};
        //poner condicion cuando el juego termina para cerrar el bucle
        while(1){
            memset(buffer,0,1024);
            int bytes = recv(c->descriptor,buffer,1024,0);
            mensaje.append(buffer,bytes);
            if(bytes <= 0){
                close(c->descriptor);
                pthread_exit(NULL);
            }
            if(bytes < 1024){
                break;
            }
        }
        cout << mensaje << endl;
        setMessageInfo(mensaje);

        //aca se puede enviar mensajes para otra clase o para el servidor
    }
    close(c->descriptor);
    pthread_exit(NULL);
}

void SocketClient::setMensaje(const char *msn) {
    send(descriptor,msn, strlen(msn),0);
}

const string &SocketClient::getMessageInfo() const {
    return message_info;
}

void SocketClient::setMessageInfo(const string &messageInfo){
    message_info = messageInfo;
}
