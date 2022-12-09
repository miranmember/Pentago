// Prog5Pentago.cpp
//     Play the two-player game of Pentago, trying to get 5 pieces in a row.
//
// Author: Miran, Member
// Program: #5, Pentago using classes
// 4/6/2020
//
#include <iostream>  // Needed to avoid compiler error for the exit() command
#include <cctype>    // For toupper()
using namespace std;

class Board {
private:
    char quad[6][6]; // private class for the 2d array
public:
    Board();//default constructor
    void display_board(); // display board funcion
    int makeMove(char row, int column, char chartomove);//make move funcion which also doubles as a way to check if a piece is valid or not
    void rotate(int quadrant, char direction);//roates the pieces
    void checkwin(int &win_o, int &win_x);//checks for winning conditions
};
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------//
Board::Board() {//default constructor
    for (int i = 0; i < 6; i++) {
        for (int y = 0; y < 6; y++) {
            quad[i][y]='.';
        }
    }
}
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------//
void Board::display_board() {//displays the baord in the main, as default it has "." but gets replaces as players make move
    cout << "    1   2   3   4   5   6   \n"
            "  1-----------------------2 \n"
            "A | "<<quad[0][0]<<"   "<<quad[0][1]<<"   "<<quad[0][2]<<" | "<<quad[0][3]<<"   "<<quad[0][4]<<"   "<<quad[0][5]<<" | A\n"// using the 2d array makes the baord look a lot more consistent.
                                                                                                                               "  |           |           | \n"
                                                                                                                               "B | "<<quad[1][0]<<"   "<<quad[1][1]<<"   "<<quad[1][2]<<" | "<<quad[1][3]<<"   "<<quad[1][4]<<"   "<<quad[1][5]<<" | B\n"
                                                                                                                                                                                                                                                  "  |           |           | \n"
                                                                                                                                                                                                                                                  "C | "<<quad[2][0]<<"   "<<quad[2][1]<<"   "<<quad[2][2]<<" | "<<quad[2][3]<<"   "<<quad[2][4]<<"   "<<quad[2][5]<<" | C\n"
                                                                                                                                                                                                                                                                                                                                                                     "  |-----------+-----------| \n"
                                                                                                                                                                                                                                                                                                                                                                     "D | "<<quad[3][0]<<"   "<<quad[3][1]<<"   "<<quad[3][2]<<" | "<<quad[3][3]<<"   "<<quad[3][4]<<"   "<<quad[3][5]<<" | D\n"
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        "  |           |           | \n"
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        "E | "<<quad[4][0]<<"   "<<quad[4][1]<<"   "<<quad[4][2]<<" | "<<quad[4][3]<<"   "<<quad[4][4]<<"   "<<quad[4][5]<<" | E\n"
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                           "  |           |           | \n"
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                           "F | "<<quad[5][0]<<"   "<<quad[5][1]<<"   "<<quad[5][2]<<" | "<<quad[5][3]<<"   "<<quad[5][4]<<"   "<<quad[5][5]<<" | F\n"
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                              "  3-----------------------4  \n"
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                              "    1   2   3   4   5   6  "
         << endl;
}
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------//
int Board::makeMove(char row, int column,char chartomove) {// makes move
    column = column - 49; // since input for column was using char. this turns it back to integer
    if (row == 'a') {// assigns row depanding on the letter user typed in. so if user types 'a' then assings row 0.
        row = 0;
    } else if (row == 'b') {
        row = 1;
    } else if (row == 'c') {
        row = 2;
    } else if (row == 'd') {
        row = 3;
    } else if (row == 'e') {
        row = 4;
    } else if (row == 'f') {
        row = 5;
    }

    if (quad[row][column] != '.') {//checks weather the space is availible, otherwise returns 1, which raises an error and asks the user to type in another valid piece
        return 1;
    }
    quad[row][column] = chartomove;// if the error checking is passed then makes move.
}
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------//
void Board::rotate(int quadrant, char direction) {//rotates the board
    quadrant = quadrant - 48;// since took in input as char this turns it back to integer.
    int x=0;
    int y=0;
    char temp = '.';
    if (quadrant == 1) {x=0;y=0;}//assings the first piece depanding on what the user put in as the quadrant. for example, if the user puts in quadrant 2, then x = 3 and y =0.
    else if (quadrant == 2) {x=0;y=3;}
    else if (quadrant == 3) {x=3;y=0;}
    else if (quadrant == 4) {x=3;y=3;}
    if (direction == 'r') {//rotates the baord after having x and y assinged depanding on the user input
        temp = quad[x][y];//creates a temp value cause i will be replacing the piece
        quad[x][y] = quad[x+2][y];
        quad[x+2][y] = quad[x+2][y+2];
        quad[x+2][y+2] = quad[x][y+2];
        quad[x][y+2] = temp;
        temp = quad[x][y+1];
        quad[x][y+1] = quad[x+1][y];
        quad[x+1][y] = quad[x+2][y+1];
        quad[x+2][y+1] = quad[x+1][y+2];
        quad[x+1][y+2] = temp;
    }
    else if (direction == 'l') {//roates the baord left if user input was 'l'
        char temp = quad[x][y];
        quad[x][y] = quad[x][y+2];
        quad[x][y+2] = quad[x+2][y+2];
        quad[x+2][y+2] = quad[x+2][y];
        quad[x+2][y] = temp;
        temp = quad[x][y+1];
        quad[x][y+1]= quad[x+1][y+2];
        quad[x+1][y+2] = quad[x+2][y+1];
        quad[x+2][y+1] = quad[x+1][y];
        quad[x+1][y] = temp;
    }
}
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------//
void Board::checkwin(int &win_o, int &win_x) {// checks weather there was a winning condition
//--------------------------------------//ROW//checks all the rows
    for (int y = 0; y < 6; y++) {// checks the left 5 pieces in each row.
        int x = 0;
        int o = 0;
        for (int i = 0; i < 6; i++) {
            if (quad[y][i] == 'X') {
                if (quad[y][i + 1] == 'X') {
                    x++;
                }
                if (x == 4) {
                    win_x = 1;// if there are 4 x in a row then win-x bcomes 1 which in the main loop creates the winniing condion.
                }
            }
            else if(quad[y][i] == 'O') {
                if (quad[y][i + 1] == 'O') {
                    o++;
                }
                if (o == 4) {
                    win_o = 1;// if there are 4 o in a row then win-x bcomes 1 which in the main loop creates the winniing condion.
                }
            }
        }
    }
    for (int y = 0; y < 6; y++) {// checks the right 5 pieces in each row
        int x = 0;
        int o = 0;
        for (int i = 5; i < 0; i--) {
            if (quad[y][i] == 'X') {
                if (quad[y][i - 1] == 'X') {
                    x++;
                }
                if (x == 4) {
                    win_x = 1;
                }
            }
            else if(quad[y][i] == 'O') {
                if (i < 1) {
                    if (quad[y][i - 1] == 'O') {
                        o++;
                    }
                    if (o == 4) {
                        win_o = 1;
                    }

                }
            }
        }
    }
//---------------------------------------//COLUMN//checks the columns
    for (int y = 0; y < 6; y++) {// checks 4 upper pieces in each column
        int x = 0;
        int o = 0;
        for (int i = 0; i < 6; i++) {
            if (quad[i][y] == 'X') {
                if (quad[i+1][y] == 'X') {
                    x++;
                }
                if (x == 4) {
                    win_x = 1;
                }
            }
            else if(quad[i][y] == 'O') {
                if (quad[i+1][y] == 'O') {
                    o++;
                }
                if (o == 4) {
                    win_o = 1;
                }


            }
        }
    }
    for (int y = 0; y < 6; y++) {//checks 4 lower pieces in each column
        int x = 0;
        int o = 0;
        for (int i = 5; i < 0; i--) {
            if (quad[i][y] == 'X') {

                if (quad[i-1][y] == 'X') {
                    x++;
                }
                if (x == 4) {
                    win_x = 1;
                }

            }
            else if(quad[i][y] == 'O') {

                if (quad[i-1][y] == 'O') {
                    o++;
                }
                if (o == 4) {
                    win_o = 1;
                }


            }
        }
    }
//--------------------------------------------//DIAGONAL RIGHT//
    int y = 0;
    int x = 0;
    int o = 0;
    for (int i = 0; i < 6; i++) {//checks diagnal right middle
        if (quad[i][y] == 'X') {

            if (quad[i + 1][y + 1] == 'X') {
                x++;
            }
            if (x == 4) {
                win_x = 1;
            }

            y++;
        }
        else if (quad[i][y] == 'O') {

            if (quad[i + 1][y + 1] == 'O') {
                o++;
            }
            if (o == 4) {
                win_o = 1;
            }

            y++;
        }
    }
    y = 1;
    x = 0;
    o = 0;
    for (int i = 0; i < 6; i++) {//checks diagnal right
        if (quad[i][y] == 'X') {

            if (quad[i + 1][y + 1] == 'X') {
                x++;
            }
            if (x == 4) {
                win_x = 1;
            }

            y++;
        }
        else if (quad[i][y] == 'O') {
            if (quad[i + 1][y + 1] == 'O') {
                o++;
            }
            if (o == 4) {
                win_o = 1;

            }
            y++;
        }
    }
    y = 0;
    x = 0;
    o = 0;
    for (int i = 1; i < 6; i++) {
        if (quad[i][y] == 'X') {

            if (quad[i + 1][y + 1] == 'X') {
                x++;
            }
            if (x == 4) {
                win_x = 1;
            }

            y++;
        }
        else if (quad[i][y] == 'O') {

            if (quad[i + 1][y + 1] == 'O') {
                o++;
            }
            if (o == 4) {
                win_o = 1;
            }

            y++;
        }
    }
//---------------------------------------------------------------//DIAGONAL LEFT//
    y = 5;
    x = 0;
    o = 0;
    for (int i = 0; i < 6; i++) {//checks diagnal left middle
        if (quad[i][y] == 'X') {

            if (quad[i + 1][y - 1] == 'X') {
                x++;
            }
            if (x == 4) {
                win_x = 1;
            }

            y--;
        }
        else if (quad[i][y] == 'O') {

            if (quad[i + 1][y - 1] == 'O') {
                o++;
            }
            if (o == 4) {
                win_o = 1;
            }

            y--;
        }
    }
    y = 5;
    x = 0;
    o = 0;
    for (int i = 1; i < 6; i++) {//checks diagnal left
        if (quad[i][y] == 'X') {

            if (quad[i + 1][y - 1] == 'X') {
                x++;
            }
            if (x == 4) {
                win_x = 1;
            }

            y--;
        }
        else if (quad[i][y] == 'O') {

            if (quad[i + 1][y - 1] == 'O') {
                o++;
            }
            if (o == 4) {
                win_o = 1;
            }

            y--;
        }
    }
    y = 4;
    x = 0;
    o = 0;
    for (int i = 1; i < 6; i++) {//checks diagnal left
        if (quad[i][y] == 'X') {

            if (quad[i + 1][y - 1] == 'X') {
                x++;
            }
            if (x == 4) {
                win_x = 1;
            }

            y--;
        }
        else if (quad[i][y] == 'O') {
            if (quad[i + 1][y - 1] == 'O') {
                o++;
            }
            if (o == 4) {
                win_o = 1;
            }
            y--;
        }
    }
}
class Node {
public:
    Board theBoard1;
    char chartomove1;
    int  inttomove1;
    Node *pNext;
};
void displayList( Node *pTemp)
{
    cout << "List of moveNumber:playerToMove is ";
    while( pTemp != NULL) {
        cout << pTemp->inttomove1 << ":" << pTemp->chartomove1;
        if( pTemp->pNext != NULL) {
            cout << "->";
        }
        pTemp = pTemp->pNext;
    }
    cout << endl;
}
void prependNode(Node * &pHead, int inttomove,char chartomove,Board theBoard)
{

    Node *pTemp = new Node;
    pTemp->inttomove1 = inttomove;
    pTemp->chartomove1 = chartomove;
    pTemp->theBoard1 = theBoard;
    pTemp->pNext = pHead;
    pHead = pTemp;
}
void deleteNode(Node * &pHead, int &inttomove,char &chartomove,Board &theBoard)
{
    if( pHead->pNext == NULL) {
        cout << "*** You cannot undo past the beginning of the game.  Please retry. ***" << endl;
    }
    else {
        cout << "* Undoing move *" << endl;
        Node *pTemp = pHead;
        pHead = pHead->pNext;
        delete pTemp;
        inttomove = pHead->inttomove1;
        chartomove = pHead->chartomove1;
        theBoard = pHead->theBoard1;
    }
}
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------//
void displayInstructions()
{
    cout << "\n"
         << "Play the two-player game of Pentago. Be the first to get 5 in a row. \n"
         << "                                                                 \n"
         << "Pentago is played on a 6 by 6 board, divided into four 3 by 3    \n"
         << "quadrants.  There are two players, X and O, who alternate turns. \n"
         << "The goal of each player is to get five of their pieces in a row, \n"
         << "either horizontally, vertically, or diagonally.                  \n"
         << "                                                                 \n"
         << "Players take turns placing one of their pieces into an empty     \n"
         << "space anywhere on the board, then choosing one of the four       \n"
         << "board quadrants to rotate 90 degrees left or right.              \n"
         << "                                                                 \n"
         << "If both players get five in a row at the same time, or the       \n"
         << "last move is played with no five in a row, the game is a tie.    \n"
         << "If a player makes five a row by placing a piece, there is no need\n"
         << "to rotate a quadrant and the player wins immediately.            \n"
         << "                                                                 \n"
         << "     Play online at:  https://perfect-pentago.net                \n"
         << "     Purchase at:     www.mindtwisterusa.com                     \n"
         << "                                                                 \n"
         << "For each move provide four inputs:                               \n"
         << "   row (A-F), column (1-6), quadrant (1-4), rotation direction (L or R) \n"
         << "For instance input of B32R places the next piece at B3 and then  \n"
         << "would rotate quadrant 2 (upper-right) to the right (clockwise).  \n"
         << "                                                                 \n"
         << "At any point enter 'x' to exit, 'i' for instructions, or 'u' to undo." << endl;
} // end displayInstructions()
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------//
int main() {
    Board theBoard;// Create the board as an instance of the Board class
    char row,column,quadrant,direction; // for input from the user
    int inttomove = 1;//number of times the game has had a play
    char chartomove = 'X';//charater's turn it flips between x and o
    //-----------------------------------------------------------------------------------//
    cout << "Welcome to Pentago, where you try to get 5 of your pieces in a line." << endl
         <<"At any point enter 'x' to exit, 'i' for instructions, or 'u' to undo." << endl;
    //-----------------------------------------------------------------------------------//
    Node *pHead = NULL;
    prependNode(pHead, inttomove,chartomove,theBoard);
    while (true) {// main loop where everything is and will run infinitaly unless winning condion is met
        theBoard.display_board();// displays updated board each loop
        displayList(pHead);
        cout << inttomove << ". Enter row, column, quadrant, direction for " << chartomove << ':' << endl;// displays numver of turns and the character.
        //--------------------------------//
        cin >> row;// takes in row as char
        row = tolower(row);// incase user enter with uppercase
        if (row == 'i') {//display information if the user inputs i
            displayInstructions();
            continue;
        }
        else if (row == 'x') {// exit the game if the user enter x
            cout << "Exiting program...";
            return 0;
        }
        if (row == 'u') {//display information if the user inputs i
            deleteNode(pHead, inttomove, chartomove, theBoard);
            continue;
        }
        else if (!(row > ('a'-1) && row < ('f'+1))){// makes sure the user only enter the letters from a to f
            cout << "     *** Invalid move row.  Please retry." << endl;
            cin >> column >> quadrant >> direction;// takes in the rest of the input and discards it because user entered incorrect row.
            continue;
        }
        //--------------------------------//
        cin >> column;//input colomn
        if (!(column > 48 && column < 55)){//bound the input between 1 to 5 but since column is char its at 48.
            cout << "     *** Invalid move column.  Please retry." << endl;
            cin >> quadrant >> direction;// takes in the rest of the input and discards it because user entered incorrect column.
            continue;
        }
        //--------------------------------//
        cin >> quadrant;
        if (!(quadrant > 48 && quadrant < 53)) {// /bound the input between 1 to 4 but since column is char its at 48.
            cout << "     *** Selected quadrant is invalid.  Please retry." << endl;
            cin  >> direction;// takes in the rest of the input and discards it because user entered incorrect quadrant.
            continue;
        }
        //--------------------------------//
        cin >> direction;
        direction = tolower(direction);//incase user enters with upper case
        if (!(direction == 'r' || direction == 'l')){// makes sure user can only enter either r or l
            cout << "     *** Quadrant rotation direction is invalid.  Please retry.";
            continue;
        }
        //--------------------------------//
        if ((theBoard.makeMove(row, column, chartomove)) == 1) {// in caes the board already has a piece where the user entered the makemove funcion returns 1 which coauses the messege to appaer.
            cout << "     *** That board location is already taken.  Please retry." << endl;
            continue;
        }
        theBoard.rotate(quadrant, direction);
        //--------------------------------//
        int win_o = 0;
        int win_x = 0;
        theBoard.checkwin(win_o,win_x);// modifies win_o or win _x to 1, if the winning condition was met.
        if ( win_o == 1 && win_x == 1) { //incase both players won at the same time
            cout << "     *** Both X and O have won.  Game is a tie."<< endl;
            (theBoard.makeMove(row, column, chartomove));
            theBoard.display_board();
            cout << "Thanks for playing.  Exiting... ";
            return 0;
        }
        else if (win_x == 1){//incase only x wins.
            cout << "     *** X has won the game!" << endl;
            (theBoard.makeMove(row, column, chartomove));
            theBoard.display_board();
            cout << "Thanks for playing.  Exiting... ";
            return 0;
        }
        else if (win_o == 1) {//incase only o wins
            cout << "     *** O has won the game!" << endl;
            (theBoard.makeMove(row, column, chartomove));
            theBoard.display_board();
            cout << "Thanks for playing.  Exiting... ";
            return 0;
        }
        //--------------------------------//
        inttomove++;//increases each loop because the unless user enters wrong input.
        if (chartomove == 'X') {//flipps the player between x and o
            chartomove = 'O';
        }
        else {
            chartomove = 'X';
        }
        if (inttomove == 37){//incase no one wins and the baord is filled the game ends with a tie
            cout << "*** No one has won.  Game is a tie.";
            theBoard.display_board();
            cout << "Thanks for playing.  Exiting... " << endl;
            return 0;
        }
        prependNode(pHead, inttomove,chartomove,theBoard);
    }
}
