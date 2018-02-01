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

class TicTacToe;
class RockPaperScissors;
class Mastermind;
class Hangman;

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Pick a game to play"<<'\n'<< "1) Tic Tac Toe"<<'\n'<< "2) Rock Paper Scissors"<<'\n'<< "3) Mastermind"<<'\n'<< "4) Hangman";
    int inputNumber;
    std::cin >> inputNumber;
    
    if (inputNumber == 1){
        TicTacToe *TTT = new TicTacToe;
        TTT->run();
    }
    
    if (inputNumber == 2){
        RockPaperScissors *RPS = new RockPaperScissors;
        RPS->run();
    }
    
//    if (inputNumber == 3){
//        Mastermind *MM = new Mastermind;
//        MM->run();
//    }
//
//    if (inputNumber == 4){
//        Hangman *HM = new Hangman;
//        HM->run();
//    }
    
}

