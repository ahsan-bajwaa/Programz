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

    string w_rook = "wR";
    int w_rook_positions[2][2] = { {7, 0}, {7, 7} }; // A1

    string b_rook = "bR";
    int b_rook_positions[2][2] = { {0, 0}, {0, 7} }; // A8

    // Placing rooks on the chessboard
    for(int i = 0; i < 2; i++){
    	chess_table[w_rook_positions[i][0]][w_rook_positions[i][1]] = " wR" + to_string(i + 1);
    	chess_table[b_rook_positions[i][0]][b_rook_positions[i][1]] = " bR" + to_string(i + 1);
	}
	
	while(true){
	
    // Movement of rook
    string piece_name = "wR2";
    cout << "Enter piece to move (i.e wR1, bR1...): ";
    cin >> piece_name;

    bool w_rook_call = false, b_rook_call = false;

    // Determine which piece to move
    int piece_index = -1;
    for(int i = 1; i <= 2; i++) {
    //	For White Rook.
    	if(piece_name == w_rook + to_string(i)){
    		piece_index = i - 1;
    		w_rook_call = true;
		}
	//	For Black Rook.	
    	if(piece_name == b_rook + to_string(i)){
    		piece_index = i - 1;
    		b_rook_call = true;
		}
	}

    `

    if (piece_index != -1) {
        cout << "Possible moves for " << piece_name << ":" << endl;

		 // Setting rook's position for white......
			if (w_rook_call) {
            	rook_row = w_rook_positions[piece_index][0];
            	rook_col = w_rook_positions[piece_index][1];
        	}
		//	Setting rook's position for Black.
			if (b_rook_call) {
				//	1st Rook.
        	    rook_row = b_rook_positions[piece_index][0];
            	rook_col = b_rook_positions[piece_index][1];
        	}

    // Checking for Rook moves

		if (w_rook_call) {
    	// Horizontal moves to the left and right
			for (int col = rook_col - 1; col >= 0; --col) { // Move left
			    if (chess_table[rook_row][col] != "  . ") { // Obstruction detected
    			    break;
   				 }
   				 chess_table[rook_row][col] = "*" + piece_name; // Mark as possible move
			}

			for (int col = rook_col + 1; col < 8; ++col) { // Move right
    			if (chess_table[rook_row][col] != "  . ") { // Obstruction detected
    			    break;
   				 }
    			chess_table[rook_row][col] = "*" + piece_name; // Mark as possible move
			}
			
			// Vertical moves upward and downward
			for (int row = rook_row - 1; row >= 0; --row) { // Move up
		    	if (chess_table[row][rook_col] != "  . ") { // Obstruction detected
    		    	break;
   			 	}
   			 chess_table[row][rook_col] = "*" + piece_name; // Mark as possible move
			}

			for (int row = rook_row + 1; row < 8; ++row) { // Move down
			    if (chess_table[row][rook_col] != "  . ") { // Obstruction detected
    			    break;
   				 }
   			 	chess_table[row][rook_col] = "*" + piece_name; // Mark as possible move
			}
		}
		
		if (b_rook_call) {
			// Horizontal moves to the left and right
			for (int col = rook_col - 1; col >= 0; --col) { // Move left
			    if (chess_table[rook_row][col] != "  . ") { // Obstruction detected
    			    break;
   				 }
   				 chess_table[rook_row][col] = "*" + piece_name; // Mark as possible move
			}

			for (int col = rook_col + 1; col < 8; ++col) { // Move right
    			if (chess_table[rook_row][col] != "  . ") { // Obstruction detected
    			    break;
   				 }
    			chess_table[rook_row][col] = "*" + piece_name; // Mark as possible move
			}
			
			// Vertical moves upward and downward
			for (int row = rook_row - 1; row >= 0; --row) { // Move up
		    	if (chess_table[row][rook_col] != "  . ") { // Obstruction detected
    		    	break;
   			 	}
   			 chess_table[row][rook_col] = "*" + piece_name; // Mark as possible move
			}

			for (int row = rook_row + 1; row < 8; ++row) { // Move down
			    if (chess_table[row][rook_col] != "  . ") { // Obstruction detected
    			    break;
   				 }
   			 	chess_table[row][rook_col] = "*" + piece_name; // Mark as possible move
			}
		}

        // Displaying chessboard.
        int numbering_numbers = 8;
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
            if (i < 7) {
                cout << endl << endl;
            } else {
                cout << endl;
            }
        }

        cout << endl << "------------------------------------------------------" << endl;
        cout << " |   ";
        for (char c = 'A'; c <= 'H'; c++) {
            cout << c << "     ";
        }
        cout << endl << "_______________________________________________________" << endl;

        // Entering a move.
        string move_input = "A4";
        cout << "Enter your move (i.e A3,B2,C3,...): ";
        cin >> move_input;

        // Convert input to row to integers.
        int move_row = 8 - (move_input[1] - '0');
        // Converting input column into integers.
        int move_col = move_input[0] - 'A';

        // Checking move.
        bool valid_move = false;

        // Rook move check.
        if (w_rook_call || b_rook_call) {
            // Check horizontal and vertical moves for rook
            if (move_row == rook_row || move_col == rook_col) {
                valid_move = true;
            }
        }

        // Checking for a valid move.
        if (valid_move) {
            // For White rook.
            if (w_rook_call) {
   		//	Removing possible move for black.
        	
			// Check horizontal moves
        		for (int i = 0; i < 8; i++) {
        			if (chess_table[rook_row][i] == "*" + piece_name)
        			    chess_table[rook_row][i] = "  . ";
        			if (chess_table[i][rook_col] == "*" + piece_name)
            			chess_table[i][rook_col] = "  . ";
    			}
            	
          // Update the chessboard
                chess_table[w_rook_positions[piece_index][0]][w_rook_positions[piece_index][1]] = "  . "; // Clear the current position
                w_rook_positions[piece_index][0] = move_row; // Update the rook's position
                w_rook_positions[piece_index][1] = move_col; // Update the rook's column
                chess_table[move_row][move_col] = " " + piece_name; // Place the rook in the new position
           }
            if (b_rook_call) {
   //	Removing possible move for black.
        		// Check horizontal moves
        		cout << move_col;
        		
        		for (int i = 0; i < 8; i++) {
        if (chess_table[rook_row][i] == "*" + piece_name)
            chess_table[rook_row][i] = "  . ";
        if (chess_table[i][rook_col] == "*" + piece_name)
            chess_table[i][rook_col] = "  . ";
    }
            	
          // Update the chessboard
                chess_table[b_rook_positions[piece_index][0]][b_rook_positions[piece_index][1]] = "  . "; // Clear the current position
                b_rook_positions[piece_index][0] = move_row; // Update the rook's position
                b_rook_positions[piece_index][1] = move_col; // Update the rook's column
                chess_table[move_row][move_col] = " " + piece_name; // Place the rook in the new position
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
    cout << " |   ";
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
    return 0;

}
