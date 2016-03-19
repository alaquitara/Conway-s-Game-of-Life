//
//  Game.hpp
//  ConwayGoL
//
//  Created by Alexander Laquitara on 1/8/16.
//  Copyright © 2016 Alexander Laquitara. All rights reserved.
//
/*********************************************************************
 ** Program Filename:  Game.hpp
 ** Author:    Alexander Laquitara
 ** Date:  1/8/2016
 ** Description: Header file for class Game
 ** Input:  User selected game mode from main.cpp
 ** Output:  prints game to console
 *********************************************************************/
#ifndef Game_hpp
#define Game_hpp

#include <stdio.h>
class Game
{
    private:
        int board[40][80];
        int tempBoard[40][80];
    public:
        Game();
        void copyBoard(int array1[40][80], int array2[40][80]);
        void printBoard();
        void checkLive();
        void oscillator();
        void glider();
        void gliderGun();
};

#endif /* Game_hpp */
