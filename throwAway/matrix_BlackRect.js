/* 
Find black cords


var image = [
[1, 1, 1, 1, 1, 1, 1],
[1, 1, 1, 1, 1, 1, 1],
[1, 1, 1, 0, 0, 0, 1],
[1, 1, 1, 0, 0, 0, 1],
[1, 1, 1, 1, 1, 1, 1]
];

var image2 = [
[1, 1],
[1, 0]
];

*/




var findBlackRect = function(image) {

	if(image === null) {


		return null;
	}


//Find the left_top
var rows = image.length;
var cols = image[0].length;

var resBlack = [];
var found_leftTop = false;
for(var i = 0; i < rows; i++) {

	for(var j = 0; j < cols; j++) {


		if(image[i][j] === 0) {
			resBlack.push([i, j]);
			found_leftTop = true;
			break;
		}
	}

	if(found_leftTop) {
		break;
	}

}



//Now move down to find the target row
var target_row = resBlack[0][0];
var target_col = resBlack[0][1];

console.log("Starting x, y: ", target_row, " ", target_col);



while(target_row + 1 < rows) {

	target_row++;


	if(image[target_row][target_col] === 1) {
		target_row--;
		break;
	}


}

//Now move right to find the target col
while(target_col + 1 < cols) {

	target_col++;


	if(image[target_row][target_col] === 1) {
		target_col--;
		break;
	}


}

resBlack.push([target_row, target_col]);


return resBlack;


}


var image = [
[1, 1, 1, 1, 1, 1, 1],
[1, 1, 1, 1, 1, 1, 1],
[1, 1, 1, 0, 0, 0, 1],
[1, 1, 1, 0, 0, 0, 1],
[1, 1, 1, 1, 1, 1, 1]
];

var image2 = [
[1, 1],
[1, 0]
];


console.log(findBlackRect(image));
console.log(findBlackRect(image2));