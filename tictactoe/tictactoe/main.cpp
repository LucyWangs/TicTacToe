//
//  main.cpp
//  tictactoe
//
//  Created by Lucy Wang on 1/28/18.
//  Copyright © 2018 Lucy Wang. All rights reserved.
//

#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include "tictactoe.cpp"
#include "rockpaperscissors.cpp"
#include "mastermind.cpp"
#include "hangman.cpp"

class TicTacToe;
class RockPaperScissors;
class Mastermind;
class Hangman;

int main(int argc, const char * argv[]) {
    bool replay = true;
    
    
    while (replay){
    std::cout << "Pick a game to play by entering a number 1 to 4:"<<'\n'<< "1) Tic Tac Toe"<<'\n'<< "2) Rock Paper Scissors"<<'\n'<< "3) Mastermind"<<'\n'<< "4) Hangman"<<'\n';
    int inputNumber;
    std::cin >> inputNumber;
    
    
    while(inputNumber != 1 and inputNumber != 2 and inputNumber != 3 and inputNumber != 4){
        std::cout << "Please enter a number 1 to 4";
        std::cin >> inputNumber;
    }
    
    
    if (inputNumber == 1){
        TicTacToe *TTT = new TicTacToe;
        TTT->run();
    }
    
    if (inputNumber == 2){
        RockPaperScissors *RPS = new RockPaperScissors;
        RPS->run();
    }
    
    if (inputNumber == 3){
        Mastermind *MM = new Mastermind;
        MM->run();
    }
    

    if (inputNumber == 4){
        Hangman *HM = new Hangman;
        HM->run();
    }
        
        std::cout << "Do you want to play another game?  Enter Y or N"<<'\n';
        std::string yesNoInput;
        std::cin >> yesNoInput;
        if(yesNoInput=="N"){
            break;
        }
    
    }
}

