//
//  rockpaperscissors.cpp
//  tictactoe
//
//  Created by Lucy Wang on 1/31/18.
//  Copyright © 2018 Lucy Wang. All rights reserved.
//

#include <iostream>
#include <cstdlib>

class RockPaperScissors;

//////////////////////////////
//RockPaperScissors Class
// This class is responsible for one game of regular rock paper scissors.

class RockPaperScissors
{
    bool isRegular;
    std::string computerChoice;
    std::string checkWin(std::string input);
    void run_regular();
    void run_lizardspock();
    std::string getChoice();
    
public:
    void run(int i);
};

//////////////////////////////////////
//RockPaperScissors Implementation

//This method checks who wins.
std::string RockPaperScissors::checkWin(std::string input)
{
    std::string response = "";
    
    if(isRegular)
    {
        if(computerChoice == input)
        {
            response = "It's a tie";
        }
        else if((computerChoice == "rock" and input == "scissors") or (computerChoice == "scissors" and input == "paper") or (computerChoice == "paper" and input == "rock"))
        {
            response = "Computer wins!";
        }
        else if((input == "rock" and computerChoice == "scissors") or (input == "scissors" and computerChoice == "paper") or (input == "paper" and computerChoice == "rock"))
        {
            response = "Player wins!";
        }
    }
    else
    {
        if(computerChoice == input)
        {
            response = "It's a tie";
        }
        else if((computerChoice == "rock" and (input == "scissors" or input == "lizard")) or (computerChoice == "scissors" and (input == "paper" or input == "lizard")) or (computerChoice == "paper" and (input == "rock" or input == "spock")) or (computerChoice == "lizard" and (input == "paper" or input == "spock")) or (computerChoice == "spock" and (input == "rock" and input == "scissors")))
        {
            response = "Computer wins!";
        }
        else if((input == "rock" and (computerChoice == "scissors" or computerChoice == "lizard")) or (computerChoice == "scissors" and (input == "paper" or input == "lizard")) or (computerChoice == "paper" and (input == "rock" or input == "spock")) or (computerChoice == "lizard" and (input == "paper" or input == "spock")) or (computerChoice == "spock" and (input == "rock" and input == "scissors")))
        {
            response = "Player wins!";
        }
        
    }
    
    return response;
}

std::string RockPaperScissors::getChoice()
{
    int num = rand() % 100;
    std::string choices_regular[3] = {"rock", "paper", "scissors"};
    std::string choices_ls[5] = {"rock", "paper", "scissors", "lizard", "spock"};
    
    if(isRegular)
    {
        num = num % 3;
        computerChoice = choices_regular[num - 1];
    }
    else
    {
        num = num % 5;
        computerChoice = choices_ls[num - 1];
    }
    
    return computerChoice;
    
}
