// RealTeam2-TicTacToe.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int X = 0;
int O = 0;

// Initillization Header
void displayBoard(char board[3][3]);

void GameEnd(char board[3][3])
{

    string input;
    cout << "Wins for X: " << X << endl;
    cout << "Wins for O: " << O;
    cout << "Would you like to Play Again Y/N: ";
    cin >> input;

    // Exit out of Game (Eddie)
    if ((input == "N") || (input == "n"))
    {
        return;
    }

    // Restarts the Game (Eddie)
    else if ((input == "Y") || (input == "y"))
    {
        board[0][0] = ' ';
        board[0][1] = ' ';
        board[0][2] = ' ';
        board[1][0] = ' ';
        board[1][1] = ' ';
        board[1][2] = ' ';
        board[2][0] = ' ';
        board[2][1] = ' ';
        board[2][2] = ' ';

        displayBoard(board);
    }
}

//TurnTracker class to keep track of whose turn it is in Tic-Tac-Toe.
//Written by Joseph Miele.
class TurnTracker
{
public:
    //CONSTRUCTORS

    //Default constructor: Set the turn to X
    TurnTracker() {
        turn = 'X';
    }
    //Constructor: Set the turn to the input value if it is 'X' or 'O'
    //Otherwise, print an error message and default to X
    TurnTracker(char startingTurn) {
        if (startingTurn == 'X' || startingTurn == 'O') {
            turn = startingTurn;
        }
        else {
            cout << "Error in turnTracker constructor: The provided value was " << startingTurn << " (expected 'X' or 'O')" << endl;
            turn = 'X';
        }
    }

    

    //MUTATORS

    //Switch the turn between 'X' and 'O'
    //If it's anything else, print an error message and do not change the turn
    void switchTurn() {
        if (turn == 'X') {
            turn = 'O';
        }
        else if (turn == 'O') {
turn = 'X';
        }
        else {
            cout << "Error in turnTracker function switchTurn(): The current turn value was " << turn << " (expected 'X' or 'O')" << endl;
        }
    }
    //Set the turn to the input value if it is 'X' or 'O'
    //If it's not, print an error message and make no change
    void setTurn(char newTurn) {
        if (newTurn == 'X' || newTurn == 'O') {
            turn = newTurn;
        }
        else {
            cout << "Error in turnTracker function setTurn(): The provided value was " << newTurn << " (expected 'X' or 'O')" << endl;
        }
    }

    //ACCESSORS

    //Return the current turn value
    char getTurn() {
        return turn;
    }

private:
    char turn;
};

//this is to display the board and its updates, I didn't want to put it in the class without your input-nicole
void displayBoard(char board[3][3]) {
    cout << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << board[i][j];
            if (j < 2) {
                cout << "  | ";
            }
        }
        if (i < 2) {
            cout << "\n------------\n";
        }
    }

}

