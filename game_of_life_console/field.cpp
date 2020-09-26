//
//  field.cpp
//  game_of_life_console
//
//  Created by David Kapatsa on 26.09.2020.
//  Copyright © 2020 David Kapatsa. All rights reserved.
//

#include "field.hpp"

    Field::Field(int fieldH, int fieldW){
        fieldHeight = fieldH;
        fieldWidth = fieldW;
        cellArray = new Cell*[fieldHeight];
        for(int i = 0; i < fieldHeight; ++i)
            cellArray[i] = new Cell[fieldWidth];
    }
    Field::~Field(){
        for(int i = 0; i < fieldHeight; ++i)
            delete [] cellArray[i];
        delete [] cellArray;
    }
    
void Field::setFieldByHand(){
        bool temp;
        for(int i = 0; i < fieldHeight; ++i){
            for(int j = 0; j < fieldWidth; ++j){
                std::cin >> temp;
                cellArray[i][j].setAlive(temp);
             //   if(temp == 1) addNeighbors(cellArray, height, width, i, j); //TODO:: this function
            }
        }
    }

//TODO::setFieldRandom()
    
void Field::print(){
        for(int i = 0; i < fieldHeight; ++i){
            for(int j = 0; j < fieldWidth; ++j){
                cellArray[i][j].print();
                std::cout << " ";
            }
        std::cout << std::endl;
        }
    }

