//
//  cell.cpp
//  game_of_life_console
//
//  Created by David Kapatsa on 26.09.2020.
//  Copyright © 2020 David Kapatsa. All rights reserved.
//

#include "cell.hpp"

void Cell::setAlive(bool num){
    alive = num;
}
bool Cell::getAlive(){
    return alive;
}
void Cell::addNeighbor(){
    ++numNeighbors;
}
void Cell::removeNeighbor(){
    --numNeighbors;
}
int Cell::getNumNeighbors(){
    return numNeighbors;
}
void Cell::setNumNeighbors(int num){
    numNeighbors = num;
}
void Cell::print(){
    if(alive == 1){
        std::cout << "██";
    }
    else {
        std::cout << "  ";
    }
}

