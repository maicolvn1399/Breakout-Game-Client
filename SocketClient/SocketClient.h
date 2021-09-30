//
// Created by michael on 4/9/21.
//
#ifndef BREAKOUT_GAME_CLIENT_SOCKETCLIENT_H
#define BREAKOUT_GAME_CLIENT_SOCKETCLIENT_H

#include <sys/socket.h>
#include <sys/types.h>
#include <netdb.h>
#include <string.h>
#include <string>
#include <iostream>
#include <pthread.h>
#include <vector>
#include <unistd.h>
#include <arpa/inet.h>
using namespace std;


/**
 * @file GameBall.h
 * @authors Michael Valverde Navarro y Max Garro Mora
 * @brief Clase que se encarga de ser el cliente y usa sockets para establecer comunicación con el server
 * @version 1.0
 * @date 4/09/2021
 */

class SocketClient{
public:
    /**
     * @brief Constructor de la clase SocketClient
     */
    SocketClient();
    /**
     * @brief método que conecta el cliente y crea el socket
     */
    void conectar();
    /**
     * @brief método que permite enviar mensajes al server
     */
    void setMensaje(const char* msn);

    /**
     * @brief método que obtiene el mensaje que el cliente recibe por parte del server
     */
    const string &getMessageInfo() const;

    /**
     * @brief método que funciona para modificar información del mensaje que le llega al cliente
     */
    void setMessageInfo(const string &messageInfo);

    string message_info;
    int port;



private:
    int descriptor;
    sockaddr_in info;

    void* Contolador(void* obj);

};

#endif //BREAKOUT_GAME_CLIENT_SOCKETCLIENT_H
