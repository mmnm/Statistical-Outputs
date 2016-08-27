/* 
Find the number of islands 

{1, 1, 0, 0, 0},
{0, 1, 0, 0, 1},
{1, 0, 0, 1, 1},
{0, 0, 0, 0, 0},
{1, 0, 1, 0, 1}


1 1 1 1 
1 1 1 1 
1 1 1 1


Algo: we can use dfs or bfs to find the connected components and then increment the count for each of those 
connected components. Visit only unique components 

*/

var isvalidRange = function(number, max) {

	if(number < 0 || number >= max) {
		return false;
	}
	return true;
}

var dfsVisit = function(matrix, row_index, col_index, isVisited) {

	if(matrix === null || isVisited === null) {
		return;
	}

	isVisited[row_index][col_index] = true;

	var neighbor_rows = [-1, 0, 1, 1, 1, 0, -1, -1];
	var neighbor_cols = [1, 1, 1, 0, -1, -1, -1, 0];

//Max 8 neigbors possible
for(var i = 0; i < 8; i++) {
	var cur_row = neighbor_rows[i] + row_index;
	var cur_col = neighbor_cols[i] + col_index;

	if(!isvalidRange(cur_row, matrix.length) || !isvalidRange(cur_col, matrix.length)) {
		continue;		
	}

	if(!isVisited[cur_row][cur_col] && matrix[cur_row][cur_col]) {
		dfsVisit(matrix, cur_row, cur_col, isVisited);
	}

}


}

var findNumberOfIslands = function(matrix) {

	if(matrix === null) {
		return 0;
	}

	var rows = matrix.length;
	var cols = matrix[0].length;


//We need to keep track of visited nodes
var isVisited = [[]];

for(var i = 0; i < rows; i++) {
	isVisited[i] = [];
	for(var j = 0; j < cols; j++) {
		isVisited[i][j] = false;
	}
}

var numberOfIslands = 0;

for(var i = 0; i < rows; i++) {
	for(var j = 0; j < cols; j++) {

		if(matrix[i][j] && isVisited[i][j] === false) {
			numberOfIslands++;
			dfsVisit(matrix, i, j, isVisited);

		}

	}

}

return numberOfIslands;


}


var array1 = 
[
[1, 1, 0, 0, 0],
[0, 1, 0, 0, 1],
[1, 0, 0, 1, 1],
[0, 0, 0, 0, 0],
[1, 0, 1, 0, 1]
];

console.log(findNumberOfIslands(array1));











