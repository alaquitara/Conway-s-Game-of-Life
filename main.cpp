//
//  main.cpp
//  ConwayGoL
//
//  Created by Alexander Laquitara on 1/8/16.
//  Copyright © 2016 Alexander Laquitara. All rights reserved.
//
/*********************************************************************  
 ** Program Filename:  main.cpp
 ** Author:    Alexander Laquitara
 ** Date:  1/8/2016
 ** Description: Main function for execution of class Game menu
 ** Input:  Class object of Game
 ** Output:  Results of calling functions within game.
 *********************************************************************/
#include <iostream>
#include <ctype.h>
#include "Game.hpp"

int main(int argc, const char * argv[]) {
    int turns, choice, count= 0;
    Game Game;
    
    do{
    std::cout<<"Conway's Game of Life:"<<std::endl;
    std::cout<<"Enter 1 for Oscillator, 2 for Glider, or 3 for Glider Gun"<<std::endl;
    std::cin>>choice;
        if((!std::cin) && (!isdigit(choice))){
            std::cin.clear();
            std::cin.ignore();
        }
    }
    
    while((choice != 1) && (choice != 2) && (choice != 3));
    
    if(choice == 1)
    {
        std::cout<<"how many times do you want to run the game?"<<std::endl;
        std::cin>>turns;
        
        Game.oscillator();
        while (count < turns){
            
            Game.printBoard();
            std::cout<<"running..."<<std::endl;
            Game.checkLive();
            count++;
        }
    }
    
    else if(choice == 2)
    {
        std::cout<<"how many times do you want to run the game?"<<std::endl;
        std::cin>>turns;
        
        Game.glider();
        while (count < turns){
            
            Game.printBoard();
            std::cout<<"running..."<<std::endl;
            Game.checkLive();
            count++;
        }
    }
    
    else if(choice == 3)
    {
        std::cout<<"how many times do you want to run the game?"<<std::endl;
        std::cin>>turns;
        
        Game.gliderGun();
        while (count < turns){
            
            Game.printBoard();
            std::cout<<"running.."<<std::endl;
            Game.checkLive();
            count++;
        }
    }
    return 0;
}
