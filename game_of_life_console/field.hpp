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

/**
*This class describes a field for the game, including all of its cells
*/
class Field {
    int fieldHeight = 20;
    int fieldWidth = 30;
    Cell** cellArray;
    //bool fieldtype - cyclic or finite
public:
    /**
    *Default constructor
    */
    Field();
    /**
    *Constructor, which sets the size of field
    */
    Field(int fieldH, int fieldW);
    /**
    *Destructor that frees the memory from cellArray
    */
    ~Field();
    /**
    *Field setting using console input
    */
    void setFieldByHand();
    /**
    *Field setting using existing array
    */
    void setFieldByArray(bool** array);
    /**
    *Field setting using random generator. @param prob sets probability for life in a single cell
    */
    void setFieldRandom(std::mt19937 generator, double prob = 0.2);
    /**
    *Using the current field setup and neighbors count, changes the field to produce the next generation of the automata
    */
    void iterateField();
    /**
    *Console output of the number of neighbors for each cell. Made mostly for debugging purposes.
    */
    void printNumNeighbors();
    /**
    *Console output of the current iteration of the field.
    */
    void print();
};

#endif /* field_hpp */
