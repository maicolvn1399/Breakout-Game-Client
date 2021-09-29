//
// Created by michael on 26/9/21.
//

#ifndef BREAKOUT_GAME_CLIENT_LINKEDLIST_H
#define BREAKOUT_GAME_CLIENT_LINKEDLIST_H

#include <stddef.h>
#include "Node.h"

/**
 * @file LinkedList.h
 * @authors Michael Valverde Navarro
 * @brief Clase que contiene la lógica para implementar una lista simple enlazada
 * @version 1.0
 * @date 28/09/2021
 */

template<class DATO>

class LinkedList{

public:
    Node<DATO> * start;
    int size = 0;

    /**
     * @brief constructor de la clase LinkedList, se instancia una lista vacía, se permite contener objetos de cualquier tipo
     */
    LinkedList(){
        start = NULL;
    }

    /**
     * @brief permite insertar objetos nuevos a la lista
     * @param DATO, tipo de dato que se inserta a la lista
     */
    void insertar(DATO);
    /**
     * @brief revisa si la lista esta vacía
     * @returns true si esta vacia, false en caso contrario
     */
    bool estaVacia();
    /**
    * @brief permite eliminar objetos de la lista
    * @param DATO, dato que se quiere eliminar
    */
    void eliminar(DATO);

    /**
     * @brief obtiene un dato de la lista
     * @param int que representa la posición que se busca obtener
     * @returns el dato que se encuentra en el indice pasado por parametro
     */
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