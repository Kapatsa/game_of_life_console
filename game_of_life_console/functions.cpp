//
//  functions.cpp
//  game_of_life_console
//
//  Created by David Kapatsa on 27.09.2020.
//  Copyright © 2020 David Kapatsa. All rights reserved.
//

#include "functions.hpp"

void addNeighbors(Cell** cellArray, int height, int width, int i, int j)
{
    //we add one to the quantity of neighbors for each of the cells in the vicinity and even the central one (we remove it later)
    for(int k = std::max(0, i-1); k < std::min(height, i+2); ++k){
        for(int l = std::max(0, j-1); l < std::min(width, j+2); ++l){
            cellArray[k][l].addNeighbor();
        }
    }
    cellArray[i][j].removeNeighbor();//the central element was not supposed to get a new neighbor, so we subtract one now
}

//TODO::repetition of code - fix later
void removeNeighbors(Cell** cellArray, int height, int width, int i, int j)
{
    //we subtract one from the quantity of neighbors for each of the cells in the vicinity and even the central one (we add it later)
    for(int k = std::max(0, i-1); k < std::min(height, i+2); ++k){
        for(int l = std::max(0, j-1); l < std::min(width, j+2); ++l){
            cellArray[k][l].removeNeighbor();
        }
    }
    cellArray[i][j].addNeighbor();//the central element was not supposed to have less neighbors, so we add one now
}
//TODO:: add a new mode, where the field is
