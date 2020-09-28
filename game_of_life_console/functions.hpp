//
//  functions.hpp
//  game_of_life_console
//
//  Created by David Kapatsa on 27.09.2020.
//  Copyright © 2020 David Kapatsa. All rights reserved.
//

#ifndef functions_hpp
#define functions_hpp

#include <stdio.h>
#include <algorithm>
#include "field.hpp"
#include "cell.hpp"

#endif /* functions_hpp */

/**
*This function adds to the number of neighbors to the cells in the vicinity
*/
void addNeighbors(Cell** cellArray, int height, int width, int i, int j);
/**
*This function subtracts one from the number of neighbors of all the cells in the vicinity
*/
void removeNeighbors(Cell** cellArray, int height, int width, int i, int j);
