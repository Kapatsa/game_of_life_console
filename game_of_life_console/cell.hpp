//
//  cell.hpp
//  game_of_life_console
//
//  Created by David Kapatsa on 26.09.2020.
//  Copyright © 2020 David Kapatsa. All rights reserved.
//

#ifndef cell_hpp
#define cell_hpp

#include <stdio.h>
#include <iostream>

/**
*This class describes a cell in a field, where the game is set. The cell can be alive or not.
*Another attribute is the number of neighbors which is used by the algorithm.
*/
class Cell {
    bool alive;
    int numNeighbors = 0;
public:
    /**
    *This method helps set a cell to be alive or dead
    */
    void setAlive(bool num);
    /**
    *This method gets a status of a cell
    */
    bool getAlive();
    /**
    *This method simply adds one to the number of neighbors it has
    */
    void addNeighbor();
    /**
    *This method simply removes one from the number of neighbors it has
    */
    void removeNeighbor();
    /**
    *Gets the current number of neighbors
    */
    int getNumNeighbors();
    /**
    *Sets the number of neighbors
    */
    void setNumNeighbors(int num);
    /**
    *Prints a single cell
    */
    void print();
};


#endif /* cell_hpp */
