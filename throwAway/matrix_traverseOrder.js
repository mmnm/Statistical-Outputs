


var printSpiralOrder = function(matrix) {


	var rows = matrix.length;
	var cols = matrix[0].length;

	var left = 0;
	var right = cols - 1;
	var top = 0;
	var bottom = rows - 1;

	for(;;){

		if(left > right || top > bottom) {
			break;
		}

		for(var i = left; i <= right; i++) {
			console.log(" ", matrix[top][i]);
		}
		top++;

		if(left > right || top > bottom) {
			break;
		}
		
		for(var i = top; i <= bottom; i++) {
			console.log(" ", matrix[i][right]);
		}
		right--;

		if(left > right || top > bottom) {
			break;
		}

		for(var i = right; i >= left; i--) {
			console.log(" ", matrix[bottom][i]);
		}
		bottom--;

		if(left > right || top > bottom) {
			break;
		}

		for(var i = bottom; i >= top; i--) {
			console.log(" ", matrix[i][left]);
		}

		left++;

	}


}

//Test cases

var array1 = [[1,2,3],
						[4,5,6],
						[7,8,9]];

var array2 = [[1,2,3,4,5],
							[6,7,8,9,10],
							[11,12,13,14,15],
							[16,17,18,19,20],
							[21,22,23,24,25]];

var array3 = 
	[[1,2,3,4],
	[5,6,7,8],
	[9,10,11,12],
	[13,14,15,16]];


var array4 = 
[[1,2,3,4,5,6],
[7,8,9,10,11,12],
[13,14,15,16,17,18]];

console.log("Test 1: Array 1");
console.log(printSpiralOrder(array1));
console.log("Test 2: Array 2");
console.log(printSpiralOrder(array2));
console.log("Test 3: Array 3");
console.log(printSpiralOrder(array3));
console.log("Test 4: Array 4");
console.log(printSpiralOrder(array4));


