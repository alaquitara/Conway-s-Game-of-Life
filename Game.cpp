//
//  Game.cpp
//  ConwayGoL
//
//  Created by Alexander Laquitara on 1/8/16.
//  Copyright © 2016 Alexander Laquitara. All rights reserved.
//
/*********************************************************************
 ** Program Filename:  Game.cpp
 ** Author:    Alexander Laquitara
 ** Date:  1/8/2016
 ** Description: Class implementation file for class Game.  Provides
    rules for movement and display on game board.
 ** Input:  User selected game mode from main.cpp
 ** Output:  prints game to console
 *********************************************************************/
#include <iostream>
#include <unistd.h>
#include "Game.hpp"

//Default constructor, creates two 2d arrays for
//a live board and temorary board
Game::Game()
{
    for(int i = 0; i < 40; i++){
        for (int j = 0; j < 80; j++){
            board [i][j] = 0;
    }
}
    for(int i = 0; i < 40; i++){
        for (int j = 0; j < 80; j++){
            tempBoard [i][j] = 0;
        }
    }
}

/*********************************************************************
 ** Function: copyBoard
 ** Description: sets two arrays equal to each other.  In this case we
    will be using it to update tempBoard into the live board
 ** Parameters:  two 2d arrays size 40x80
 ** Pre-Conditions: Board object
 ** Post-Conditions:  board object
 *********************************************************************/
void Game::copyBoard(int array1[40][80],int array2[40][80])
{
    for(int i = 0; i < 40; i++){
        for (int j = 0; j < 80; j++){
            array1[i][j] = array2[i][j];
        }
    }
    
}
/*********************************************************************
 ** Function: printBoard
 ** Description: Prints array board to console
 ** Parameters:  None
 ** Pre-Conditions: Board object
 ** Post-Conditions:  None
 *********************************************************************/
void Game::printBoard()
{
    for(int i = 10; i < 30; i++){
        for(int j = 20; j < 60; j++){
            if(board[i][j] == 1){       // * for live cell
                std::cout<< "*";
            }
            else{
                std::cout<<" ";     //blank space for dead cell
            }
        }
        std::cout<<'\n';
    }
    sleep(1);   //sets a 1 second delay to appear as if board is animated
}
/*********************************************************************
 ** Function: checkLive
 ** Description: The bread and butter of game of life.  This is the algorithm
    which decides if a cell is to live or die.
 ** Parameters:  None
 ** Pre-Conditions: Board object
 ** Post-Conditions:  an updated board after rules of the game are applied.
 *********************************************************************/
void Game::checkLive()
{
    int liveCount = 0;
    
    for(int i =0; i < 40; i++)
    {
        for(int j=0; j<80;j++)
        {
            /*
            **  Checks to see which of the 8 neighbors of a cell are living.
            **  if alive adds to the running tally liveCount
            */
            
            liveCount = 0;
            if(board[i - 1][j - 1] == 1)
            {
                liveCount++;
            }
            if(board[i - 1][j] == 1)
            {
                liveCount++;
            }
            if(board[i - 1][j + 1] == 1)
            {
                liveCount++;
            }
            if(board[i][j - 1] == 1)
            {
                liveCount++;
            }
            if(board[i][j + 1] == 1)
            {
                liveCount++;
            }
            if(board[i + 1][j - 1] == 1)
            {
                liveCount++;
            }
            if(board[i + 1][j] == 1)
            {
                liveCount++;
            }
            if(board[i + 1][j + 1] == 1)
            {
                liveCount++;
            }

            //Applies the 4 rules
            if ((board[i][j]==1)&&((liveCount < 2)||(liveCount > 3)))
            {
                tempBoard[i][j] = 0;
            }
            
            else if ((board[i][j]==0)&&((liveCount == 3)))
            {
                tempBoard[i][j] = 1;
            }

            else if ((board[i][j]==1)&&((liveCount == 2)||(liveCount == 3)))
            {
                tempBoard[i][j] = 1;
            }
        
            else
            {
                tempBoard[i][j] = 0;
            }
            
        }
    }
    copyBoard(board, tempBoard); //applies changes to the live board
}

/*********************************************************************
 ** Function: oscillator
 ** Description: sets up the board to execute an oscillator pattern,
    allows user to place on the board if desired.
 ** Parameters:  None
 ** Pre-Conditions: Board object
 ** Post-Conditions:  None
 *********************************************************************/
void Game::oscillator()
{
    char place;
    int x, y;
    
    std::cout<<"You chose the oscillator pattern. Startpoint is the center cell. Would you like to place the location Y/N?"<<std::endl;
    std::cin>>place;
    
    if(place == 'Y' || place == 'y'){
        std::cout<<"The grid is 20 rows x 40 coulmns"<<std::endl;
        std::cout<<"Please place the x axis"<<std::endl;
        std::cin>> x;
        if(!std::cin){
            std::cin.clear();
            std::cin.ignore();
        }
        std::cout<< "Please place the y axis"<<std::endl;
        std::cin>> y;
        if(!std::cin){
            std::cin.clear();
            std::cin.ignore();
        }
        board[y+11][x+20] = 1;
        board[y+10][x+20] = 1;
        board[y+12][x+20] = 1;
    }
    
    else{
        board[20][30] = 1;
        board[19][30] = 1;
        board[21][30] = 1;
    }
}

