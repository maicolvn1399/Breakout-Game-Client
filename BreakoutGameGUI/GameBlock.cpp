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
