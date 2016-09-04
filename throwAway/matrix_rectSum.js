
/* The GI 

Find the sum of all the points in the rectangle in general and 
implement the below APIs

setPoints(matrix, coords,  value)
getSumRectangle(matrix, rect_coords)

Make getSumRectangle O(n) in worst case

*/



//Version 1 without O(n) optimization

var inMatrixRange = function(len, x, y) {

	if(x < 0 || y < 0 || x >= len || y >= len) {
		//Out of range, dont update
		return false;
	} else {
		return true;
	}

}

var setPoints = function(matrix, coords, value) {

	if(matrix === null || coords === null || value === null) {
		return true;
	}

	var x = coords[0];
	var y = coords[1];


	if(!inMatrixRange(matrix.length, x, y)) {
		return false;
	}

	matrix[x][y] = value;

	return true;

}


var getSumRectangle = function(matrix, rect_coords) {
	if(matrix === null || rect_coords === null) {
		return -1;
	}

	var sum = 0;

	var lower_x = rect_coords[0][0];
	var lower_y = rect_coords[0][1];
	var upper_x = rect_coords[1][0];
	var upper_y = rect_coords[1][1];

	if(!inMatrixRange(matrix.length, lower_x, lower_y) || 
		!inMatrixRange(matrix.length, upper_x, upper_y)) {
		return -1;
}

	//Go through all the points in the rectangle and calculate the sum
	for(var i = lower_x; i <= upper_x; i++) {
		for(var j = lower_y; j <= upper_y; j++) {
			sum += matrix[i][j];
		}
	}

	return sum;

} 


var array1 = [
[1, 2, 30, 11, 21],
[34, 29, 4, 2, 1],
[3, 8, 10, 1, 3],
[13, 23, 1, 7, 16]

];



