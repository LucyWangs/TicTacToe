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
    bool placePiece(Piece p, int row, int col);
    std::string getWinner();
};

class SuperTicTacToe
{
    TicTacToe large_board[3][3];
    //
};

//////////////////////////////
//TicTacToe Implementations

//This should return the board
std::string* TicTacToe::getGrid()
{
    return *board;
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
bool TicTacToe::placePiece(Piece p, int row, int col)
{
    bool canPlace = false;
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



int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
