//
//  game.hpp
//  game_of_life_console
//
//  Created by David Kapatsa on 26.09.2020.
//  Copyright © 2020 David Kapatsa. All rights reserved.
//

#ifndef game_hpp
#define game_hpp

#include <stdio.h>
#include "field.hpp"
#include <iostream>

/**
*Class made for the initial setup of the field and actual gameplay
*/
class Game {
    Field* fieldPtr;
    char typeOfGame;
    std::mt19937 generator;
public:
    /**
    *Default constructor, needs a random number generator for cell field generation
    */
    Game(std::mt19937 gen);
    /**
    *Initial setup of the game
    */
    void setGame();
    /**
    *Actual gameplay with exit
    */
    void play();
};


#endif /* game_hpp */
