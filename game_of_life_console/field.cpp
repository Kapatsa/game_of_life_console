//
//  field.cpp
//  game_of_life_console
//
//  Created by David Kapatsa on 26.09.2020.
//  Copyright © 2020 David Kapatsa. All rights reserved.
//

#include "field.hpp"
#include "functions.hpp"

    Field::Field(){
        cellArray = new Cell*[fieldHeight];
        for(int i = 0; i < fieldHeight; ++i)
            cellArray[i] = new Cell[fieldWidth];
    }

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
                if(temp == 1) addNeighbors(cellArray, fieldHeight, fieldWidth, i, j);
            }
        }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    }

//TODO:: Include check for bounds of array
void Field::setFieldByArray(bool** array){
    bool temp;
    for(int i = 0; i < fieldHeight; ++i){
        for(int j = 0; j < fieldWidth; ++j){
            temp = array[i][j];
            cellArray[i][j].setAlive(temp);
            if(temp == 1) addNeighbors(cellArray, fieldHeight, fieldWidth, i, j);
        }
    }
}

void Field::setFieldRandom(std::mt19937 generator, double prob){
    //TODO:: Check that prob parameter is inside the bounds (0;1)
    std::bernoulli_distribution d(prob);
    int temp;
    for(int i = 0; i < fieldHeight; ++i){
        for(int j = 0; j < fieldWidth; ++j){
            temp = d(generator);
            cellArray[i][j].setAlive(temp);
            if(temp == 1) addNeighbors(cellArray, fieldHeight, fieldWidth, i, j);
        }
    }
}

void Field::iterateField(){
    int temp;
    
    for(int i = 0; i < fieldHeight; ++i){
        for(int j = 0; j < fieldWidth; ++j){
            temp = cellArray[i][j].getNumNeighbors();
            if(cellArray[i][j].getAlive() == 1){
                if(temp < 2 || temp > 3){
                    cellArray[i][j].setAlive(0);
                }
            }
            else {
                if(temp == 3){
                    cellArray[i][j].setAlive(1);
                }
            }
            cellArray[i][j].setNumNeighbors(0);
        }
    }
//calculating the number of neighbors again
    for(int i = 0; i < fieldHeight; ++i){
        for(int j = 0; j < fieldWidth; ++j){
            if(cellArray[i][j].getAlive() == 1) addNeighbors(cellArray, fieldHeight, fieldWidth, i, j);
        }
    }
}

    
void Field::print(){
        for(int i = 0; i < fieldHeight; ++i){
            std::cout << "║";
            for(int j = 0; j < fieldWidth; ++j){
                cellArray[i][j].print();
                std::cout << "║";
            }
        std::cout << std::endl;
        }
    std::cout << std::endl;
    }

void Field::printNumNeighbors(){
    for(int i = 0; i < fieldHeight; ++i){
        std::cout << "║";
        for(int j = 0; j < fieldWidth; ++j){
            std::cout << cellArray[i][j].getNumNeighbors();
            std::cout << "║";
        }
    std::cout << std::endl;
    }
std::cout << std::endl;
}