//Function to check if someone has won the game
//Implemented by Dylan
void checkWin(char board[3][3])
{
    //Check if there is a win in row 1
    if ((board[0][0] == 'X' && board[0][1] == 'X' && board[0][2] == 'X')
        || (board[0][0] == 'x' && board[0][1] == 'x' && board[0][2] == 'x')
        || (board[0][0] == 'O' && board[0][1] == 'O' && board[0][2] == 'O')
        || (board[0][0] == 'o' && board[0][1] == 'o' && board[0][2] == 'o'))
    {
        cout << board[0][0] << " wins!";

        if (board[0][0] == 'X' || board[0][0] == 'x')
        {
            X++;
        }

        else if (board[0][0] == 'O' || board[0][0] == 'o')
        {
            O++;
        }

        GameEnd(board);
    }
    //Check if there is a win in row 2
    else if ((board[1][0] == 'X' && board[1][1] == 'X' && board[1][2] == 'X')
        || (board[1][0] == 'x' && board[1][1] == 'x' && board[1][2] == 'x')
        || (board[1][0] == 'O' && board[1][1] == 'O' && board[1][2] == 'O')
        || (board[1][0] == 'o' && board[1][1] == 'o' && board[1][2] == 'o'))
    {
        cout << board[1][0] << " wins!";

        if (board[1][0] == 'X' || board[1][0] == 'x')
        {
            X++;
        }

        else if (board[1][0] == 'O' || board[1][0] == 'o')
        {
            O++;
        }

        GameEnd(board);
    }
    //Check if there is a win in row 3
    else if ((board[2][0] == 'X' && board[2][1] == 'X' && board[2][2] == 'X')
        || (board[2][0] == 'x' && board[2][1] == 'x' && board[2][2] == 'x')
        || (board[2][0] == 'O' && board[2][1] == 'O' && board[2][2] == 'O')
        || (board[2][0] == 'o' && board[2][1] == 'o' && board[2][2] == 'o'))
    {
        cout << board[2][0] << " wins!";

        if (board[2][0] == 'X' || board[2][0] == 'x')
        {
            X++;
        }

        else if (board[2][0] == 'O' || board[2][0] == 'o')
        {
            O++;
        }

        GameEnd(board);
    }
    //Check if there is a win in column 1
    else if ((board[0][0] == 'X' && board[1][0] == 'X' && board[2][0] == 'X')
        || (board[0][0] == 'x' && board[1][0] == 'x' && board[2][0] == 'x')
        || (board[0][0] == 'O' && board[1][0] == 'O' && board[2][0] == 'O')
        || (board[0][0] == 'o' && board[1][0] == 'o' && board[2][0] == 'o'))
    {
        cout << board[0][0] << " wins!";

        if (board[0][0] == 'X' || board[0][0] == 'x')
        {
            X++;
        }

        else if (board[0][0] == 'O' || board[0][0] == 'o')
        {
            O++;
        }

        GameEnd(board);
    }
    //Check if there is a win in column 2
    else if ((board[0][1] == 'X' && board[1][1] == 'X' && board[2][1] == 'X')
        || (board[0][1] == 'x' && board[1][1] == 'x' && board[2][1] == 'x')
        || (board[0][1] == 'O' && board[1][1] == 'O' && board[2][1] == 'O')
        || (board[0][1] == 'o' && board[1][1] == 'o' && board[2][1] == 'o'))
    {
        cout << board[0][1] << " wins!";

        if (board[0][1] == 'X' || board[0][1] == 'x')
        {
            X++;
        }

        else if (board[0][1] == 'O' || board[0][1] == 'o')
        {
            O++;
        }

        GameEnd(board);
    }
    //Check if there is a win in column 3
    else if ((board[0][2] == 'X' && board[1][2] == 'X' && board[2][2] == 'X')
        || (board[0][2] == 'x' && board[1][2] == 'x' && board[2][2] == 'x')
        || (board[0][2] == 'O' && board[1][2] == 'O' && board[2][2] == 'O')
        || (board[0][2] == 'o' && board[1][2] == 'o' && board[2][2] == 'o'))
    {
        cout << board[0][2] << " wins!";

        if (board[0][2] == 'X' || board[0][2] == 'x')
        {
            X++;
        }

        else if (board[0][2] == 'O' || board[0][2] == 'o')
        {
            O++;
        }

        GameEnd(board);
    }
    //Check if there is a win in left to right diagonal
    else if ((board[0][0] == 'X' && board[1][1] == 'X' && board[2][2] == 'X')
        || (board[0][0] == 'x' && board[1][1] == 'x' && board[2][2] == 'x')
        || (board[0][0] == 'O' && board[1][1] == 'O' && board[2][2] == 'O')
        || (board[0][0] == 'o' && board[1][1] == 'o' && board[2][2] == 'o'))
    {
        cout << board[0][0] << " wins!";

        if (board[0][0] == 'X' || board[0][0] == 'x')
        {
            X++;
        }

        else if (board[0][0] == 'O' || board[0][0] == 'o')
        {
            O++;
        }

        GameEnd(board);
    }
    //Check if there is a win in right to left diagonal
    else if ((board[0][2] == 'X' && board[1][1] == 'X' && board[2][0] == 'X')
        || (board[0][2] == 'x' && board[1][1] == 'x' && board[2][0] == 'x')
        || (board[0][2] == 'O' && board[1][1] == 'O' && board[2][0] == 'O')
        || (board[0][2] == 'o' && board[1][1] == 'o' && board[2][0] == 'o'))
    {
        cout << board[0][2] << " wins!";
        
        if (board[0][2] == 'X' || board[0][2] == 'x')
        {
            X++;
        }

        else if (board[0][2] == 'O' || board[0][2] == 'o')
        {
            O++;
        }
        GameEnd(board);
    }
    else if (board[0][0] != ' ' && board[0][1] != ' ' && board[0][2] != ' ' && board[1][0] != ' ' && board[1][1] != ' '
        && board[1][2] != ' ' && board[2][0] != ' ' && board[2][1] != ' ' && board[2][2] != ' ')
    {
        cout << "Draw!";
    }
}

//Demonstration of the TurnTracker class, for testing purposes.
//(Remove this when implementing the full game of Tic Tac Toe.)
int main()
{
    //welcome message
    cout << "Welcome to Tic-Tac-Toe" << endl;
    //starting board just for display purposes and to help make displayBoard (can be taken out later)
    cout << "_|_|_\n" << "_|_|_\n" << " | | " << endl;
    //attempt at making initial board that can change
    char board[3][3] = { {' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '} };

    //for updating the board later ex ask player for which column and which row
    int row;
    int col;

    //displaying initial board (this should be put in loop later so that board can update
    displayBoard(board);

    TurnTracker tt1;
    cout << tt1.getTurn() << endl; //should output X
    tt1.switchTurn();
    cout << tt1.getTurn() << endl; //should output O

    TurnTracker tt2('O');
    cout << tt2.getTurn() << endl; //should output O
    tt2.setTurn('O');
    cout << tt2.getTurn() << endl; //should output O
    tt2.setTurn('X');
    cout << tt2.getTurn() << endl; //should output X

    TurnTracker tt3('T'); //should output an error message!
    cout << tt3.getTurn() << endl; //should output X
    tt3.setTurn('T'); //should output an error message!
    cout << tt3.getTurn() << endl; //should output X
    tt3.switchTurn();
    cout << tt3.getTurn() << endl; //should output O
    
}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

// Eddie: Score Count of Wins, Restart Game, (Optional: Exit Game)