//
//  main.cpp
//  tictactoe
//
//  Created by Lucy Wang on 1/28/18.
//  Copyright © 2018 Lucy Wang. All rights reserved.
//

#include <iostream>

class TicTacToe;
class SuperTicTacToe;
                                                                            //I don't know if we need this to be an enum
enum Piece
{
    X,
    O
};

                                                                            //I don't know if we need this player struct

////////////////////////
// "Player.h"
//
// This struct is responsible for storing all the details
//    that identify a player
// Player is a header-only object.
struct Player
{
    std::string name;
    
    friend std::istream &operator>>(std::istream &is, Player &p)
    {
        is >> p.name;
        return is;
    }
    
    friend std::ostream &operator<<(std::ostream &os, const Player &p)
    {
        os << p.name;
        return os;
    }
};

////////////////////////
//TicTacToe Class
// This class is responsible for one game of regular tic-tac-toe (3 X 3 grid)

class TicTacToe
{
    std::string board[3][3];
    Player player1;
    Player player2;
    bool isDone;
    
public:
    std::string* getGrid();
    Piece getTurn(Piece current);
    bool checkWin();
    bool placePiece(Piece p, char location);
    std::string getWinner();
    void printGrid();
    bool isFull();
};

class SuperTicTacToe
{
    TicTacToe large_board[3][3];
    Player player1;
    Player player2;
    
public:
    std::string* getLargeGrid();
    //bool chooseBox(Piece p, char location);
    Piece getTurn(Piece current);
    bool checkLargeWin();
    bool placePiece(Piece p, char super_location, char location);
    bool placePiece(Piece p, char location);
    bool checkGridStatus(char super_location);
    
};

//////////////////////////////
//TicTacToe Implementations

//This should return the board
std::string* TicTacToe::getGrid()
{
    return *board;
}

void TicTacToe::printGrid(){
    std::string a,b,c,d,e,f,g,h,i;
    if (board[0][0]==""){
        a='A';
    }
    else{
        a=board[0][0];
    }
    if (board[0][1]==""){
        b='B';
    }
    else{
        b=board[0][1];
    }
    if (board[0][2]==""){
        c='C';
    }
    else{
        c=board[0][2];
    }
    if (board[1][0]==""){
        d='D';
    }
    else{
        d=board[1][0];
    }
    if (board[1][1]==""){
        e='E';
    }
    else{
        e=board[1][1];
    }
    if (board[1][2]==""){
        f='F';
    }
    else{
        f=board[1][2];
    }
    if (board[2][0]==""){
        g='G';
    }
    else{
        g=board[2][0];
    }
    if (board[2][1]==""){
        h='H';
    }
    else{
        h=board[2][1];
    }
    if (board[2][2]==""){
        i='I';
    }
    else{
        i=board[2][2];
    }
    
    
    std::cout << a << "  |  " << b <<"  |  "<< c << '\n';
    std::cout << "-----------" << '\n';
    std::cout << d <<"  |  "<< e <<"  |  "<< f << '\n';
    std::cout << "-----------" << '\n';
    std::cout << g <<"  |  "<< h <<"  |  "<< i << '\n';
}

//This method should check if there is already a win on the board
bool TicTacToe::checkWin()
{
    bool horizontalWin = false;
    bool verticalWin = false;
    bool diagonalWin = false;
    
    //Checks the rows and the columns
    for(int i = 0; i < 3; i++)
    {
        //Checks the rows for the win
        if(board[i][0] != "" and board[i][0] == board[i][1] and board[i][1] == board[i][2])
        {
            horizontalWin = true;
        }
        //Checks the columns for the win
        else if(board[0][i] != "" and board[0][i] == board[1][i] and board[1][i] == board[2][i])
        {
            verticalWin = true;
        }
    }
    
    //check diagonals
    if(board[0][0] != "" and board[0][0] == board[1][1] and board[1][1] == board[2][2])
    {
        diagonalWin = true;
    }
    else if(board[0][2] != "" and board[0][2] == board[1][1] and board[1][1] == board[2][0])
    {
        diagonalWin = true;
    }
    
    return diagonalWin or horizontalWin or verticalWin;
}

//This should place the piece based on specified location. Returns whether or not this action can be done
bool TicTacToe::placePiece(Piece p, char location)
{
    bool canPlace = false;
//    if (row>=3 or col>=3){
//        return false;
//    }
    int row, col;
    
    if(location == 'A')
    {
        row = 0;
        col = 0;
    }
    else if(location == 'B')
    {
        row = 0;
        col = 1;
    }
    else if(location == 'C')
    {
        row = 0;
        col = 2;
    }
    else if(location == 'D')
    {
        row = 1;
        col = 0;
    }
    else if(location == 'E')
    {
        row = 1;
        col = 1;
    }
    else if(location == 'F')
    {
        row = 1;
        col = 2;
    }
    else if(location == 'G')
    {
        row = 2;
        col = 0;
    }
    else if(location == 'H')
    {
        row = 2;
        col = 1;
    }
    else if(location == 'I')
    {
        row = 2;
        col = 2;
    }
    else
    {
        row = NULL;
        col = NULL;
        canPlace = false;
    }
    
    if(board[row][col] == "")
    {
        switch(p)
        {
            case X:
                board[row][col] = "X";
                break;
            case O:
                board[row][col] = "O";
                break;
        }
        canPlace = true;
    }
    else
    {
        //something is already in the board at that location
        canPlace = false;
    }
    return canPlace;
}

//Returns the next piece to be played
Piece TicTacToe::getTurn(Piece current)
{
    switch(current)
    {
        case X:
            return O;
        case O:
            return X;
    }
}

//Returns bool of whether or not board is full
bool TicTacToe::isFull(){
    for(int i = 0; i < 3; i++){
        for (int j=0; j<3; j++){
            if (board[i][j] == ""){
                return false;
            }
        }
    }
    return true;
}

//////////////////////////////////
//SuperTicTacToe Implementation
//This class is responsible for a large game of tic-tac-toe,
//where there is a 3 X 3 grid



int main(int argc, const char * argv[]) {
    // insert code here...
    
    TicTacToe *game = new TicTacToe;
    std::cout << "Welcome to Super Tic Tac Toe!\n";
    std::cout << "Player 1 will place O's and Player 2 will place X's\n";
    while(!game->checkWin() and !game->isFull()){
        
        //print tictactoe board
        game->printGrid();
        
        //input from player 1 (O's)
        std::cout << "Player 1: enter a letter\n";
        char inputChar;
        std::cin  >> inputChar;
        
        //checks if move is valid, places piece
        while(!game->placePiece(O,inputChar)){
            std::cout << "That is not an empty spot.  Please pick another letter \n";
            std::cin  >> inputChar;
        }
        //checks for win or full board
        if(game->checkWin() || game->isFull()){break;}
        
        //print tictactoe board
        game->printGrid();
        
        //input from player 2 (X's)
        std::cout << "Player 2: enter a row and column\n";
        std::cin  >> inputChar;
        
        //checks if move is valid, places piece
        while(!game->placePiece(X,inputChar)){
            std::cout << "That is not an empty spot.  Please pick another letter \n";
            std::cin  >> inputChar;
        }
    }
    //if loop exited, determines why and outputs appropriate statement
    game->printGrid();
    if(game->checkWin()){
        std::cout << "Congrats you won!";
    }
    else{
        std::cout << "It's a tie!";
    }


}
