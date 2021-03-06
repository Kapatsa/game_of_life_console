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

/*! \mainpage Описание программы
*
* \section intro_sec Введение
*
* Это документация к консольной игре "Game of Life". Здесь будет приведено её краткое описание.
*
* \subsection sect Описание
*
* Игра имеет два способа взаимодействия: простой и продвинутый.
* Простой предполагает минимум интерактива. Сразу же выбирается стандартный размер поля, а начальный вид самого поля строится случайным образом с помощью генератора случайных чисел.
* При выборе сложного способа взаимодействия, можно выбирать как размеры поля, так и способ его заполнения (вручную с помощью консольного ввода или случайная генерация с заданной вероятностью жизни той или иной клетки)
*
* Ввиду небольшого времени на выполнение задания, эта версия пока совсем черновая. Главными недостатками следует считать отсутствие проверки ввода и обработки ошибок в некоторых местах, а также графического интерфейса.
* Программа без ошибок компилилировалась в Xcode.
*/

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
