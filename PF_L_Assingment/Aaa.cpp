#include <iostream>
#include <string>
using namespace std;

void display_board(string chess_table[8][8]) {
	// Displaying chessboard.
	int numbering_numbers = 8;
	char numbering_alphabets = 'A';
    cout << endl << "__________________________Chessboard_________________________" << endl << endl;
	cout << " |   ";
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
	cout << " |   ";
    for(char c = 'A'; c <= 'H'; c++){
        cout << c << "     ";
    }
    cout << endl << "_______________________________________________________" << endl;	
	
}

int main() {
    string chess_table[8][8];
	//	 Placing a chess table with dots.
    for(int i = 0; i < 8; i++) {
    	for(int j = 0; j < 8; j++) {
    		 chess_table[i][j] = "  . ";
		}
	}
	string w_knight = "wH";
    int w_knight_positions[2][2] = { {7, 1}, {7, 6} };
	
    string b_knight = "bH";
    int b_knight_positions[2][2] = { {0, 1}, {0, 6} };                           
	
	string b_queen = "b_Q";
	int b_queen_positions[2] = {0, 3};
	
    //	Placing white knight on the chessboard.
	for (int i = 0; i < 2; i++) {
        chess_table[w_knight_positions[i][0]][w_knight_positions[i][1]] = " wH" + to_string(i + 1);
        
        chess_table[b_knight_positions[i][0]][b_knight_positions[i][1]] = " bH" + to_string(i + 1);		
	}
	
	//	Placing white knight on the chessboard.
	chess_table[b_queen_positions[0]][b_queen_positions[1]] = "b_Q";
	
    while(true) {

// Movement of pawn
    string piece_name;
    cout << "Enter pawn to move (i.e wP1, wR1,..): ";
    cin >> piece_name;
    
    bool w_knight_call = false, b_knight_call = false, b_queen_call = false;

// Determine which pawn to move
    int piece_index = -1;
    
	if (piece_name[1] == 'H') {
		for (int i = 1; i <= 2; i++) {
    	//	White Pawn.
    		if(piece_name == w_knight + to_string(i)) {
    			piece_index = i - 1;
    			w_knight_call = true;
			}
    	
    	// Black pawns.
    		if(piece_name == b_knight + to_string(i)) {
    			piece_index = i - 1;
    			b_knight_call = true;
			}
		}
	}
	
	if(piece_name == b_queen) {
		b_queen_call = true;
		piece_index = 0;
	}
	
	int knight_row, knight_col;
	
    if (piece_index != -1) {
		
		// Display possible moves on the chessboard
        cout << "Possible moves for " << piece_name << ":" << endl;
		
		int knight_moves[8][2] = { {-2, 1}, {-1, 2}, {1, 2}, {2, 1}, {-2, -1}, {-1, -2}, {1, -2}, {2, -1} };
		
		if (b_knight_call) {
		//	Black Movement of knight.
        knight_row = b_knight_positions[piece_index][0];
        knight_col = b_knight_positions[piece_index][1];
        
		for(int i = 0; i < 8; i++) {
                    int new_row = knight_row + knight_moves[i][0];
                    int new_col = knight_col + knight_moves[i][1];
                    if (new_row >= 0 && new_row < 8 && new_col >= 0 && new_col < 8) {
                    	if(chess_table[new_row][new_col] != "  . ") {
                    		continue;
						}
                        chess_table[new_row][new_col] = "*" + piece_name;
                    }
                }
		}
		int queen_row, queen_col;
        
     // Queen Moves..
     	if (b_queen_call) {
     		queen_row = b_queen_positions[0];
       	 	queen_col = b_queen_positions[1];
       	 	//	Marks..
       	 	
       	 	// Horizontal moves to the left and right
			for (int i = queen_col - 1; i >= 0; i--) { // Move left
			    if (chess_table[queen_row][i] != "  . ") { // Obstruction detected
    			    break;
   				 }
   				 chess_table[queen_row][i] = "*" + piece_name; // Mark as possible move
			}

			for (int i = queen_col + 1; i < 8; i++) { // Move right
    			if (chess_table[queen_row][i] != "  . ") { // Obstruction detected
    			    break;
   				 }
    			chess_table[queen_row][i] = "*" + piece_name; // Mark as possible move
			}
			
			// Vertical moves upward and downward
			for (int i = queen_row - 1; i >= 0; i--) { // Move up
		    	if (chess_table[i][queen_col] != "  . ") { // Obstruction detected
    		    	break;
   			 	}
   			 chess_table[i][queen_col] = "*" + piece_name; // Mark as possible move
			}

			for (int i = queen_row + 1; i < 8; i++) {  // Move down.
			    if (chess_table[i][queen_col] != "  . ") { // Obstruction detected.
    			    break;
   				 }
   			 	chess_table[i][queen_col] = "*" + piece_name; // Mark as possible move
			}
			
			
			//	For cross movement of queen...
			// for bottom right.
				for (int i = 1; i < 7; i++) {
				    if (queen_row + i > 7 || queen_row +i > 7) break; 
				    if (chess_table[queen_row + i][queen_row + i] != "  . ") break; 
				    chess_table[queen_row + i][queen_row + i] = "*" + piece_name;
				}
				//	for bottom left.
				for (int i = 1; i < 7; i++) {
				    if (queen_row + i > 7 || queen_row -i < 0) break;
				    if (chess_table[queen_row + i][queen_row -i] != "  . ") break;
				    chess_table[queen_row + i][queen_row - i] = "*" + piece_name;
				}
				//	For upper right.
				for (int i = 1; i < 7; i++) {
				    if (queen_row -i < 0 || queen_row - i < 0) break;
				    if (chess_table[queen_row -i][queen_row - i] != "  . ") break;
				    chess_table[queen_row -i][queen_row -i] = "*" + piece_name;
				}
				//	For upper left.
				for (int i = 1; i < 7; i++) {
				    if (queen_row -i < 0 || queen_row + i > 7) break;
				    if (chess_table[queen_row - i][queen_row + i] != "  . ") break;
				    chess_table[queen_row - i][queen_row +i] = "*" + piece_name;
				}
	}

	display_board(chess_table);

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
        
        if (b_queen_call) {
        	
		// Check for row and column move.
	        if(move_row == queen_row || move_col == queen_col){
	            valid_move = true;
	        }
	        
		// Check for diagonal move.
	        else if(move_row - queen_row == move_col - queen_col || (move_row - queen_row == -(move_col - queen_col))) {
	            valid_move = true;
	    	}
	    
	    }
		
     	  
        //	For Knight move check.
    	if (w_knight_call || b_knight_call) {
    		int new_row = abs(move_row - knight_row);
			int new_col = abs(move_col - knight_col);
    		
			if (abs(new_row) == 2 && abs(new_col) == 1 ||
			  	abs(new_row) == 1 && abs(new_col) == 2) {
					
					valid_move = true;
			}
		}
		int new_row, new_col;
		
//	Checking for a valid move.
        if (valid_move) {
        		
        	
        	if (b_queen_call) {
		        new_row = queen_row + b_queen_positions[0];
		       	new_col = queen_col + b_queen_positions[1];
		       	
				// Removing possible marks.
		       	
				for (int i = 0; i < 8; i++){
					// 	For Parallel and Vertical moves.
	        		if (chess_table[queen_row][i] == "*" + piece_name) {
		            	chess_table[queen_row][i] = "  . ";
					}
					if (chess_table[i][queen_col] == "*" + piece_name) {
		            	chess_table[i][queen_col] = "  . ";
					}
					
					// For Digonals Moves.
	        		if (chess_table[queen_row -i][queen_col -i] == "*" + piece_name){		// Top-left
			            chess_table[queen_row - i][queen_col - i] = "  . ";
					}
					if (chess_table[queen_row -i][queen_col +i] == "*" + piece_name){		// Top-right
			            chess_table[queen_row - i][queen_col +i] = "  . ";
					} 
					if (chess_table[queen_row +i][queen_col -i] == "*" + piece_name){		// Bottom-left
			            chess_table[queen_row +i][queen_col - i] = "  . ";
					} 
					if (chess_table[queen_row +i][queen_col +i] == "*" + piece_name){		// Top-left
			            chess_table[queen_row +i][queen_col +i] = "  . ";
					}
				}
		       	
		       	
		       	
        		// Update the chessboard
                chess_table[b_queen_positions[0]][b_queen_positions[1]] = "  . "; // Clear the current position
                b_queen_positions[0] = move_row; // Update the rook's position
                b_queen_positions[1] = move_col; // Update the rook's column
                chess_table[move_row][move_col] = " " + piece_name; // Place the rook in the new position
			}
//        	
			// 	For Knight.
        	if (b_knight_call) {
        		for(int i = 0; i < 8; i++) {
		        	new_row = knight_row + knight_moves[i][0];
		        	new_col = knight_col + knight_moves[i][1];
		        	//	if (new_row > 0 && new_row < 8 && new_col > 0 && new_col < 8) {
		        		if (chess_table[new_row][new_col] == "*" + piece_name) {
		        			chess_table[new_row][new_col] = "  . ";
						}
				}
			//}
				// Update the chessboard
                chess_table[b_knight_positions[piece_index][0]][b_knight_positions[piece_index][1]] = "  . "; // Clear the current position
                b_knight_positions[piece_index][0] = move_row; // Update the rook's position
                b_knight_positions[piece_index][1] = move_col; // Update the rook's column
                chess_table[move_row][move_col] = " " + piece_name; // Place the rook in the new position
			}

			
		}
		else {
            cout << "You entered a wrong move!" << endl;
        }
    } else {
        cout << "You selected wrong pown!" << endl;
    }

	display_board(chess_table);
	}
}
