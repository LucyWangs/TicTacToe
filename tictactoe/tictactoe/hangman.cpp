//
//  hangman.cpp
//  tictactoe
//
//  Created by Kriti Jain on 2/1/18.
//  Copyright © 2018 Lucy Wang. All rights reserved.
//


#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>
const int num_tries = 5;

class Hangman{
    std::string word_to_guess;
    
    
    
public:
    Hangman(){};
    Hangman(std::string word_to_guess) : word_to_guess(word_to_guess){};
    int populateWord(char guessed_letter, std::string secret_word, std::string &used_letters);
    bool runGame(std::string progress, int wrong_guesses);
    void run();
    
};

int Hangman::populateWord(char guessed_letter, std::string secret_word, std::string &used_letters){
    int ii;
    int matches = 0;
    int len_word = secret_word.length();
    
    for (ii = 0; ii< len_word; ii++){
        if (guessed_letter == used_letters[ii]){
            return 0;
        }
        if (guessed_letter == secret_word[ii]){
            used_letters[ii] = guessed_letter;
            matches++;
        }
    }
    return matches;
}

bool Hangman::runGame(std::string progress,int wrong_guesses){
    if (wrong_guesses >= num_tries){
        return false;
    }
    else if (word_to_guess == progress){
        std::cout << "You guessed the word " << word_to_guess << " correctly. \n";
        std::cout << "Good job!!!";
        return false;
    }
    return true;
    
}
void Hangman::run(){
    srand(time(0));
    char letter;
    int wrong_guesses = 0;
    std::string word_to_guess;
    std::ifstream file;
    file.open ("/Users/kjain/Documents/Final Project/deminem/deminem/wordsEn.txt");
    std::string str;
    std::vector<std::string> mylist;
    while(!file.eof()){
        getline(file, str);
        mylist.push_back(str);
    }
    
    file.close();
    
    int n = rand() % 10000;
    word_to_guess = mylist[n];
    word_to_guess.erase(word_to_guess.length()-1, 1);
    Hangman h = Hangman(word_to_guess);
    
    std::string progress(word_to_guess.length(), '*');
    std::cout << "Welcome to Hangman!!! Get ready to guess a word.";
    std::cout << "\n\nEach letter is represented by an asterisk.";
    std::cout << "\nEach round you are to guess ONLY one letter.";
    std::cout << "\nIf you do not guess a letter that is contained in the secret word, you expend one of your tries";
    std::cout << "\nYou have " << num_tries << " tries to try and guess the secret word.";
    std::cout << "----------------------------------------------------";
    
    while (h.runGame(progress,wrong_guesses)){
        std::cout << "\n\n\n" << progress;
        std::cout << "\nGuess a letter\n";
        std::cin >> letter;
        if (h.populateWord(letter, word_to_guess, progress) == 0){
            std::cout << "\nWhoops! That letter is not in the secret word";
            wrong_guesses++;
        }
        else{
            std::cout << "\nCongratulations!!! You have correctly guessed a letter.";
        }
        std::cout << "\nYou have " << num_tries - wrong_guesses << " guesses remaining.";
        
    }
    
    if (wrong_guesses == num_tries){
        std::cout << "\nI am sorry, but you have lost.";
        std::cout << "\nFor consolation, the secret word was : " << word_to_guess << "\n";
    }
    
    std::cin.ignore();
    std::cin.get();
}
