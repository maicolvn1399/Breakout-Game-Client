//
// Created by michael on 26/9/21.
//

#ifndef BREAKOUT_GAME_CLIENT_LINKEDLIST_H
#define BREAKOUT_GAME_CLIENT_LINKEDLIST_H

#include <stddef.h>
#include "Node.h"

/**
 * @brief SimpleList class, contains de logic of the list structure.
 *
 * @tparam DATO, list data type
 */

template<class DATO>

class LinkedList{

public:
    Node<DATO> * start;
    int size = 0;

    LinkedList(){
        start = NULL;
    }

    void insertar(DATO);
    bool estaVacia();
    void eliminar(DATO);
    DATO obtenerPos(int);

};

template<class DATO>
void LinkedList<DATO>::insertar(DATO _data) {
    if(start == NULL){
        start = new Node<DATO>(_data);
        size++;
    }else{
        Node<DATO> * tmp = start;
        while (tmp->next != NULL){
            tmp = tmp->next;
        }
        Node<DATO> * newNode = new Node<DATO>(_data);
        tmp->next = newNode;
        newNode->next = NULL;
        size++;
    }

}

template<class DATO>
bool LinkedList<DATO>::estaVacia() {
    return start == NULL;
}

template<class DATO>
void LinkedList<DATO>::eliminar(DATO _data) {
    if(!estaVacia()){
        if(_data == start->data){
            Node<DATO> * deleted = start;
            start = start->next;
            deleted->next = NULL;
            delete deleted;
            size -= 1;
        }
    }else{
        Node<DATO> * previous_node = start;
        Node<DATO> * tmp;
        tmp = start;
        while (tmp != NULL){
            if(tmp->data == _data){
                previous_node->next = tmp->next;
                tmp->next = NULL;
                delete tmp;
                size -= 1;
            }
            previous_node = tmp;
            tmp = tmp->next;
        }
    }
}

template<class DATO>
DATO LinkedList<DATO>::obtenerPos(int Pos) {
    Node<DATO> *tmp = start;
    int i = 0;
    if(tmp != NULL){
        if(Pos == 0){
            return  tmp->data;
        }
        while (i < Pos && i <= size){
            tmp = tmp->next;
            i += 1;
        }return tmp->data;
    }return tmp->data;
}

#endif //BREAKOUT_GAME_CLIENT_LINKEDLIST_H