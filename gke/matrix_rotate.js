
/*

Rotate an image by 90


1 1 0 1
1 0 1 1   --->  1  1
                0  1
                1  0
                1  1


1, 2

2, rows - 1 - 1




*/




var rotateImage = function(matrix) {

	var rows = matrix.length;
	var cols = matrix[0].length;



	var res_matrix = [];


	for(var i = 0; i < cols; i++) {
		res_matrix[i] = [];
	}

	for(var i = 0; i < rows; i++) {

		for(var j = 0; j < cols; j++) {

			//Put it in new matrix at correct location
			res_matrix[j][rows - 1 - i] = matrix[i][j];

		}

	}

	return res_matrix;


}


var printMatrix = function(matrix) {


	var rows = matrix.length;
	var cols = matrix[0].length;

	var sum = 0;
	for(var i = 0; i < rows; i++) {
		for(var j = 0;  j < cols; cols++) {

			sum += matrix[i][j];
			// console.log(matrix[i][j] + " ");


		}
		// console.log("\n");
	}

	console.log(sum);

}


// var array1 = [
// 							[1,1,0,1],
// 							[1,0,0,1]
// 							];


var array1 = [
							 [1,1,0,1],
							 [1,0,0,1]
									];


var printMatrix = function(matrix) {

	var rows = matrix.length;
	var cols = matrix[0].length;


	for(var i = 0; i < rows; i++) {
		var string1 = "";
		for(var j = 0; j < cols; j++) {
			string1 += matrix[i][j];
			string1 += " ";
		}
		console.log(string1);
	}




}

printMatrix(array1);


console.log("Transformed matrix: ");
console.log(printMatrix(rotateImage(array1)));










