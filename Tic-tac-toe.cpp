#include<bits/stdc++.h>
#define mii map<int, int> 
#define vi vector<int> 
#define int long long int 
#define f first
#define s second 
#define pb push_back 
#define mp make_pair 
#define mod 100000007
using namespace std;


char board[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
bool player1Turn = true;

// Function to display the Tic Tac Toe board
void displayBoard() {
    cout << "  " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << endl;
    cout << " -----------" << endl;
    cout << "  " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << endl;
    cout << " -----------" << endl;
    cout << "  " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << endl;
}

// Function to check if there's a winner or the game is a tie
char checkWinner() {
    // Checking rows
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return board[i][0];
        }
    }
    // Checking columns
    for (int i = 0; i < 3; i++) {
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
            return board[0][i];
        }
    }
    // Checking diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return board[0][0];
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        return board[0][2];
    }
    // Checking for tie
    bool isTie = true;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] != 'X' && board[i][j] != 'O') {
                isTie = false;
                break;
            }
        }
        if (!isTie) break;
    }
    if (isTie) return 'T'; // T represents tie
    return ' ';
}

// Function to get the move from the player
int getPlayerMove() {
    int choice;
    cout << "Enter your move (1-9): ";
    cin >> choice;
    return choice;
}

// Function to get the move from the computer
int getComputerMove() {
    // Very basic AI, just picks a random available spot
    vector<int> availableMoves;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] != 'X' && board[i][j] != 'O') {
                availableMoves.push_back(i * 3 + j + 1);
            }
        }
    }
    srand(time(NULL));
    return availableMoves[rand() % availableMoves.size()];
}

int32_t main() {
    int move;
    char winner;
    while (true) {
        displayBoard();
        if (player1Turn) {
            move = getPlayerMove();
            if (board[(move - 1) / 3][(move - 1) % 3] != 'X' && board[(move - 1) / 3][(move - 1) % 3] != 'O') {
                board[(move - 1) / 3][(move - 1) % 3] = 'X';
                player1Turn = false;
            }
        } else {
            move = getComputerMove();
            cout << "Computer's move: " << move << endl;
            board[(move - 1) / 3][(move - 1) % 3] = 'O';
            player1Turn = true;
        }
        winner = checkWinner();
        if (winner != ' ') {
            displayBoard();
            if (winner == 'T') {
                cout << "It's a tie!" << endl;
            } else if (winner == 'X') {
                cout << "Congratulations! You win!" << endl;
            } else {
                cout << "Computer wins!" << endl;
            }
            break;
        }
    }
    return 0;
}
