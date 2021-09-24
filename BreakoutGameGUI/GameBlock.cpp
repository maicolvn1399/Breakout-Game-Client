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
    const string words[15] = {"común","doble","triple","interno","profundo","sorpresa","común","común","común","común",
                              "común","común","común","común","común"};
    string word;

    for(int i = 0; i < totalBlocks; i++){
        word = words[rand()%15];
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
}

void GameBlock::setBlockColors(){
    block.setFillColor(Color(235,174,52));
    block.setOutlineColor(Color(255,255,255));
}

void GameBlock::setBlocksPositions(Vector2f positions){

    block.setPosition(positions);
}

void GameBlock::setBlockColorsDoble() {
    block.setFillColor(Color(235,174,52));
    block.setOutlineColor(Color(255,255,255));
}

