//
// Created by michael on 26/9/21.
//

#ifndef BREAKOUT_GAME_CLIENT_NODE_H
#define BREAKOUT_GAME_CLIENT_NODE_H

#include <stddef.h>
#include <stdlib.h>

/**
 * @file Node.h
 * @authors Michael Valverde Navarro
 * @brief Clase que contiene la lógica para implementar un nodo que forma parte de la estructura de datos lista simple enlazada
 * @version 1.0
 * @date 28/09/2021
 */

template<class DATO>

class Node{
public:
    DATO data;
    Node<DATO> * next;

    /**
     * @brief constructor de la clase Node, se instancia una estructura que sirve para contener los datos de la lista
     */
    Node(){
        data;
        next = NULL;
    }

    /**
     * @brief constructor de la clase Node, se instancia una estructura que sirve para contener los datos de la lista
     * @param _data dato que el nodo contiene
     */
    Node(DATO _data){
        data = _data;
        next = NULL;
    }

    /**
     * @brief constructor de la clase Node, se instancia una estructura que sirve para contener los datos de la lista
     * @param _data dato que el nodo contiene
     * @param _next puntero que representa el siguiente nodo en la lista
     */
    Node(DATO _data, Node<DATO> *_next){
        data = _data;
        next = _next;
    }

    /**
     * @brief libera memoria del puntero
     * @param p puntero a liberar memoria
     */
    void operator delete(void *p){
        free(p);
    }

    /**
     * @brief modifica el dato ingresado
     * @param _data dato a modificar
     */
    void modify(DATO _data){
        data = _data;
    }

    /**
     * @brief método para obtener un dato en especifico de la lista
     */
    DATO consult(){
        return data;
    }

};

#endif //BREAKOUT_GAME_CLIENT_NODE_H