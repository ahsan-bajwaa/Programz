#include <iostream>
#include <string>
using namespace std;

int main() {
    string chess_table[8][8];
	//	 Placing a chess table with dots.
    for(int i = 0; i < 8; i++) {
    	for(int j = 0; j < 8; j++){
    		 chess_table[i][j] = "  . ";
		}    
	}  
	
    string w_rook = "wR";
    int w_rook_positions[2][2] = { {7, 0}, {7, 7} }; // A1

    string b_rook = "bR";
    int b_rook_positions[2][2] = { {0, 0}, {0, 7} }; // A8
    
    string w_bishop = "wB";
    int w_bishop_positions[2][2] = { {7, 2}, {7, 5} };
    
    string b_bishop = "bB";
    int b_bishop_positions[2][2] = { {0, 2}, {0, 5} };

// Placing white Bishop on the chessboard
    for(int i = 0; i < 2; i++) {
    	chess_table[w_bishop_positions[i][0]][w_bishop_positions[i][1]] = " wB" + to_string(i + 1);
    	chess_table[b_bishop_positions[i][0]][b_bishop_positions[i][1]] = " bB" + to_string(i + 1);
	}
    
    // Placing rooks on the chessboard
    for(int i = 0; i < 2; i++) {
    	chess_table[w_rook_positions[i][0]][w_rook_positions[i][1]] = " wR" + to_string(i + 1);
    	chess_table[b_rook_positions[i][0]][b_rook_positions[i][1]] = " bR" + to_string(i + 1);
	}
	
    while(true) {

// Movement of pawn
    string piece_name;
    cout << "Enter pawn to move (i.e wP1, wR1,..): ";
    cin >> piece_name;
    
    bool w_bishop_call = false, b_bishop_call = false, w_rook_call = false, b_rook_call = false;

// Determine which pawn to move
    int piece_index = -1;
    
	if(piece_name[1] == 'B') {
		for(int i = 1; i <= 2; i++) {
    //	For White Bishop.
    		if(piece_name == w_bishop + to_string(i)){
    			piece_index = i - 1;
    			w_bishop_call = true;
			}
	//	For Black Bishop.	
    		if(piece_name == b_bishop + to_string(i)){
    			piece_index = i - 1;
    			b_bishop_call = true;
			}
		}
	}

	if(piece_name[1] == 'R') {
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
	
	
    if (piece_index != -1) {
// Display possible moves on the chessboard
        cout << "Possible moves for " << piece_name << ":" << endl;
	int rook_row, rook_col, bishop_row, bishop_col;
	
			

			// 	Checking for white Bishop call.
  			if (w_bishop_call) {
            	bishop_row = w_bishop_positions[piece_index][0];
            	bishop_col = w_bishop_positions[piece_index][1];
			  }
			// 	Checking for white Bishop call.
  			if (b_bishop_call) {
            	bishop_row = b_bishop_positions[piece_index][0];
            	bishop_col = b_bishop_positions[piece_index][1];
			  }			  
	
	
	// Setting rook's position for white......
		// Setting rook's position for white......
			if (w_rook_call) {
            	rook_row = w_rook_positions[piece_index][0];
            	rook_col = w_rook_positions[piece_index][1];
        	}
		//	Setting rook's position for Black.
			if (b_rook_call) {
        	    rook_row = b_rook_positions[piece_index][0];
            	rook_col = b_rook_positions[piece_index][1];
        	}
       	
    // Checking for Rook moves

		if (b_bishop_call || w_bishop_call) {
				// for bottom right.
				for (int i = 1; i < 7; i++) {
				    if (bishop_row + i > 7 || bishop_col +i > 7) break; 
				    if (chess_table[bishop_row + i][bishop_col + i] != "  . ") break; 
				    chess_table[bishop_row + i][bishop_col + i] = "*" + piece_name;
				}
				//	for bottom left.
				for (int i = 1; i < 7; i++) {
				    if (bishop_row + i > 7 || bishop_col -i < 0) break;
				    if (chess_table[bishop_row + i][bishop_col -i] != "  . ") break;
				    chess_table[bishop_row + i][bishop_col - i] = "*" + piece_name;
				}
				//	For upper right.
				for (int i = 1; i < 7; i++) {
				    if (bishop_row -i < 0 || bishop_col - i < 0) break;
				    if (chess_table[bishop_row -i][bishop_col - i] != "  . ") break;
				    chess_table[bishop_row -i][bishop_col -i] = "*" + piece_name;
				}
				//	For upper left.
				for (int i = 1; i < 7; i++) {
				    if (bishop_row -i < 0 || bishop_col + i > 7) break;
				    if (chess_table[bishop_row - i][bishop_col + i] != "  . ") break;
				    chess_table[bishop_row - i][bishop_col +i] = "*" + piece_name;
				}
			}
		
		if(false){// (w_rook_call) {
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

			for (int row = rook_row + 1; row < 8; ++row) {  // Move down.
			    if (chess_table[row][rook_col] != "  . ") { // Obstruction detected.
    			    break;
   				 }
   			 	chess_table[row][rook_col] = "*" + piece_name; // Mark as possible move
			}
		}
		
		if (false){//(b_rook_call) {
			// Horizontal moves to the left and right
			for (int col = rook_col - 1; col >= 0; --col) { // Move left
			    if (chess_table[rook_row][col] != "  . ") { // Obstruction detected
    			    break;
   				 }
   				 chess_table[rook_row][col] = "*" + piece_name; // Mark as possible move
			}

			for (int col = rook_col + 1; col < 8; ++col) { // Move right.
    			if (chess_table[rook_row][col] != "  . ") { // Obstruction detected.
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

			for (int row = rook_row + 1; row < 8; ++row) { // Move down.
			    if (chess_table[row][rook_col] != "  . ") { // Obstruction detected.
    			    break;
   				 }
   			 	chess_table[row][rook_col] = "*" + piece_name; // Mark as possible move
			}
		}
        
     

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
	cout << " |   ";
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
		
		// Rook move check.
        if (w_rook_call || b_rook_call) {
            // Check horizontal and vertical moves for rook
            if (move_row == rook_row || move_col == rook_col) {
                valid_move = true;
            }
        }
        
        // Bishop Move check.
        if (w_bishop_call || b_bishop_call) {
        	if(abs(move_row - bishop_row) == abs(move_col - bishop_col)) {
            valid_move = true;
    		}
		}
        
//	Checking for a valid move.
        if (valid_move) {
			
			if (b_bishop_call) {
				// Removing possible move marks.
				//	Diagonal moves.
	            for (int i = 0; i < 7; i++) {
	            	if(chess_table[bishop_row - i][bishop_col - i] == "*" + piece_name) 	// Top-left
		                chess_table[bishop_row - i][bishop_col - i] = "  . ";
		            if(chess_table[bishop_row - i][bishop_col + i] == "*" + piece_name) 	// Top-right
		                chess_table[bishop_row - i][bishop_col + i] = "  . ";
		            if(chess_table[bishop_row + i][bishop_col - i] == "*" + piece_name) 	// Bottom-left
		                chess_table[bishop_row + i][bishop_col - i] = "  . ";
		            if(chess_table[bishop_row + i][bishop_col + i] == "*" + piece_name) 	// Bottom-right
		                chess_table[bishop_row + i][bishop_col + i] = "  . ";
		                
		            
					// Update the chessboard
	                chess_table[b_bishop_positions[piece_index][0]][b_bishop_positions[piece_index][1]] = "  . "; // Clear the current position
	                b_bishop_positions[piece_index][0] = move_row; // Update the rook's position
	                b_bishop_positions[piece_index][1] = move_col; // Update the rook's column
	                chess_table[move_row][move_col] = " " + piece_name; // Place the rook in the new position    
				}
			}
				
				if (w_bishop_call) {
					// Removing possible move marks.
	            //	Diagonal moves.
	            for (int i = 0; i < 7; i++) {
	            	if(chess_table[bishop_row - i][bishop_col - i] == "*" + piece_name) 	// Top-left
		                chess_table[bishop_row - i][bishop_col - i] = "  . ";
		            if(chess_table[bishop_row - i][bishop_col + i] == "*" + piece_name) 	// Top-right
		                chess_table[bishop_row - i][bishop_col + i] = "  . ";
		            if(chess_table[bishop_row + i][bishop_col - i] == "*" + piece_name) 	// Bottom-left
		                chess_table[bishop_row + i][bishop_col - i] = "  . ";
		            if(chess_table[bishop_row + i][bishop_col + i] == "*" + piece_name) 	// Bottom-right
		                chess_table[bishop_row + i][bishop_col + i] = "  . ";
		                
		            
					// Update the chessboard
	                chess_table[w_bishop_positions[piece_index][0]][w_bishop_positions[piece_index][1]] = "  . "; // Clear the current position
	                w_bishop_positions[piece_index][0] = move_row; // Update the rook's position
	                w_bishop_positions[piece_index][1] = move_col; // Update the rook's column
	                chess_table[move_row][move_col] = " " + piece_name; // Place the rook in the new position 
				}
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
    } 
	
	else {
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
