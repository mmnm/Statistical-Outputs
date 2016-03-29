/* Find all the islands */

/*

       {1, 1, 0, 0, 0},
       {0, 1, 0, 0, 1},
       {1, 0, 0, 1, 1},                 
       {0, 0, 0, 0, 0},
       {1, 0, 1, 0, 1}
       */





       var dfsVisit = function(matrix, coords, isSeen) {

       	if(matrix === null || coords === null || isSeen === null) {
       		console.log("Something wrong in dfsVisit call")
       		return;
       	}

       	var neighborsRow = [-1, -1, -1, 0, 0, 1, 1, 1];
       	var neighborsCol = [-1, 0, 1, -1, 1, -1, 0, 1];


	//Explore connected neighbor components
	for(var i = 0; i < neighborsRow.length; i++) {
		var curR = neighborsRow[i] + coords[0];
		var curC = neighborsCol[i] + coords[1];

		if( (curR >= 0) && (curR < matrix.length) && (curC >= 0) && (curC < matrix[0].length) ) {


			if(!(isSeen[curR][curC]) && matrix[curR][curC]) {
				isSeen[curR][curC] = true;
				dfsVisit(matrix, [curR, curC], isSeen);
			}

		}

	}

}


var countIslands = function(matrix) {


	if(matrix === null) {
		return;
	}

	var rows = matrix.length;
	var cols = matrix[0].length;

	var isSeen = [[]];

	for(var i = 0; i < rows; i++) {
		isSeen[i] = [];
		for(var j = 0; j < cols; j++) {
			isSeen[i][j] = false;
		}
	}
	var isLandCount = 0;
	//We visit elements of the matrix and each time we find a 1 we traverse the dfs component 

	for(var i = 0; i < rows; i++) {
		for(var j = 0; j < cols; j++) {

			if( !(isSeen[i][j]) && matrix[i][j] ) {
				isLandCount++;
				dfsVisit(matrix, [i, j], isSeen);

			}

		}

	}

	return isLandCount;

}


var matrix = 


[
[1, 1, 0, 0, 0],
[0, 1, 0, 0, 1],
[1, 0, 0, 1, 1],                 
[0, 0, 0, 0, 0],
[1, 0, 1, 0, 1]
];



console.log(countIslands(matrix));












