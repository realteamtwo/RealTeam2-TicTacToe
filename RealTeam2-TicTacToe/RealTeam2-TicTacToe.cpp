// RealTeam2-TicTacToe.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

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

//Demonstration of the TurnTracker class, for testing purposes.
//(Remove this when implementing the full game of Tic Tac Toe.)
int main()
{
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
