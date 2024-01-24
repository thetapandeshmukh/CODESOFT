// Build a simple console-based Tic-Tac-Toe game that
// allows two players to play against each other 
// Game Board: Create a 3x3 grid as the game board.
// Players: Assign
// "X"
// and "O" to two players.
// Display Board: Show the current state of the board.
// Player Input: Prompt the current player to enter their move.
// Update Board: Update the game board with the player
// '
// s move.
// Check for Win: Check if the current player has won.
// Check for Draw: Determine if the game is a draw.
// Switch Players: Alternate turns between
// "X"
// and "O"
// players.
// Display Result: Show the result of the game (win, draw, or ongoing).
// Play Again: Ask if the players want to play another game.

#include <iostream>
#include <array>

enum class Player { X, O, None };

std::array<std::array<Player, 3>, 3> board = {{
    {Player::None, Player::None, Player::None},
    {Player::None, Player::None, Player::None},
    {Player::None, Player::None, Player::None}
}};

void displayBoard() {
    std::cout << "Tic-Tac-Toe Game\n";
    std::cout << "---------------\n";
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (board[i][j] == Player::None) {
                std::cout << "- ";
            } else if (board[i][j] == Player::X) {
                std::cout << "X ";
            } else {
                std::cout << "O ";
            }
        }
        std::cout << std::endl;
    }
    std::cout << "---------------\n";
}

bool isBoardFull() {
    for (const auto& row : board) {
        for (const auto& cell : row) {
            if (cell == Player::None) {
                return false;
            }
        }
    }
    return true;
}

bool checkWin(Player player) {
    for (int i = 0; i < 3; ++i) {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
            (board[0][i] == player && board[1][i] == player && board[2][i] == player)) {
            return true;
        }
    }

    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player)) {
        return true;
    }

    return false;
}

bool makeMove(int row, int col, Player currentPlayer) {
    if (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == Player::None) {
        board[row][col] = currentPlayer;
        return true;
    }
    return false;
}

int main() {
    Player currentPlayer = Player::X;
    bool gameRunning = true;

    while (gameRunning) {
        displayBoard();

        int row, col;
        std::cout << "Player " << (currentPlayer == Player::X ? "X" : "O") << ", enter row and column (0-2): ";
        std::cin >> row >> col;

        if (makeMove(row, col, currentPlayer)) {
            if (checkWin(currentPlayer)) {
                displayBoard();
                std::cout << "Player " << (currentPlayer == Player::X ? "X" : "O") << " wins!\n";
                gameRunning = false;
            } else if (isBoardFull()) {
                displayBoard();
                std::cout << "It's a draw!\n";
                gameRunning = false;
            } else {
                currentPlayer = (currentPlayer == Player::X) ? Player::O : Player::X;
            }
        } else {
            std::cout << "Invalid move! Try again.\n";
        }
    }

    return 0;
}
