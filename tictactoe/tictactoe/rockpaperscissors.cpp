//
//  rockpaperscissors.cpp
//  tictactoe
//
//  Created by Lucy Wang on 1/31/18.
//  Copyright © 2018 Lucy Wang. All rights reserved.
//

#include <stdio.h>
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
    std::string getChoice();
    bool checkInput(std::string input);
    
public:
    void run();
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
        else if((input == "rock" and (computerChoice == "scissors" or computerChoice == "lizard")) or (input == "scissors" and (computerChoice == "paper" or computerChoice == "lizard")) or (input == "paper" and (computerChoice == "rock" or computerChoice == "spock")) or (input == "lizard" and (computerChoice == "paper" or computerChoice == "spock")) or (input == "spock" and (computerChoice == "rock" and computerChoice == "scissors")))
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

bool RockPaperScissors::checkInput(std::string input)
{
    std::string choices_regular[3] = {"rock", "paper", "scissors"};
    std::string choices_ls[5] = {"rock", "paper", "scissors", "lizard", "spock"};
    
    if(isRegular)
    {
        if (std::find(std::begin(choices_regular), std::end(choices_regular), input) != std::end(choices_regular))
        {
            return true;
        }
    }
    else
    {
        if (std::find(std::begin(choices_ls), std::end(choices_ls), input) != std::end(choices_ls))
        {
            return true;
        }
    }
    return false;
}

void RockPaperScissors::run()
{
    std::cout << "Welcome to Rock Paper Scissors\n";
    std::cout << "You will be playing against the computer.\n";
    
    std::cout << "Do you want to play regular rock, paper, scissors or rock, paper, scissors, lizard, spock? Please enter 'regular' or 'ls'.";
    bool valid = false;
    while(!valid)
    {
        std::string input;
        std::cin >> input;
        if (input == "regular")
        {
            isRegular = true;
            valid = true;
            break;
        }
        else if(input == "ls")
        {
            isRegular = false;
            valid = true;
            break;
        }
        else
        {
            std::cout << "Please enter a valid choice ('regular' or 'ls')";
        }
    }
    getChoice();
    
    std::cout << "Player: Choose rock, paper, or scissors";
    valid = false;
    while(!valid)
    {
        std::string inputStr;
        std::cin >> inputStr;
        
        if(checkInput(inputStr))
        {
            std::cout << checkWin(inputStr);
        }
        else
        {
            std::cout << "Please input a valid choice";
        }
    }
    
}