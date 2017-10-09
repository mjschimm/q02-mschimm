#include "Piezas.h"
#include <vector>

/** CLASS Piezas
 * Class for representing a Piezas vertical board, which is roughly based
 * on the game "Connect Four" where pieces are placed in a column and 
 * fall to the bottom of the column, or on top of other pieces already in
 * that column. For an illustration of the board, see:
 *  https://en.wikipedia.org/wiki/Connect_Four
 *
 * Board coordinates [row,col] should match with:
 * [2,0][2,1][2,2][2,3]
 * [1,0][1,1][1,2][1,3]
 * [0,0][0,1][0,2][0,3]
 * So that a piece dropped in column 2 should take [0,2] and the next one
 * dropped in column 2 should take [1,2].
**/


/**
 * Constructor sets an empty board (default 3 rows, 4 columns) and 
 * specifies it is X's turn first
**/
Piezas::Piezas()
{
    turn = X;
    
    std::vector<Piece> tmp (4, Blank);
    for(int i=0; i<BOARD_ROWS; i++) {
        board.push_back(tmp);
    }
}

/**
 * Resets each board location to the Blank Piece value, with a board of the
 * same size as previously specified
**/
void Piezas::reset()
{
    for(int i=0; i<BOARD_ROWS; i++) {
        for(int j=0; j<BOARD_COLS; j++) {
            board[i][j] = Blank;
        }
    }
}

/**
 * Places a piece of the current turn on the board, returns what
 * piece is placed, and toggles which Piece's turn it is. dropPiece does 
 * NOT allow to place a piece in a location where a column is full.
 * In that case, placePiece returns Piece Blank value 
 * Out of bounds coordinates return the Piece Invalid value
 * Trying to drop a piece where it cannot be placed loses the player's turn
**/ 
Piece Piezas::dropPiece(int column)
{
    if(column < 0 || column >= BOARD_COLS) {
         if(turn == X) {
            turn = O;
        }
        else {
            turn = X;
        }
        return Invalid;
    }
    if(board[2][column] != Blank) {
         if(turn == X) {
            turn = O;
        }
        else {
            turn = X;
        }
        return Blank;
    }
    for(int row=0; row<BOARD_ROWS; row++) {
        if(board[row][column] == Blank) {
            board[row][column] = turn;
            if(turn == X) {
                turn = O;
                return X;
            }
            else {
                turn = X;
                return O;
            }
            break;
        }
    }
    if(turn == X) {
        turn = O;
        return X;
    }
    else {
        turn = X;
        return O;
    }
}

/**
 * Returns what piece is at the provided coordinates, or Blank if there
 * are no pieces there, or Invalid if the coordinates are out of bounds
**/
Piece Piezas::pieceAt(int row, int column)
{
    if(row >= BOARD_ROWS || column >= BOARD_COLS || row < 0 || column < 0) {
        return Invalid;
    }
    else {
        return board[row][column];
    }
}

/**
 * Returns which Piece has won, if there is a winner, Invalid if the game
 * is not over, or Blank if the board is filled and no one has won ("tie").
 * For a game to be over, all locations on the board must be filled with X's 
 * and O's (i.e. no remaining Blank spaces). The winner is which player has
 * the most adjacent pieces in a single line. Lines can go either vertically
 * or horizontally. If both X's and O's have the same max number of pieces in a
 * line, it is a tie.
**/
Piece Piezas::gameState()
{
    for(int i=0; i<BOARD_ROWS; i++) {
        for(int j=0; j<BOARD_COLS; j++) {
            if(board[i][j] == Blank) {
                return Invalid;
            }
        }
    }
    int number_of_os = 0;
    int highest_os = 0;
    int highest_xs = 0;
    int number_of_xs = 0;
    Piece last_piece;
    for(int i=0; i<BOARD_ROWS; i++) {
        for(int j=0; j<BOARD_COLS; j++) {
            if(board[i][j] == X) {
                if(number_of_xs == 0) {
                    last_piece = X;
                    number_of_xs++;
                }
                else {
                    if(last_piece == X) {
                        number_of_xs++;
                    }
                }
            }
            if(board[i][j] == O) {
                if(number_of_os == 0) {
                    last_piece = O;
                    number_of_os++;
                }
                else {
                    if(last_piece == O) {
                        number_of_os++;
                    }
                }
            }
        }
        if(number_of_xs > highest_xs) {
            highest_xs = number_of_xs;
        }
        if(number_of_os > highest_os) {
            highest_os = number_of_os;
        }
        number_of_xs = 0;
        number_of_os = 0;
    }
    for(int i=0; i<BOARD_COLS; i++) {
        for(int j=0; j<BOARD_ROWS; j++) {
            if(board[j][i] == X) {
                if(number_of_xs == 0) {
                    last_piece = X;
                    number_of_xs++;
                }
                else {
                    if(last_piece == X) {
                        number_of_xs++;
                    }
                }
            }
            if(board[j][i] == O) {
                if(number_of_os == 0) {
                    last_piece = O;
                    number_of_os++;
                }
                else {
                    if(last_piece == O) {
                        number_of_os++;
                    }
                }
            }
        }
        if(number_of_xs > highest_xs) {
            highest_xs = number_of_xs;
        }
        if(number_of_os > highest_os) {
            highest_os = number_of_os;
        }
        number_of_xs = 0;
        number_of_os = 0;
    }
    if(highest_xs > highest_os) {
        return X;
    }
    else if(highest_os > highest_xs) {
        return O;
    }
    else {
        return Blank;
    }
}

