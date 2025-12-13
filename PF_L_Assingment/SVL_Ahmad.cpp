#include <iostream>
using namespace std;

// Function to print the chessboard with queen moves
void printChessboard(int x, int y) {
    char board[10][10];

    // Initialize the board with '.'
    for (int i = 0; i <= 9; i++) {
        for (int j = 0; j <= 9; j++) {
            board[i][j] = '.';	// 0 1
        }
    }

    // Place the Queen's starting position with 's'
    board[x][y] = 's';

    // Mark horizontal and vertical moves with 'Q'
    for (int i = 0; i <= 9; i++) {
        if (i != y) board[x][i] = 'Q';  // Horizontal
        if (i != x) board[i][y] = 'Q';  // Vertical
    }

    // Mark diagonal moves with 'Q'
    for (int i = 1; i <= 9; i++) {
        // Top-right
        if (x + i < 10 && y + i < 10) board[x + i][y + i] = 'Q';
        // Bottom-right
        if (x + i < 10 && y - i >= 0) board[x + i][y - i] = 'Q';
        // Top-left
        if (x - i >= 0 && y + i < 10) board[x - i][y + i] = 'Q';
        // Bottom-left
        if (x - i >= 0 && y - i >= 0) board[x - i][y - i] = 'Q';
    }

    // Print the board
    cout << "\nChessboard with Queen's moves:\n";
    for (int i = 0; i <= 9; i++) {
        for (int j = 0; j <= 9; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int x, y;

    while (true) {
    //	Geting input from user.
        cout << "Entering position of Queen:\n";
        cout << "Enter row (0 to exit): ";
        
        cin >> x;
        
        if(x == 0)
			break;
		
        cout << "Enter column (0 to exit): ";
        cin >> y;
        if(y == 0)
			break;
			
		
        x = x -1;
		y = y - 1;		

        // Check valid input range
        if (x < 0 || x >= 10 || y < 0 || y >= 10) {
            cout << "Invalid position! Please enter values between 1 and 10.\n";
            continue;
        }

        // Display the chessboard with queen moves
        printChessboard(x, y);
    }

    
}