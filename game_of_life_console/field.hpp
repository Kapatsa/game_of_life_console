//
//  field.hpp
//  game_of_life_console
//
//  Created by David Kapatsa on 26.09.2020.
//  Copyright © 2020 David Kapatsa. All rights reserved.
//

#ifndef field_hpp
#define field_hpp

#include <iostream>
#include "cell.hpp"
#include <stdio.h>
#include <random>

class Field {
    int fieldHeight = 20;
    int fieldWidth = 30;
    Cell** cellArray;
    //bool fieldtype - cyclic or finite
public:
    Field();
    Field(int fieldH, int fieldW);
    ~Field();
    void setFieldByHand();
    void setFieldByArray(bool** array);
    void setFieldRandom(std::mt19937 generator, double prob = 0.2);
    void iterateField();
    void printNumNeighbors();
    void print();
};

#endif /* field_hpp */
