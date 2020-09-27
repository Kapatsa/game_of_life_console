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

class Game {
    Field* fieldPtr;
    char typeOfPlayer;
public:
    Game();
    void setGame();
    void play();
};


#endif /* game_hpp */
