/* Find path in a maze (shortest) from start to end (shortest path);
if there are no blockages
What is shortest path - 
traverse diagonal untill start and end are on the same row and then
move in straight column path
*/

var movecords = function(start, direction) {

	var res = start;
	if(direction === true) {
		res += 1;

	} else {
		res -= 1;
	}

	return res;

};


var findShortestMazePathNoBlockage = 
function(matrix, start_cords, end_cords) {

// debugger;
if(matrix === null || matrix === undefined) {

	return null;
}

if(start_cords === null || start_cords === undefined) {
	return null;
}

if(end_cords === null || end_cords === undefined) {
	return null;
}

//Test if start_cords and end_cords are indeed part of the maze


var start_row = start_cords[0];
var end_row =end_cords[0];
var start_col = start_cords[1];
var end_col = end_cords[1];

var col_forward_dir = false;
var row_forward_dir = false;

var res_array = [];
res_array.push(start_cords);
var count_shortest_path_hops  = 0;

if(start_row < end_row) {
	row_forward_dir = true;
} else {
	row_forward_dir = false;
}

if(start_col < end_col) {
	col_forward_dir = true;
} else {
	col_forward_dir = false;
}

while( (start_row !== end_row) && (start_col !== end_col) ) {

//We move diagonal till they become equal
//We need to know the direction

start_row = movecords(start_row, row_forward_dir);
start_col = movecords(start_col, col_forward_dir);

res_array.push([start_row, start_col]);
count_shortest_path_hops++;

}

//Now start and end are in the same row, 
//move straight till they are same col

while(start_col !== end_col) {
	start_col = movecords(start_col, col_forward_dir);
	res_array.push([start_row, start_col]);
	count_shortest_path_hops++;

}

while(start_row !== end_row) {
	start_row = movecords(start_row, row_forward_dir);
	res_array.push([start_row, start_col]);
	count_shortest_path_hops++;

}

console.log("Shortest path hop count: ", count_shortest_path_hops);
return res_array;

}


var array1 = [

[1,1,1,1,1],
[1,1,1,1,1],
[1,1,1,1,1],
[1,1,1,1,1],
[1,1,1,1,1],
[1,1,1,1,1],
[1,1,1,1,1]

];


console.log(findShortestMazePathNoBlockage(array1, [0,0], [5,4]));
console.log(findShortestMazePathNoBlockage(array1, [5,4], [0,0]));
console.log(findShortestMazePathNoBlockage(array1, [0,0], [3,4]));
console.log(findShortestMazePathNoBlockage(array1, [3,4], [0,0]));
console.log(findShortestMazePathNoBlockage(array1, [1,4], [1,0]));
console.log(findShortestMazePathNoBlockage(array1, [1,0], [1,4]));











