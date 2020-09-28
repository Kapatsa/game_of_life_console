//
//  game.cpp
//  game_of_life_console
//
//  Created by David Kapatsa on 26.09.2020.
//  Copyright © 2020 David Kapatsa. All rights reserved.
//

#include "game.hpp"

Game::Game(std::mt19937 gen){
    generator = gen;
}

void Game::setGame(){
    
    std::cout << "Please enter type of game" << std::endl << "type 's' for simple, and 'a' for advanced: ";
    
    do {
            std::cin >> typeOfGame;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
            if(typeOfGame != 's' && typeOfGame != 'a'){
                std::cout << std::endl << "Please enter 's' or 'a': ";
            }
    } while (typeOfGame != 's' && typeOfGame != 'a');
    
    switch (typeOfGame) {
        case 's':
            fieldPtr = new Field();
            fieldPtr -> setFieldRandom(generator);
            break;
        case 'a':
            int height;
            int width;
            char input;
            double prob;
            std::cout << "Please enter the height of field (in cells): ";
            std::cin >> height;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
            std::cout << "Please enter the width of field (in cells): ";
            std::cin >> width;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
            fieldPtr = new Field(height, width);
            std::cout << "Please enter the type of initial field" << std::endl << "type 'r' for random, and 'm' for manual input: ";
            do {
                       std::cin >> input;
                       std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
                       if(input != 'r' && input != 'm'){
                           std::cout << std::endl << "Please enter 'r' or 'm': ";
                       }
               } while (input != 'r' && input != 'm');
            if (input == 'r'){
                std::cout << "Enter probability of life in each cell (0 to 1): ";
                std::cin >> prob;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
                fieldPtr -> setFieldRandom(generator, prob);
            } else {
                fieldPtr -> setFieldByHand();
            }
            break;
        default:
            break;
    }

};
void Game::play(){
    std::cout << "Here is the initial field:" << std::endl;
    fieldPtr -> print();
    std::cout << "Press enter to iterate the field, press any other key to stop" << std::endl;
    while (std::cin.get() == '\n') {
        fieldPtr -> iterateField();
        fieldPtr -> print();
        std::cout << "Press enter to iterate the field, press any other key to stop" << std::endl;
    }
    delete fieldPtr;
};


