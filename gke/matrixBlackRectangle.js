

/*
// Q1

Imagine we have an image where every pixel is white or black.  We’ll represent this image as a simple 2D array (0 = black, 1 = white).
The image you get is known to have a single black rectangle on a white background.
Your goal is to find this rectangle and return its coordinates.

var image = [
[1, 1, 1, 1, 1, 1, 1],
[1, 1, 1, 1, 1, 1, 1],
[1, 1, 1, 0, 0, 0, 1],
[1, 1, 1, 0, 0, 0, 1],
[1, 1, 1, 1, 1, 1, 1]
];
*/

/* Concentrate on corner cases:
1. Ensure there is no out of bound array access, this can be done if in any loop two things are ensured: a. Bound is checked at start in loop
       b. increment decrement operations are done as the last statement of loop

2. Ensure the loops break out as intended. break used will break out from current loop and not all loops

*/           

/*
Complexity analysis
There could an optimization of below algo: The lower right co-ordinates could be found by traversing diagonal right 
*/


var getBlackRightCord = function(matrix, leftx, lefty) {
  //Edge cases
  //if there is only 1 row with 0s
  //if there is multiple rows
  //if only 1 0s
  var row = matrix.length;
  var col = matrix[0].length;
  

  var curRow0 = matrix[leftx][lefty];
  var left = leftx, right = lefty;
  
  while((curRow0 !== 1) && (left < row)) {
    curRow0 = matrix[left][right];
    left = left + 1;
  }
  
  var leftcord = left - 1;
  var curRow0 = matrix[leftcord][lefty];
  
  while((curRow0 !== 1) && (right < col)) {
    curRow0 = matrix[leftcord][right];
    right = right + 1;
  }
  
  var rightcords = [];
  rightcords.push(leftcord, right - 1);
  return rightcords;
  

}



var returnBlackRectange = function(matrix) {


  if(matrix === null) {
    return -1;
  }
  
  
  var row = matrix.length;
  var col = matrix[0].length;

  
  //This has upper left and bottom right co-rds of the rectange
  var out_arr = [];
  
  for(var i = 0; i < row; i++) {

    var curRow = matrix[i];
    for(var j = 0; j < col; j++) {
      var curElem = curRow[j];

      if(curElem === 0) {

        console.log("times");
        
        var cordLeft = [];
        cordLeft.push(i, j);
        out_arr.push(cordLeft);
        var cordRight = [];
        
        cordRight = getBlackRightCord(matrix, i, j);
        out_arr.push(cordRight);  
        return out_arr;
      }
      
    }
    
  }



  
}


//Test cases

// var image = [
// [1, 1, 1, 1, 1, 1, 1],
// [1, 1, 1, 1, 1, 1, 1],
// [1, 1, 1, 0, 0, 0, 1],
// [1, 1, 1, 0, 0, 0, 1],
// [1, 1, 1, 1, 1, 1, 1]
// ];
// console.log(returnBlackRectange(image));
/************/

//Test cases

// var image = [
// [1, 1, 1, 1, 1, 1, 1],
// [1, 1, 1, 1, 1, 1, 1],
// [1, 1, 1, 1, 1, 1, 1],
// [1, 1, 1, 1, 0, 0, 0],
// [1, 1, 1, 1, 1, 1, 1]
// ];


// console.log(returnBlackRectange(image));

/************/

//Test cases

var image = [
[1, 1, 1, 1, 1, 1, 1],
[1, 1, 1, 1, 1, 1, 1],
[1, 1, 1, 1, 1, 1, 1],
[1, 1, 1, 1, 1, 1, 1],
[1, 1, 1, 1, 0, 0, 0]
];


console.log(returnBlackRectange(image));




