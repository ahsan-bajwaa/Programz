#include <iostream>
#include <string>
using namespace std;

	//	 Placing a chess table with dots. 8 * 8.
void creating_chess_table(string chess_table[8][8]) {
    for(int i = 0; i < 8; i++){
    	for(int j = 0; j < 8; j++){
    		 chess_table[i][j] = "  . ";
		}
	}
}

	// Placing white pawns on the chessboard
void placing_pawn(string chess_table[8][8], int w_pawn_positions[8][2], int b_pawn_positions[8][2]) {
    for (int i = 0; i < 8; i++) {
        chess_table[w_pawn_positions[i][0]][w_pawn_positions[i][1]] = " wP" + to_string(i + 1);
        chess_table[b_pawn_positions[i][0]][b_pawn_positions[i][1]] = " bP" + to_string(i + 1);
    }
}

void placing_rook(string chess_table[8][8], int w_rook_positions[2][2], int b_rook_positions[2][2]){
	for(int i = 0; i < 2; i++){
    	chess_table[w_rook_positions[i][0]][w_rook_positions[i][1]] = " wR" + to_string(i + 1);
    	chess_table[b_rook_positions[i][0]][b_rook_positions[i][1]] = " bR" + to_string(i + 1);
	}
}

void determining_selected_pawn(int &piece_index, string piece_name, bool &w_pawn_call, bool &b_pawn_call, string w_pawn, string b_pawn){
	if(piece_name[1] == 'P'){
    	for (int i = 1; i <= 8; i++) {
    	//	White pawns.
    		if(piece_name == w_pawn + to_string(i)) {
    			piece_index = i - 1;
    			w_pawn_call = true;
		}
    	
    	// Black pawns.
    		if(piece_name == b_pawn + to_string(i)) {
    			piece_index = i - 1;
    			b_pawn_call = true;
				}
			}
		}
}

void determinig_selected_rook(int &piece_index,string piece_name, bool &w_rook_call, bool &b_rook_call, string w_rook, string b_rook){
	if(piece_name[1] == 'R'){
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
	}
}

int main() {
    string chess_table[8][8]; 
	//	Creating a Chess table.
	creating_chess_table(chess_table);
	
    string b_rook = "bR";
    string w_rook = "wR";
	string w_pawn = "wP";
    string b_pawn = "bP";
    int w_rook_positions[2][2] = { {7, 0}, {7, 7} }; // A1
    int b_rook_positions[2][2] = { {0, 0}, {0, 7} }; // A8
    
    int w_pawn_positions[8][2] = { {6, 0}, {6, 1}, {6, 2}, {6, 3}, {6, 4}, {6, 5}, {6, 6}, {6, 7} }; // A2-H2
    int b_pawn_positions[8][2] = {{1, 0}, {1, 1}, {1, 2}, {1, 3}, {1, 4}, {1, 5}, {1, 6}, {1, 7}};  // A7-H7

	placing_pawn(chess_table, w_pawn_positions, b_pawn_positions);
    
    // Placing rooks on the chessboard
	placing_rook(chess_table, w_rook_positions, b_rook_positions);    
    
	
    while(true){

// Movement of pawn
    string piece_name;
    cout << "Enter pawn to move (i.e wP1, wR1,..): ";
    cin >> piece_name;
    
    bool w_pawn_call = false, b_pawn_call = false, w_rook_call = false, b_rook_call = false;

// Determine which pawn to move
    int piece_index = -1;
    
    determining_selected_pawn(piece_index, piece_name, w_pawn_call, b_pawn_call, w_pawn, b_pawn);
	
	determinig_selected_rook(piece_index, piece_name, w_rook_call, b_rook_call, w_rook, b_rook);
	
    if (piece_index != -1) {
// Display possible moves on the chessboard
        cout << "Possible moves for " << piece_name << ":" << endl;

// 	Checking for white pawn call.
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
    
//	 Checking for Black pawn call.   
	if(b_pawn_call)	{
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
	int rook_row, rook_col;
	// Setting rook's position for white......
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
	char numbering_alphabets = 'A';
    cout << endl << "__________________________Chessboard_________________________" << endl << endl;
	cout << " |    ";
    for(char c = 'A'; c <= 'H'; c++){
        cout << c << "     ";
    }
	cout << endl << "_____________________________________________________" << endl;
    for(int i = 0; i < 8; i++){
    	cout << numbering_numbers << "| ";
        for(int j = 0; j < 8; j++){
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

// Entering a move.
        string move_input;
        cout << "Enter your move (i.e A3,B2,C3,...): ";
        cin >> move_input;

		// Convert input to row to integers.
        int move_row = 8 - (move_input[1] - '0');
        // 	Converting input colomn into intergers.
        int move_col = move_input[0] - 'A';

// Checking move.
        bool valid_move = false;
        
        if(w_pawn_call){
        	if (move_row == w_pawn_positions[piece_index][0] - 1 && move_col == w_pawn_positions[piece_index][1]) {
// Move one step forward
            valid_move = true;
        	}
			else if (move_row == w_pawn_positions[piece_index][0] - 2 && move_col == w_pawn_positions[piece_index][1] && w_pawn_positions[piece_index][0] == 6) {
// Move two steps forward
            valid_move = true;
        	}
		}
		
		if(b_pawn_call){
			if (move_row == b_pawn_positions[piece_index][0] + 1 && move_col == b_pawn_positions[piece_index][1]) {
// Move one step forward
            valid_move = true;
        	}
			else if (move_row == b_pawn_positions[piece_index][0] + 2 && move_col == b_pawn_positions[piece_index][1] && b_pawn_positions[piece_index][0] == 1) {
// Move two steps forward
            valid_move = true;
        	}
		}
		
		// Rook move check.
        if (w_rook_call || b_rook_call) {
            // Check horizontal and vertical moves for rook
            if (move_row == rook_row || move_col == rook_col) {
                valid_move = true;
            }
        }
        
//	Checking for a valid move.
        if (valid_move) {
// For White pawn.
            if(w_pawn_call){
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
//	 For Black pawn.		
			if(b_pawn_call) {
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
		}
		else {
            cout << "You entered a wrong move!" << endl;
        }
    } else {
        cout << "You selected wrong pown!" << endl;
    }

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
        for(int j = 0; j < 8; j++){
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
}
