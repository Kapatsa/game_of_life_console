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
#include <array>
#include "cell.hpp"
#include <stdio.h>
#include <random>

class Field {
    int fieldHeight;
    int fieldWidth;
    Cell** cellArray;
public:
    Field(int fieldH, int fieldW);
    ~Field();
    void setFieldByHand();
    void setFieldRandom(std::mt19937 generator, double prob = 0.1);
    void print();
};

#endif /* field_hpp */
