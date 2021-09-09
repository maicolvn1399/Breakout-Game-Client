//
// Created by maxgm on 8/9/21.
//

#ifndef BREAKOUT_GAME_CLIENT_NODO_H
#define BREAKOUT_GAME_CLIENT_NODO_H
#include <stddef.h>

/**
 * @brief Nodo, struc.
 *
 * @tparam DATO, type of the node
 */
template<class DATO>
class Nodo {
public:
    DATO dato;
    Nodo<DATO> * next;


    // Constructores
    Nodo(){
        dato;
        next = NULL;
    }

    Nodo(DATO _dato){
        dato = _dato;
        next = NULL;
    }

    Nodo(DATO _dato, Nodo<DATO> * _siguiente){
        dato = _dato;
        next = _siguiente;
    }
    /**
     * @brief Delete de memory space of the node
     *
     * @param p, pointer of the node
     */
    void operator delete(void * p){
        free(p);
    }

    /**
     * @brief Edited the value of the node
     *
     * @param DATO, node
     */
    void modif(DATO _dato){
        dato = _dato;
    }

    /**
     * @brief Consult the node
     */
    DATO consulta(){
        return dato;
    }
};

#endif //BREAKOUT_GAME_CLIENT_NODO_H
