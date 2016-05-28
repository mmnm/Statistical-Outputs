
/*
ds - matrix
1. Init - matrix - row, col - Init to 0s
2. randomly assign bombs and keep track of them --- 1s






*/


function Game(width, height, mine_count) {

	this.matrix = [[]];
	this.rows = height;
	this.cols = width;

	this.init(this.rows, this.cols);
	this.BombRandomizer(this.rows, this.cols, mine_count);
	this.printMatrix(this.rows, this.cols);


}

Game.prototype.printMatrix = function(rows, cols) {

	for(var i = 0; i < rows; i++) {
		for(var j = 0; j < cols; j++) {
			console.warn(this.matrix[i][j]);
		}
	}



}

Game.prototype.init = function(rows, cols) {

	for(var i = 0; i < rows; i++) {
		this.matrix[i] = [];
	}

	//Init this matrix to all 0s
	for(var i = 0; i < rows; i++) {
		for(var j = 0; j < cols; j++) {
			this.matrix[i][j] = 0;
		}
	}




}

Game.prototype.BombRandomizer = function(rows, cols, mine_count) {

	// Math.floor((Math.random() * (width - 1)) + 0)
	// console.warn("BombRand Width: height:: mine_count", 
	// 	width, height, mine_count);
	while(mine_count > 0) {

		var x_bomb = Math.floor( (Math.random() * (rows - 1) ) + 0);
		var y_bomb = Math.floor( (Math.random() * (cols - 1) ) + 0);

		if(this.matrix[x_bomb][y_bomb] === 1) {
			continue;
		} else {
			this.matrix[x_bomb][y_bomb] = 1;
			mine_count--;
		}

	}

}

// reveal takes x and y coordinates and returns the
// count of surrounding mines, or -1 if the cell at x,y
// contains a mine
Game.prototype.reveal = function(col, row) {

/*
	if a 1 is found --- return -1
	if a 0 is found then traverse each of it valid neignbors 
	and return the number of 1s

     1 0 1
     1 0 1
     1 1 1

     */

var count = -1;
if(this.matrix[row][col] === 1) {
     	return count;
}
count++;

var neigbor_rows =  [-1, -1, 0, 1, 1, 1, 0, -1];
var neighbor_cols = [0,  1, 1, 1, 0, -1, -1, -1];

//Check for valid neigbors only

for(var i = 0; i < 8; i++) {

	var curX = row + neigbor_rows[i];
	var curY = col + neighbor_cols[i];

	if( ((curX >= 0) && (curX < this.rows)) && 
		((curY >= 0) && (curY < this.cols)) ) {
		if(this.matrix[curX][curY]) {
			count++;
		}
	}

}

return count++;



};

module.exports = Game;
