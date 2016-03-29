
	// Check if the board elements have valid sudoku entries till this point

	// A sudoku board is 9 x 9


	var isValidSudoku = function(board) {

		// Must be 9 x 9
		var rows = board.length;
		var cols = board[0].length;

		if(rows !== 9 || cols !== 9) {
			return false;
		}


		//Keep track of the elems seen in rows and cols and 
		//board of 3x3, if they are repeated then it is invalid board

		var rowTrack = [];
		for(var i = 0; i < rows; i++) {
			rowTrack[i] = [];
		}

		var colTrack = [];
		for(var i = 0; i < cols; i++) {
			colTrack[i] = [];
		}

		var sudokuTrack = [];
		for(var i = 0; i < parseInt(rows / 3); i++) {
			sudokuTrack[i] = [];
			for(var j = 0; j < parseInt(cols/ 3); j++) {
				sudokuTrack[i][j] = [];

			}
			
		}





		for(var i = 0; i < rows; i++) {

			for(var j = 0; j < cols; j++) {

				var cur_elem = board[i][j];

				if(cur_elem === 0) {
					continue;
				}

				if(rowTrack[i][cur_elem]) {
		
					return false;
				} else {
					rowTrack[i][cur_elem] = true;
				}

				if(colTrack[j][cur_elem]) {
					
					return false;
				} else {
					colTrack[j][cur_elem] = true;
				}

				var gridx = parseInt(i / 3);
				var gridy = parseInt(j / 3);
				if(sudokuTrack[gridx][gridy][cur_elem]) {
				
					return false;
				} else {
					sudokuTrack[gridx][gridy][cur_elem] = true;
				}


			}

		}


		return true;

	}


	var board = [

	[5,3,0,0,7,0,0,0,0],
	[6,0,0,1,9,5,0,0,0],
	[0,9,8,0,0,0,0,6,0],
	[8,0,0,0,6,0,0,0,3],
	[4,0,0,8,0,3,0,0,1],
	[7,0,0,0,2,0,0,0,6],
	[0,6,0,0,0,0,2,8,0],
	[0,0,0,4,1,9,0,0,5],
	[0,0,0,0,8,0,0,7,9]


	];

	console.log(isValidSudoku(board));






