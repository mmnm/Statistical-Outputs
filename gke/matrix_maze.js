/* Solve a maze

Return a solution gto solve a maze.

{1, 0, 0, 0}
{1, 1, 0, 1}
{0, 1, 0, 0}
{1, 1, 1, 1}


Assumptions : valid paths are all diagonal and vertical / horizontal connections


*/



var matrix = 
[
[1, 0, 0, 0],
[1, 1, 0, 1],
[0, 1, 0, 0],
[1, 1, 1, 1]
];





var solveMaze = function(matrix) {


	var rows = matrix.length;
	var cols = matrix[0].length;

	var isSeen = [[]];
	for(var i = 0; i < rows; i++) {
		isSeen[i] = [];
		for(var j = 0; j < cols; j++) {
			isSeen[i][j] = false;
		}
	}


	var start_index = [0,0];
	var end_index = [cols - 1, rows - 1];
	var output_index = [];

	if(solveMazeUtil(matrix, start_index, end_index, isSeen, output_index)) {
		return output_index;
	} else {
		return [];
	}


}

var isIndexesSame = function(start, end) {

	if( (start[0] === end[0]) && (start[1] === end[1]) ) {
		return true;
	}

	return false;



}



var solveMazeUtil = function(matrix, start_index, end_index, isSeen, output_index) {

	//Blah blah checks
	if(matrix === null || start_index === null || end_index === null || isSeen === null) {
		return [];
	}

	//Process current node

	if(isIndexesSame(start_index, end_index)) {
		//Path found 
		pathFound = true;
		console.log("Yayyyyy path found");
		
		output_index.push(end_index);
		return true;

	}

	output_index.push(start_index);


	var neighborRows = [-1, -1, -1, 0, 0, 1, 1, 1];
	var neighborCols = [-1, 0, 1, -1, 1, -1, 0, 1];
	
	var curRow = start_index[0];
	var curCol = start_index[1];
	isSeen[curRow][curCol] = true;


	//Process its neighbors
	for(var k = 0; k < 8; k++) {
		var curR = curRow + neighborRows[k];
		var curC = curCol + neighborCols[k];

		//Check Valid neigbor
		if( (curC >= 0) && (curC < matrix[0].length) && 
			(curR >= 0) && (curR < matrix.length) ) {
			

		//Check if not visited and call solveUtil to find a path
	if( !(isSeen[curR][curC]) && (matrix[curR][curC] === 1) ) {
		if(solveMazeUtil(matrix, [curR, curC], end_index, isSeen, output_index)) {
			return true;
		}
	}

}

}

	//Backtrack the solution as it is not found
	output_index.pop();
	return false;


}



var matrix = 
[
[1, 0, 0, 0],
[1, 1, 0, 1],
[0, 1, 0, 0],
[1, 1, 1, 1]
];



console.log(solveMaze(matrix));






