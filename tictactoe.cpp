#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

char board[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};

bool isBoardFull() {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (board[i][j] == ' ')
                return false;
        }
    }
    return true;
}

void displayBoard() {
    cout << "-------------" << endl;
    for (int i = 0; i < 3; ++i) {
        cout << "| ";
        for (int j = 0; j < 3; ++j) {
            cout << board[i][j] << " | ";
        }
        cout << endl;
        cout << "-------------" << endl;
    }
}

bool checkWin(char symbol) {
    for (int i = 0; i < 3; ++i) {
        if ((board[i][0] == symbol && board[i][1] == symbol && board[i][2] == symbol) ||
            (board[0][i] == symbol && board[1][i] == symbol && board[2][i] == symbol))
            return true;
    }

    if ((board[0][0] == symbol && board[1][1] == symbol && board[2][2] == symbol) ||
        (board[0][2] == symbol && board[1][1] == symbol && board[2][0] == symbol))
        return true;

    return false;
}

void playerMove(char symbol) {
    int row, col;
    while (true) {
        if (symbol == 'X') {
            cout << "Player '" << symbol << "', enter your move (row and column): ";
            cin >> row >> col;
        } else {
            row = rand() % 3;
            col = rand() % 3;
        }

        if (row < 0 || row > 2 || col < 0 || col > 2 || board[row][col] != ' ') {
            cout << "Invalid move. Try again." << endl;
        } else {
            board[row][col] = symbol;
            break;
        }
    }
}

int main() {
    srand(static_cast<unsigned int>(time(0)));
    cout << "Welcome to Tic-Tac-Toe against AI!\n";
    char currentPlayer = 'X';

    while (true) {
        displayBoard();
        playerMove(currentPlayer);

        if (checkWin(currentPlayer)) {
            displayBoard();
            if (currentPlayer == 'X') {
                cout << "Player 'X' wins! Congratulations!" << endl;
            } else {
                cout << "AI wins! Better luck next time!" << endl;
            }
            break;
        }

        if (isBoardFull()) {
            displayBoard();
            cout << "It's a draw! Game over." << endl;
            break;
        }

        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X'; 
    }

    return 0;
}