/*********************************************************************
 ** Function: glider
 ** Description: sets up the board to execute a glider pattern,
    allows user to place on the board if desired.
 ** Parameters:  None
 ** Pre-Conditions: Board object
 ** Post-Conditions:  None
 *********************************************************************/
void Game::glider() //http://www.conwaylife.com/wiki/Glider
{
    char place;
    int x,y;
    
    std::cout<<"You chose the glider pattern. Startpoint is the top left live cell. Would you like to place the location Y/N?"<<std::endl;
    std::cin>>place;
    
    if(place == 'Y' || place == 'y'){
        std::cout<<"The grid is 20 rows x 40 coulmns"<<std::endl;
        std::cout<<"Please place the x axis"<<std::endl;
        std::cin>> x;
        
        if(!std::cin){
            std::cin.clear();
            std::cin.ignore();
        }
        
        std::cout<< "Please place the y axis"<<std::endl;
        std::cin>> y;
        if(!std::cin){
            std::cin.clear();
            std::cin.ignore();
        }
        board[y+10][x+20] = 1;
        board[y+11][x+21] = 1;
        board[y+9][x+22] = 1;
        board[y+10][x+22] = 1;
        board[y+11][x+22] = 1;
    }
    
    else{
        board[15][25] = 1;
        board[16][26] = 1;
        board[14][27] = 1;
        board[15][27] = 1;
        board[16][27] = 1;
    }
}

/*********************************************************************
 ** Function: gliderGun
 ** Description: sets up the board to execute a glider gun pattern,
    allows user to place on the board if desired.
 ** Parameters:  None
 ** Pre-Conditions: Board object
 ** Post-Conditions:  None
 *********************************************************************/
void Game::gliderGun() //http://www.conwaylife.com/wiki/Gosper_glider_gun
{
    char place;
    int x,y;
    
    std::cout<<"You chose the glider gun pattern.  Would you like to place the location Y/N?  Startpoint is the left most shape."<<std::endl;
    std::cin>>place;
    
    if(place == 'Y' || place == 'y'){
        std::cout<<"The grid is 20 rows x 40 coulmns"<<std::endl;
        std::cout<<"Please place the x axis"<<std::endl;
        std::cin>> x;
        if(!std::cin){
            std::cin.clear();
            std::cin.ignore();
        }
        
        std::cout<< "Please place the y axis"<<std::endl;
        std::cin>> y;
        if(!std::cin){
            std::cin.clear();
            std::cin.ignore();
        }
        //left block
        board[y+10][x+20] = 1;
        board[y+10][x+21] = 1;
        board[y+11][x+20] = 1;
        board[y+11][x+21] = 1;
        
        //right block
        board[y+8][x+54] = 1;
        board[y+9][x+55] = 1;
        board[y+9][x+54] = 1;
        board[y+8][x+55] = 1;
        
        //left shape
        board[y+10][x+30] = 1;
        board[y+11][x+30] = 1;
        board[y+12][x+30] = 1;
        board[y+9][x+31] = 1;
        board[y+13][x+31] = 1;
        board[y+8][x+32] = 1;
        board[y+14][x+32] = 1;
        board[y+8][x+33] = 1;
        board[y+14][x+33] = 1;
        board[y+9][x+35] = 1;
        board[y+11][x+34] = 1;
        board[y+13][x+35] = 1;
        board[y+10][x+36] = 1;
        board[y+11][x+36] = 1;
        board[y+12][x+36] = 1;
        board[y+11][x+37] = 1;
        
        //right shape
        board[y+10][x+40] = 1;
        board[y+9][x+40] = 1;
        board[y+8][x+40] = 1;
        board[y+10][x+41] = 1;
        board[y+9][x+41] = 1;
        board[y+8][x+41] = 1;
        board[y+7][x+42] = 1;
        board[y+11][x+42] =1 ;
        board[y+7][x+44] = 1;
        board[y+6][x+44] = 1;
        board[y+11][x+44] = 1;
        board[y+12][x+44] = 1;
    }
    
    else{
        //left block
        board[20][21]=1;
        board[20][22]=1;
        board[21][21]=1;
        board[21][22]=1;
        
        //right block
        board[18][55]=1;
        board[19][56]=1;
        board[18][56]=1;
        board[19][55]=1;
        
        //left shape
        board[20][31]=1;
        board[21][31]=1;
        board[22][31]=1;
        board[19][32]=1;
        board[23][32]=1;
        board[18][33]=1;
        board[24][33]=1;
        board[18][34]=1;
        board[24][34]=1;
        board[19][36]=1;
        board[21][35]=1;
        board[23][36]=1;
        board[20][37]=1;
        board[21][37]=1;
        board[22][37]=1;
        board[21][38]=1;
        
        //right shape
        board[20][41]=1;
        board[19][41]=1;
        board[18][41]=1;
        board[20][42]=1;
        board[19][42]=1;
        board[18][42]=1;
        board[17][43]=1;
        board[21][43]=1;
        board[17][45]=1;
        board[16][45]=1;
        board[21][45]=1;
        board[22][45]=1;
        
    }
}
