//
// Created by michael on 26/9/21.
//

#ifndef BREAKOUT_GAME_CLIENT_NODE_H
#define BREAKOUT_GAME_CLIENT_NODE_H

#include <stddef.h>
#include <stdlib.h>

template<class DATO>

class Node{
public:
    DATO data;
    Node<DATO> * next;

    Node(){
        data;
        next = NULL;
    }

    Node(DATO _data){
        data = _data;
        next = NULL;
    }
    Node(DATO _data, Node<DATO> *_next){
        data = _data;
        next = _next;
    }

    void operator delete(void *p){
        free(p);
    }

    void modify(DATO _data){
        data = _data;
    }

    DATO consult(){
        return data;
    }

};



#endif //BREAKOUT_GAME_CLIENT_NODE_H
