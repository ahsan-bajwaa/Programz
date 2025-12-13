// 	 Movement of Bishap.
	for(int i = 0; i <= 3; i++){
		int Rows = row -1, Coloumns = coloumn-1;
		for(int j = 0; j <10; j++){
			
			// condition for cross postion movement.
			if(Rows >= 0 && Rows < 10 && Coloumns >= 0 && Coloumns < 10){
				if(i == 0){
					chess[Rows--][Coloumns++] = 'Q';
				}
				if(i == 1){
					chess[Rows--][Coloumns--] = 'Q';
				}
				if(i == 2){
					chess[Rows++][Coloumns++] = 'Q';
				}
				if(i == 3){
					chess[Rows++][Coloumns--] = 'Q';
				}
			}
			
		}
	}
	
//	Movement of Knight.
		// It will prevent Knight to move outside the board.
	
	if (row - 3 >= 0 && coloumn - 2 >= 0)
		chess[row - 3][coloumn - 2] = '+';
	if (row - 3 >= 0 && coloumn < 10)
		chess[row - 3][coloumn] = '+';
	if (row - 2 >= 0 && coloumn - 3 >= 0)
		chess[row - 2][coloumn - 3] = '+';
	if (row - 2 >= 0 && coloumn + 1 < 10)
		chess[row - 2][coloumn + 1] = '+';

	if (row < 10 && coloumn - 3 >= 0)
		chess[row][coloumn - 3] = '+';
	if (row < 10 && coloumn + 1 < 10)
		chess[row][coloumn + 1] = '+';
	if (row + 1 < 10 && coloumn - 2 >= 0)
		chess[row + 1][coloumn - 2] = '+';
	if (row + 1 < 10 && coloumn < 10)
		chess[row + 1][coloumn] = '+';
		
// 	Movement of Rock
	for(int i = 0; i < 10; i++){
		for(int j = 0; j < 10; j++){
			chess[i][coloumn - 1] = 'Q';
			chess[row - 1][i] = 'Q';
		}
	}
	
// Movement of Queen.
	// 	 This loop will help to make cross position of queen.
	for(int i = 0; i <= 3; i++){
		int Rows = row -1, Coloumns = coloumn-1;
		for(int j = 0; j <10; j++){
			
			// condition for cross postion movement.
			if(Rows >= 0 && Rows < 10 && Coloumns >= 0 && Coloumns < 10){
				if(i == 0){
					chess[Rows--][Coloumns++] = 'Q';
				}
				if(i == 1){
					chess[Rows--][Coloumns--] = 'Q';
				}
				if(i == 2){
					chess[Rows++][Coloumns++] = 'Q';
				}
				if(i == 3){
					chess[Rows++][Coloumns--] = 'Q';
				}
			}
			
		}
	}
	
	// 		It make plus movement of Queen.
	for(int i = 0; i < 10; i++){
		for(int j = 0; j < 10; j++){
			chess[i][coloumn - 1] = 'Q';
			chess[row - 1][i] = 'Q';
		}
	}
	
					

if (row - 3 >= 0 && coloumn < 10)
		chess[row - 3][coloumn] = '+';
	if (row - 2 >= 0 && coloumn - 3 >= 0)
		chess[row - 2][coloumn - 3] = '+';
	if (row - 2 >= 0 && coloumn + 1 < 10)
		chess[row - 2][coloumn + 1] = '+';

	if (row < 10 && coloumn - 3 >= 0)
		chess[row][coloumn - 3] = '+';
	if (row < 10 && coloumn + 1 < 10)
		chess[row][coloumn + 1] = '+';
	if (row + 1 < 10 && coloumn - 2 >= 0)
		chess[row + 1][coloumn - 2] = '+';
	if (row + 1 < 10 && coloumn < 10)
		chess[row + 1][coloumn] = '+';

//		Bishop Moves.
	// Diagonal moves.
	
	// Bottom right side.
	for (int k = 1; k < 8; k++) {
	    if (row + k > 7 || col + k > 7) break; // Out of bounds checking..
	    if (chessboard[row + k][col + k] != "[ ]") break; // Obstruction detected.
	    chessboard[row + k][col + k] = "*"; // Marking valid move.
	}
	
	// Bottom-left move.
	for (int k = 1; k < 8; k++) { 
	    if (row + k > 7 || col - k < 0) break; // Out of bounds check.
	    if (chessboard[row + k][col - k] != "[ ]") break; // Obstruction detected.
	    chessboard[row + k][col - k] = "*"; // Marking valid move.
	}
	
	// Top right move.
	for (int k = 1; k < 8; k++) {
	    if (row - k < 0 || col + k > 7) break; // Out of bounds
	    if (chessboard[row - k][col + k] != "[ ]") break; // Obstruction detected
	    chessboard[row - k][col + k] = "*"; // Mark valid move.
	}
	
	// Top left move.
	for (int k = 1; k < 8; k++) {
	    if (row - k < 0 || col - k < 0) break; // Out of bounds
	    if (chessboard[row - k][col - k] != "[ ]") break; // Obstruction detected
	    chessboard[row - k][col - k] = "*"; // Marking valid move.
	}

	

