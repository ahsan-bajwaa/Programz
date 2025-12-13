#include <iostream>
#include <string>
using namespace std;

int main() {
	int numbering_numbers = 8;
    string chess_table[8][8] = {  {"  . ","  . ","  . ","  . ","  . ","  . ","  . ","  . ",},
                                  {"  . ","  . ","  . ","  . ","  . ","  . ","  . ","  . ",},
                                  {"  . ","  . ","  . ","  . ","  . ","  . ","  . ","  . ",},
                                  {"  . ","  . ","  . ","  . ","  . ","  . ","  . ","  . ",},
                                  {"  . ","  . ","  . ","  . ","  . ","  . ","  . ","  . ",},
                                  {"  . ","  . ","  . ","  . ","  . ","  . ","  . ","  . ",},
                                  {"  . ","  . ","  . ","  . ","  . ","  . ","  . ","  . ",},
                                  {"  . ","  . ","  . ","  . ","  . ","  . ","  . ","  . ",},
                                };

    string w_pawn = "wP";
    int w_pawn_positions[8][2] = { {6, 0}, {6, 1}, {6, 2}, {6, 3}, {6, 4}, {6, 5}, {6, 6}, {6, 7} }; // A2-H2
    
    string b_pawn = "bP";
    int b_pawn_positions[8][2] = {{1, 0}, {1, 1}, {1, 2}, {1, 3}, {1, 4}, {1, 5}, {1, 6}, {1, 7}};  // A7-H7

    string w_rook = "wR";
    int w_rook_positions[1][2] = { {7, 0} }; // A1

    string b_rook = "bR";
    int b_rook_positions[1][2] = { {0, 0} }; // A8

    // Placing white pawns and rooks on the chessboard
    for (int i = 0; i < 8; i++) {
        chess_table[w_pawn_positions[i][0]][w_pawn_positions[i][1]] = " wP" + to_string(i + 1);
        chess_table[b_pawn_positions[i][0]][b_pawn_positions[i][1]] = " bP" + to_string(i + 1);
    }
    chess_table[w_rook_positions[0][0]][w_rook_positions[0][1]] = " wR1";
    chess_table[b_rook_positions[0][0]][b_rook_positions[0][1]] = " bR1";

    // Movement of pawn or rook
    string piece_name;
    cout << "Enter piece to move (i.e wP1, bP1, wR1, bR1): ";
    cin >> piece_name;

    bool w_pawn_call = false, b_pawn_call = false, w_rook_call = false, b_rook_call = false;

    // Determine which piece to move
    int piece_index = -1;
    for (int i = 1; i <= 8; i++) {
        // White pawns.
        if (piece_name == w_pawn + to_string(i)) {
            piece_index = i - 1;
            w_pawn_call = true;
        }
        // Black pawns.
        if (piece_name == b_pawn + to_string(i)) {
            piece_index = i - 1;
            b_pawn_call = true;
        }
        // White rook.
        if (piece_name == "wR1") {
            piece_index = 0;
            w_rook_call = true;
        }
        // Black rook.
        if (piece_name == "bR1") {
            piece_index = 0;
            b_rook_call = true;
        }
    }
    int rook_row, rook_col;

    if (piece_index != -1) {
        cout << "Possible moves for " << piece_name << ":" << endl;
        
         // Checking for Rook moves
    if (w_rook_call) {
        rook_row = w_rook_positions[piece_index][0]; // Initialize rook_row
        rook_col = w_rook_positions[piece_index][1]; // Initialize rook_col
    }
        
     if (b_rook_call) {
        rook_row = b_rook_positions[piece_index][0]; // Initialize rook_row
        rook_col = b_rook_positions[piece_index][1]; // Initialize rook_col
	}

        // Checking for white pawn .
        if (w_pawn_call) {
            // Move one step forward for 'White' pawn.
            if (w_pawn_positions[piece_index][0] > 0) {
                int one_step_row = w_pawn_positions[piece_index][0] - 1;
                int one_step_col = w_pawn_positions[piece_index][1];
                chess_table[one_step_row][one_step_col] = "*" + w_pawn + to_string(piece_index + 1);
            }

            // Check if 'White' pawn can move two steps forward
            if (w_pawn_positions[piece_index][0] == 6) {
                int two_steps_row = w_pawn_positions[piece_index][0] - 2;
                int two_steps_col = w_pawn_positions[piece_index][1];
                chess_table[two_steps_row][two_steps_col] = "*" + w_pawn + to_string(piece_index + 1);
            }
        }

        // Checking for Black pawn call.
        if (b_pawn_call) {
            // Move one step forward for 'Black' pawn.
            if (b_pawn_positions[piece_index][0] < 7) {
                int one_step_row = b_pawn_positions[piece_index][0] + 1;
                int one_step_col = b_pawn_positions[piece_index][1];
                chess_table[one_step_row][one_step_col] = "*" + b_pawn + to_string(piece_index + 1);
            }

            // Check if 'Black' pawn can move two steps forward
            if (b_pawn_positions[piece_index][0] == 1) {
                int two_steps_row = b_pawn_positions[piece_index][0] + 2;
                int two_steps_col = b_pawn_positions[piece_index][1];
                chess_table[two_steps_row][two_steps_col] = "*" + b_pawn + to_string(piece_index + 1);
            }
        }

        // Checking for Rook moves
        if (w_rook_call) {
            int rook_row = w_rook_positions[piece_index][0];
            int rook_col = w_rook_positions[piece_index][1];

            // Check horizontal moves
            for (int col = 0; col < 8; col++) {
                if (col != rook_col) {
                    if (chess_table[rook_row][col] != "  . ") {
                        break; // Stop if there's a piece in the way
                    }
                    chess_table[rook_row][col] = "*" + w_rook + to_string(piece_index + 1);
                }
            }

            // Check vertical moves
            for (int row = 0; row < 8; row++) {
                if (row != rook_row) {
                    if (chess_table[row][rook_col] != "  . ") {
                        break; // Stop if there's a piece in the way
                    }
                    chess_table[row][rook_col] = "*" + w_rook + to_string(piece_index + 1);
                }
            }
        }

        if (b_rook_call) {
            int rook_row = b_rook_positions[piece_index][0];
            int rook_col = b_rook_positions[piece_index][1];

            // Check horizontal moves
            for (int col = 0; col < 8; col++) {
                if (col != rook_col) {
                    if (chess_table[rook_row][col] != "  . ") {
                        break; // Stop if there's a piece in the way
                    }
                    chess_table[rook_row][col] = "*" + b_rook + to_string(piece_index + 1);
                }
            }

            // Check vertical moves
            for (int row = 0; row < 8; row++) {
                if (row != rook_row) {
                    if (chess_table[row][rook_col] != "  . ") {
                        break; // Stop if there's a piece in the way
                    }
                    chess_table[row][rook_col] = "*" + b_rook + to_string(piece_index + 1);
                }
            }
        }

        // Displaying chessboard.
        int numbering_numbers = 8;
        char numbering_alphabets = 'A';
        cout << endl << "__________________________Chessboard_________________________" << endl << endl;
        cout << " |    ";
        for (char c = 'A'; c <= 'H'; c++) {
            cout << c << "     ";
        }
        cout << endl << "_____________________________________________________" << endl;
        for (int i = 0; i < 8; i++) {
            cout << numbering_numbers << "| ";
            for (int j = 0; j < 8; j++) {
                cout << chess_table[i][j] << "  ";
                if (j == 7) {
                    cout << "|" << numbering_numbers--;
                }
            }
            if (i < 7)
                cout << endl << endl;
            else
                cout << endl;
        }
        cout << endl << "------------------------------------------------------" << endl;
        cout << " |    ";
        for (char c = 'A'; c <= 'H'; c++) {
            cout << c << "     ";
        }
        cout << endl << "_______________________________________________________" << endl;

        // Entering a move.
        string move_input;
        cout << "Enter your move (i.e A3,B2,C3,...): ";
        cin >> move_input;

        // Convert input to row to integers.
        int move_row = 8 - (move_input[1] - '0');
        // 	Converting input column into integers.
        int move_col = move_input[0] - 'A';

        // Checking move.
        bool valid_move = false;

        if (w_pawn_call) {
            if (move_row == w_pawn_positions[piece_index][0] - 1 && move_col == w_pawn_positions[piece_index][1]) {
                // Move one step forward
                valid_move = true;
            }
            else if (move_row == w_pawn_positions[piece_index][0] - 2 && move_col == w_pawn_positions[piece_index][1] && w_pawn_positions[piece_index][0] == 6) {
                // Move two steps forward
                valid_move = true;
            }
        }

        if (b_pawn_call) {
            if (move_row == b_pawn_positions[piece_index][0] + 1 && move_col == b_pawn_positions[piece_index][1]) {
                // Move one step forward
                valid_move = true;
            }
            else if (move_row == b_pawn_positions[piece_index][0] + 2 && move_col == b_pawn_positions[piece_index][1] && b_pawn_positions[piece_index][0] == 1) {
                // Move two steps forward
                valid_move = true;
            }
        }

        if (w_rook_call || b_rook_call) {
            // Check horizontal and vertical moves for rook
            if (move_row == rook_row || move_col == rook_col) {
                valid_move = true;
            }
        }

        // Checking for a valid move.
        if (valid_move) {
            // For White pawn.
            if (w_pawn_call) {
                // Clear possible move markings
                if (w_pawn_positions[piece_index][0] > 0) {
                    chess_table[w_pawn_positions[piece_index][0] - 1][w_pawn_positions[piece_index][1]] = "  . "; // Clear one step move
                }
                if (w_pawn_positions[piece_index][0] == 6) {
                    chess_table[w_pawn_positions[piece_index][0] - 2][w_pawn_positions[piece_index][1]] = "  . "; // Clear two steps move
                }

                // Update the chessboard
                chess_table[w_pawn_positions[piece_index][0]][w_pawn_positions[piece_index][1]] = "  . "; // Clear the current position
                w_pawn_positions[piece_index][0] = move_row; // Update the pawn's position
                w_pawn_positions[piece_index][1] = move_col; // Update the pawn's column
                chess_table[move_row][move_col] = " wP" + to_string(piece_index + 1); // Place the pawn in the new position
            }
            // For Black pawn.
            if (b_pawn_call) {
                // Clear possible move markings
                if (b_pawn_positions[piece_index][0] < 6) {
                    chess_table[b_pawn_positions[piece_index][0] + 1][b_pawn_positions[piece_index][1]] = "  . "; // Clear one step move
                }
                if (b_pawn_positions[piece_index][0] == 1) {
                    chess_table[b_pawn_positions[piece_index][0] + 2][b_pawn_positions[piece_index][1]] = "  . "; // Clear two steps move
                }

                // Update the chessboard
                chess_table[b_pawn_positions[piece_index][0]][b_pawn_positions[piece_index][1]] = "  . "; // Clear the current position
                b_pawn_positions[piece_index][0] = move_row; // Update the pawn's position
                b_pawn_positions[piece_index][1] = move_col; // Update the pawn's column
                chess_table[move_row][move_col] = " bP" + to_string(piece_index + 1); // Place the pawn in the new position
            }
            // For White rook.
            if (w_rook_call) {
                // Update the chessboard
                chess_table[w_rook_positions[piece_index][0]][w_rook_positions[piece_index][1]] = "  . "; // Clear the current position
                w_rook_positions[piece_index][0] = move_row; // Update the rook's position
                w_rook_positions[piece_index][1] = move_col; // Update the rook's column
                chess_table[move_row][move_col] = " wR1"; // Place the rook in the new position
            }
            // For Black rook.
            if (b_rook_call) {
                // Update the chessboard
                chess_table[b_rook_positions[piece_index][0]][b_rook_positions[piece_index][1]] = "  . "; // Clear the current position
                b_rook_positions[piece_index][0] = move_row; // Update the rook's position
                b_rook_positions[piece_index][1] = move_col; // Update the rook's column
                chess_table[move_row][move_col] = " bR1"; // Place the rook in the new position
            }
        } else {
            cout << "You entered a wrong move!" << endl;
        }
    } else {
        cout << "You selected a wrong piece!" << endl;
    }

    // Displaying chessboard.
    numbering_numbers = 8;
    cout << endl << "__________________________Chessboard_________________________" << endl << endl;
    cout << " |    ";
    for (char c = 'A'; c <= 'H'; c++) {
        cout << c << "     ";
    }
    cout << endl << "_____________________________________________________" << endl;
    for (int i = 0; i < 8; i++) {
        cout << numbering_numbers << "| ";
        for (int j = 0; j < 8; j++) {
            cout << chess_table[i][j] << "  ";
            if (j == 7) {
                cout << "|" << numbering_numbers--;
            }
        }
        if (i < 7)
            cout << endl << endl;
        else
            cout << endl;
    }
    cout << endl << "------------------------------------------------------" << endl;
    cout << " |    ";
    for (char c = 'A'; c <= 'H'; c++) {
        cout << c << "     ";
    }
    cout << endl << "_______________________________________________________" << endl;
}
