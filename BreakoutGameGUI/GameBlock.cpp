//
// Created by michael on 13/9/21.
//

#include "GameBlock.h"

const RectangleShape &GameBlock::getBlock() const {
    return block;
}

bool *GameBlock::getIsBlock() const {
    return isBlock;
}

GameBlock::GameBlock() {
    block.setSize(Vector2f(40,30));
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

void GameBlock::setBlockColors(){
    block.setFillColor(Color(235,174,52));
    block.setOutlineColor(Color(255,255,255));
}

void GameBlock::setBlocksPositions(Vector2f positions){

    block.setPosition(positions);
}

