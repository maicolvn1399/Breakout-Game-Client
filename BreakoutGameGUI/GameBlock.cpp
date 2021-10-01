//
// Created by michael on 13/9/21.
//

#include "GameBlock.h"
#include "iostream"

const RectangleShape &GameBlock::getBlock() const {
    return block;
}

bool *GameBlock::getIsBlock() const {
    return isBlock;
}

GameBlock::GameBlock() {


    block.setSize(Vector2f(40, 30));
    block.setOutlineThickness(1.0f);
}

void GameBlock::setFalseValuesToArray(){
    for(int i = 0; i < totalBlocks; i++){
        isBlock[i] = false;
    }
    for(int i = 0; i < 160; i++){
        isBlock[i] = true;
    }
}

void GameBlock::setBlockTypes(){
    //const string words[15] = {"común","doble","triple","interno","profundo","sorpresa","común","común","común","común",
                              //"común","común","común","común","común"};

    LinkedList<string> *ptrWords = new LinkedList<string>();

    ptrWords->insertar("común");
    ptrWords->insertar("doble");
    ptrWords->insertar("triple");
    ptrWords->insertar("interno");
    ptrWords->insertar("profundo");
    ptrWords->insertar("sorpresa");
    ptrWords->insertar("común");
    ptrWords->insertar("común");
    ptrWords->insertar("común");
    ptrWords->insertar("común");
    ptrWords->insertar("común");
    ptrWords->insertar("común");
    ptrWords->insertar("común");
    ptrWords->insertar("común");
    ptrWords->insertar("común");
    ptrWords->insertar("sorpresa");
    ptrWords->insertar("sorpresa");

    string word;

    for(int i = 0; i < totalBlocks; i++){
        word = ptrWords->obtenerPos(rand()%17);
        wordList[i] = word;
    }

    for(int i = 0; i < totalBlocks; i++){
        if(wordList[i] == "doble"){
            hitsToBlock[i] = 2;
        }else if(wordList[i] == "triple"){
            hitsToBlock[i] = 3;

        }else{
            hitsToBlock[i] = 0;
        }
    }

    for(int i = 0; i < totalBlocks; i++){
        if(wordList[i] == "común"){
            blockColorList[i] = 1;
        }else if(wordList[i] == "doble"){
            blockColorList[i] = 2;
        }else if(wordList[i] == "triple"){
            blockColorList[i] = 3;
        }else if(wordList[i] == "interno"){
            blockColorList[i] = 4;
        }else if(wordList[i] == "profundo"){
            blockColorList[i] = 5;
        }else{
            blockColorList[i] = 6;
        }
    }
}

void GameBlock::setBlockColors(){
    block.setFillColor(Color(235,174,52));
    block.setOutlineColor(Color(255,255,255));
}

void GameBlock::setBlocksPositions(Vector2f positions){
    block.setPosition(positions);
}


int GameBlock::getCantidadProfundos() {
    for(int i = 0; i < 160; i++){
        if(wordList[i] == "profundo"){
            cantidadBloquesProfundos += 1;
        }
    }
    return cantidadBloquesProfundos;
}

