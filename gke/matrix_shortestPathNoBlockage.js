/* Find the shortest path in a maze between two points which does not have blockages*/



var isInMatrixRange = function(curElem, matrixLen) {

	if(matrixLen === null || curElem === null) {
		return null;
	}

	if((curElem < 0) || (curElem >= matrixLen)) {
		return false;
	} 

	return true;

}


var updatedCord = function(curElem, directionVal, matrixLen) {



	var ret_cord = curElem + directionVal;


	//Check if any of them is out of range then reset them
	if(!isInMatrixRange(ret_cord, matrixLen)) {
	//Reset
	return curElem;
}

return ret_cord;

}

/* coords is an array of form [x1, y1]*/
var findShortestPathInMaze = function(matrix, coords1, coords2) {

	if(matrix === null || coords1 === null || coords2 === null) {
		return null;
	}
	// debugger;
//Check if the coords are in valid range
if(!isInMatrixRange(coords1[0], matrix.length) || 
	!isInMatrixRange(coords2[0], matrix.length) ||
	!isInMatrixRange(coords1[1], matrix[0].length) ||
	!isInMatrixRange(coords2[1], matrix[0].length) ) {
	return null;
}

var output_arr = [];
var row_forward_dir = -1;
var col_forward_dir = -1;

if(coords1[0] <= coords2[0]) {
	row_forward_dir = 1;
}
if(coords1[1] <= coords2[1]) {
	col_forward_dir = 1;
}


while( (coords1[0] !== coords2[0]) || (coords1[1] !== coords2[1]) ){

	output_arr.push(coords1.slice());
//Adjust coords1 to new valid range coords
var new_x = coords1[0];
var new_y = coords1[1];

if(coords1[0] !== coords2[0]) {
	new_x = updatedCord(coords1[0], row_forward_dir, matrix.length);
}

if(coords1[1] !== coords2[1]) {
	new_y = updatedCord(coords1[1], col_forward_dir, matrix[0].length);
}

coords1 = [new_x, new_y];

}

// Make the last input 
output_arr.push(coords2.slice());

return output_arr;


}

var matrix1 = [

[1,1,1,1,1],
[1,1,1,1,1],
[1,1,1,1,1],
[1,1,1,1,1],
[1,1,1,1,1]
];


console.log(findShortestPathInMaze(matrix1, [0,0], [4,4]));
console.log(findShortestPathInMaze(matrix1, [4,4], [0,0]));
console.log(findShortestPathInMaze(matrix1, [4,4], [0,0]));
console.log(findShortestPathInMaze(matrix1, [4,4], [1,3]));
console.log(findShortestPathInMaze(matrix1, [1,3], [4,4]));
console.log(findShortestPathInMaze(matrix1, [1,3], [2,3]));
console.log(findShortestPathInMaze(matrix1, [1,3], [2,3]));
console.log(findShortestPathInMaze(matrix1, [4,2], [0,0]));




