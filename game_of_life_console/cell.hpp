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

class Cell {
    bool alive;
    int numNeighbors = 0;
public:
    void setAlive(bool num);
    bool getAlive();
    void addNeighbor();
    void removeNeighbor();
    int getNumNeighbors();
    void setNumNeighbors(int num);
    void print();
};


#endif /* cell_hpp */
