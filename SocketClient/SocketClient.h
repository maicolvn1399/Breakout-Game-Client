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


class SocketClient{
public:
    SocketClient();
    void conectar();
    void setMensaje(const char* msn);

    const string &getMessageInfo() const;

    void setMessageInfo(const string &messageInfo);

    string message_info;
    int port;



private:
    int descriptor;
    sockaddr_in info;

    void* Contolador(void* obj);

};

#endif //BREAKOUT_GAME_CLIENT_SOCKETCLIENT_H
