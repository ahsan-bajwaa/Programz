#include <iostream>
using namespace std;

// Initialize the chessboard
void create_table(char chess[10][10]) {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            chess[i][j] = '.';
        }
    }
}

// Mark all valid moves of the Queen
void queen_moves(char chess[10][10], int row, int column) {
    for (int i = 0; i < 10; i++) {
        // Mark horizontal and vertical moves
        chess[row - 1][i] = 'Q';
        chess[i][column - 1] = 'Q';

        // Mark diagonal moves
        if (row - 1 - i >= 0 && column - 1 - i >= 0) // Top-left
            chess[row - 1 - i][column - 1 - i] = 'Q';
        if (row - 1 - i >= 0 && column - 1 + i < 10) // Top-right
            chess[row - 1 - i][column - 1 + i] = 'Q';
        if (row - 1 + i < 10 && column - 1 - i >= 0) // Bottom-left
            chess[row - 1 + i][column - 1 - i] = 'Q';
        if (row - 1 + i < 10 && column - 1 + i < 10) // Bottom-right
            chess[row - 1 + i][column - 1 + i] = 'Q';
    }
}

// Display the chessboard
void display_board(char chess[10][10]) {
    cout << "\n_Chessboard_\n";
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            cout << chess[i][j] << "  ";
        }
        cout << endl;
    }
    cout << "----------------------------\n";
}

// Check if the Queen's move is valid
bool is_valid_move(int row, int column, int new_row, int new_column) {
    return (new_row == row || new_column == column || 
            abs(new_row - row) == abs(new_column - column));
}

int main() {
    char chess[10][10];
    int row = 5, column = 8; // Default Queen position

    // Initialize the chessboard
    create_table(chess);

    // Mark valid moves and set the initial position
    queen_moves(chess, row, column);
    chess[row - 1][column - 1] = 'S';

    // Display the initial chessboard
    display_board(chess);

    while (true) {
        // Get the new position
        cout << "Enter the new position of the Queen (row and column, 0 to exit): ";
        int new_row, new_column;
        cin >> new_row;

        if (new_row == 0) break; // Exit condition
        cin >> new_column;
        if (new_column == 0) break;

        // Validate the move
        if (new_row < 1 || new_row > 10 || new_column < 1 || new_column > 10) {
            cout << "Position out of bounds. Try again.\n";
            continue;
        }

        if (is_valid_move(row, column, new_row, new_column)) {
            row = new_row;
            column = new_column;

            // Reset and update the chessboard
            create_table(chess);
            queen_moves(chess, row, column);
            chess[row - 1][column - 1] = 'S';
            display_board(chess);
        } else {
            cout << "Invalid move. Queen can't move there. Try again.\n";
        }
    }

    cout << "Thanks for playing the game!";
    return 0;
}