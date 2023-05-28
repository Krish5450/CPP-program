#include <iostream>
#include <vector>

using namespace std;

const int BOARD_SIZE = 3;

// Function to print the Tic-Tac-Toe board
void printBoard(const vector<vector<char>>& board) {
    for (int i = 0; i < BOARD_SIZE; ++i) {
        for (int j = 0; j < BOARD_SIZE; ++j) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

// Function to check if a player has won
bool checkWin(const vector<vector<char>>& board, char player) {
    // Check rows
    for (int i = 0; i < BOARD_SIZE; ++i) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player)
            return true;
    }

    // Check columns
    for (int i = 0; i < BOARD_SIZE; ++i) {
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player)
            return true;
    }

    // Check diagonals
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player))
        return true;

    return false;
}

int main() {
    vector<vector<char>> board(BOARD_SIZE, vector<char>(BOARD_SIZE, ' '));
    int row, col;
    char currentPlayer = 'X';
    int movesLeft = BOARD_SIZE * BOARD_SIZE;

    while (movesLeft > 0) {
        // Print the board
        printBoard(board);

        // Get the current player's move
        cout << "Player " << currentPlayer << ", enter your move (row column): ";
        cin >> row >> col;

        // Validate the move
        if (row < 0 || row >= BOARD_SIZE || col < 0 || col >= BOARD_SIZE || board[row][col] != ' ') {
            cout << "Invalid move! Try again." << endl;
            continue;
        }

        // Update the board with the player's move
        board[row][col] = currentPlayer;
        --movesLeft;

        // Check if the current player wins
        if (checkWin(board, currentPlayer)) {
            cout << "Player " << currentPlayer << " wins!" << endl;
            break;
        }

        // Switch to the next player
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    // If no one wins, it's a tie
    if (movesLeft == 0) {
        cout << "It's a tie!" << endl;
    }

    // Print the final board
    printBoard(board);

    return 0;
}
