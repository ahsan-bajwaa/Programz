#include <iostream>
#include <string>
using namespace std;

void display_board(string chess_table[8][8]) {
    // Displaying chessboard.
    int numbering_numbers = 8;
    char numbering_alphabets = 'A';
    cout << endl << "__________________________Chessboard_________________________" << endl << endl;
    cout << " |    ";
    for(char c = 'A'; c <= 'H'; c++){
        cout << c << "     ";
    }
    cout << endl << "_____________________________________________________" << endl;
    for(int i = 0; i < 8; i++){
        cout << numbering_numbers << "| ";
        for(int j = 0; j < 8; j++) {
            cout << chess_table[i][j] << "  ";
            if(j == 7){
                cout << "|" << numbering_numbers--;
            }
        }
        if(i < 7)
            cout << endl << endl;
        else
            cout << endl;
    }
    cout << endl << "------------------------------------------------------" << endl;    
    cout << " |    ";
    for(char c = 'A'; c <= 'H'; c++){
        cout << c << "     ";
    }
    cout << endl << "_______________________________________________________" << endl;    
}

int main() {
    string chess_table[8][8];
    // Placing a chess table with dots.
    for(int i = 0; i < 8; i++) {
        for(int j = 0; j < 8; j++) {
            chess_table[i][j] = "  . ";
        }
    }
    string w_knight = "wH";
    int w_knight_positions[2][2] = { {7, 1}, {7, 6} };
    string b_knight = "bH";
    int b_knight_positions[2][2] = { {0, 1}, {0, 6} };                           

    // Placing knights on the chessboard.
    for (int i = 0; i < 2; i++) {
        chess_table[w_knight_positions[i][0]][w_knight_positions[i][1]] = " wH" + to_string(i + 1);
        chess_table[b_knight_positions[i][0]][b_knight_positions[i][1]] = " bH" + to_string(i + 1);        
    }

    while(true) {
        // Movement of pawn
        string piece_name;
        cout << "Enter pawn to move (i.e wP1, wR1,..): ";
        cin >> piece_name;

        bool w_knight_call = false, b_knight_call = false;

        // Determine which pawn to move
        int piece_index = -1;

        if (piece_name[1] == 'H') {
            for (int i = 1; i <= 2; i++) {
                // White Knight
                if(piece_name == w_knight + to_string(i)) {
                    piece_index = i - 1;
                    w_knight_call = true;
                }
                // Black Knight
                if(piece_name == b_knight + to_string(i)) {
                    piece_index = i - 1;
                    b_knight_call = true;
                }
            }
        }

        int knight_row, knight_col;

        if (piece_index != -1) {
            // Display possible moves on the chessboard
            cout << "Possible moves for " << piece_name << ":" << endl;
            int knight_moves[8][2] = { {-2, 1}, {-1, 2}, {1, 2}, {2, 1}, {-2, -1}, {-1, -2}, {1, -2}, {2, -1} };

            if(b_knight_call) {
                knight_row = b_knight_positions[piece_index][0];
                knight_col = b_knight_positions[piece_index][1];

                // Mark possible moves for black knight
                for(int i = 0; i < 8; i++) {
                    int new_row = knight_row + knight_moves[i][0];
                    int new_col = knight_col + knight_moves[i][1];
                    if (new_row >= 0 && new_row < 8 && new_col >= 0 && new_col < 8) {
                        chess_table[new_row][new_col] = "*" + piece_name;
                    }
                }
            }

            if(w_knight_call) {
                knight_row = w_knight_positions[piece_index][0];
                knight_col = w_knight_positions[piece_index][1];

                // Mark possible moves for white knight
                for(int i = 0; i < 8; i++) {
                    int new_row = knight_row + knight_moves[i][0];
                    int new_col = knight_col + knight_moves[i][1];
                    if (new_row >= 0 && new_row < 8 && new_col >= 0 && new_col < 8) {
                        chess_table[new_row][new_col] = "*" + piece_name;
                    }
                }
            }

            display_board(chess_table);

            // Entering a move.
            string move_input;
            cout << "Enter your move (i.e A3,B2,C3,...): ";
            cin >> move_input;

            // Convert input to row to integers.
            int move_row = 8 - (move_input[1] - '0');
            int move_col = move_input[0] - 'A';

            bool valid_move = false;

            // For Knight move check
            if (w_knight_call || b_knight_call) {
                if (abs(move_row - knight_row) == 2 && abs(move_col - knight_col) == 1 ||
                    abs(move_row - knight_row) == 1 && abs(move_col - knight_col) == 2) {
                    valid_move = true;
                }
            }

            // Checking for a valid move.
            if (valid_move) {
                // For Knight movement
                if (b_knight_call) {
                    chess_table[b_knight_positions[piece_index][0]][b_knight_positions[piece_index][1]] = "  . "; // Clear the current position
                    b_knight_positions[piece_index][0] = move_row; // Update the knight's position
                    b_knight_positions[piece_index][1] = move_col; // Update the knight's column
                    chess_table[move_row][move_col] = " " + piece_name; // Place the knight in the new position
                }

                if (w_knight_call) {
                    chess_table[w_knight_positions[piece_index][0]][w_knight_positions[piece_index][1]] = "  . "; // Clear the current position
                    w_knight_positions[piece_index][0] = move_row; // Update the knight's position
                    w_knight_positions[piece_index][1] = move_col; // Update the knight's column
                    chess_table[move_row][move_col] = " " + piece_name; // Place the knight in the new position
                }
            } else {
                cout << "You entered a wrong move!" << endl;
            }
        } else {
            cout << "You selected a wrong piece!" << endl;
        }

        display_board(chess_table);
    }
}
