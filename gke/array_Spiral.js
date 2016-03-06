/* 
Print a given matrix in spiral form
Given a 2D array, print it in spiral form. See the following examples.

Input:
        1    2   3   4
        5    6   7   8
        9   10  11  12
        13  14  15  16
Output: 
1 2 3 4 8 12 16 15 14 13 9 5 6 7 11 10 


Input:
        1   2   3   4  5   6
        7   8   9  10  11  12
        13  14  15 16  17  18
Output: 
1 2 3 4 5 6 12 18 17 16 15 14 13 7 8 9 10 11


*/




var printSpiral = function(matrix) {

	if(matrix === null || matrix === undefined) {

		return;

	}



	var rows = matrix.length;
	var cols = matrix[0].length;

	var left = 0;
	var right = cols - 1;
	var top = 0;
	var bottom = rows - 1;

	for(;;) {

		//Print left to right
		if(top > bottom) {
			break;
		}
		for(var i = left; i <= right; i++) {

			console.log(matrix[top][i]);

		}
		top++;


	//Print top to bottom
	if(left > right) {
		break;
	}

	for(var i = top; i <= bottom; i++) {

		console.log(matrix[i][right]);
	}
	right--;


		//Print right to left

		if(top > bottom) {
			break;
		}

		for(var i = right; i >= left; i--){

			console.log(matrix[bottom][i]);

		}
		bottom--;


		//Print bottom to top

		if(left > right) {
			break;
		}

		for(var i = bottom; i >= top; i--) {
			console.log(matrix[i][left])
		}
		left++;


	}



}

// 1 2 3 4 8 12 16

var array1 = [ 
[1, 2,   3,    4],
[5, 6,   7,    8],
[9, 10, 11,    12],
[13, 14, 15,   16]
];

var array2 = [
[1,   2,   3,   4,  5,   6],
[7,   8,   9,  10,  11,  12],
[13,  14,  15, 16,  17,  18]
];

console.log(printSpiral(array1));
console.log(printSpiral(array2));