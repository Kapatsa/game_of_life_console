//
//  main.cpp
//  game_of_life_console
//
//  Created by David Kapatsa on 26.09.2020.
//  Copyright © 2020 David Kapatsa. All rights reserved.
//

#include <iostream>
#include <random>
#include <fstream>
#include "field.hpp"
#include "cell.hpp"
#include "game.hpp"

int main(int argc, const char * argv[]) {
    
    std::random_device rd;
    std::mt19937 gen(rd());
    
    Game game(gen);
    
    std::cout << R"(
      ___     _     __  __   ___      ___    ___     _      ___   ___   ___
     / __|   /_\   |  \/  | | __|    / _ \  | __|   | |    |_ _| | __| | __|
    | (_ |  / _ \  | |\/| | | _|    | (_) | | _|    | |__   | |  | _|  | _|
     \___| /_/ \_\ |_|  |_| |___|    \___/  |_|     |____| |___| |_|   |___|
    by David Kapatsa, 2020.
    )" << std::endl;
    
    while (1) {
        game.setGame();
        game.play();
        
        std::cout << "again? (y/n): ";
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        if (std::cin.get() != 'y') break;
    }
    

    return 0;
}
