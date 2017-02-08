/* Given a boolean 2D matrix, find the number of islands. 
A group of connected 1s forms an island. 
For example, the below matrix contains 5 islands

Input : mat[][] = {{1, 1, 0, 0, 0},
                   {0, 1, 0, 0, 1},
                   {1, 0, 0, 1, 1},
                   {0, 0, 0, 0, 0},
                   {1, 0, 1, 0, 1} 
Output : 5

1 1 1 
1 1 1  
1 1 1   


*/

var dfsvisit = function(matrix, visited, row, col) {

	//Form neighbors to visit
	var neighbor_row = [-1, 0, 1, 1, 1,  0, -1, -1,];
	var neighbor_col = [1, 1,  1, 0, -1, -1, -1, 0];

	//Visit all valid neigbors
	for(var i = 0; i < 8; i++) {

		var cur_row = row + neighbor_row[i];
		var cur_col = col + neighbor_col[i];

		if(cur_row >= 0 && cur_row <= matrix.length - 1 && cur_col >= 0 &&
			cur_col <= matrix[0].length - 1) {
			if(matrix[cur_row][cur_col] && !visited[cur_row][cur_col]) {
				visited[cur_row][cur_col] = true;
				dfsvisit(matrix, visited, cur_row, cur_col);
			} 
		}

	}


}



var findIslands = function(matrix) {

	if(matrix === null) {
		return 0;
	}

	/* Start probing the matrix */
	var rows = matrix.length;
	var cols = matrix[0].length;

	var visited = [];
	for(var i = 0; i < rows; i++) {
		visited[i] = [];
		for(var j = 0; j < cols; j++) {
			visited[i][j] = false;
		}
	}

	

	var count = 0;
	for(var i = 0; i < rows; i++) {
		for(var j = 0; j < cols; j++) {

			if(!visited[i][j] && matrix[i][j]) {
				dfsvisit(matrix, visited, i, j);
				count++;
			}

		}
	}

	return count;

}

var matrix =       [[1, 1, 0, 0, 0],
                   [0, 1, 0, 0, 1],
                   [1, 0, 0, 1, 1],
                   [0, 0, 0, 0, 0],
                   [1, 0, 1, 0, 1]];

console.log(findIslands(matrix));


