//
//  main.cpp
//  mastermind
//
//  Created by Kriti Jain on 1/31/18.
//  Copyright © 2018 Kriti Jain. All rights reserved.
//

#include <iostream>
#include <cstdlib>

class Mastermind;

class Mastermind
{
    int code;
    
public:
    Mastermind(){};
    Mastermind(int code) : code(code){};
    bool checkGuess(std::string guessCode);
    void run();
};

bool Mastermind::checkGuess(std::string guessCode){
    std::string numberToString = std::to_string(code);
    int correctNumbers = 0;
    int correctLocations = 0;
    if(numberToString == guessCode){
        std::cout << "Congrats you win! You have guessed 4 correct numbers in the correct locations.\n";
        return true;
    }
    std::string tempCode = numberToString;
    for (int i = 0; i < guessCode.length(); i++){
        if (tempCode.find(guessCode[i]) != std::string::npos){ // if digit in code
            correctNumbers++;
            //std::cout << tempCode << "\n"; //checking to see what number was
            std::size_t found = tempCode.find(guessCode[i]);
            tempCode.erase(found, 1);
        }
        if (numberToString[i] == guessCode[i]){
            correctLocations++;
        }
    }
    std::cout << "You have guessed " << correctNumbers << " correct numbers in " << correctLocations << " correct locations.\n";
    return false;
}

void Mastermind::run() {
    // insert code here...
    srand(time(0)); //to get a different random number every time
    int gameCode;
    //gameCode = 1000;
    gameCode = rand()% 10000;
    Mastermind game = Mastermind(gameCode);
    std::cout << "Welcome to Mastermind!\n";
    std::cout << "I have created a code. Try to guess which 4 digits are in my code.\n";
    std::string input;
    std::cin >> input;
    while (!game.checkGuess(input)){
        std::cout << "Guess again.\n";
        std::cin >> input;
    };
    
    //return 0;
}

