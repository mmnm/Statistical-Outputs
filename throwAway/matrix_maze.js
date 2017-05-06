/* 
Solve a maze 

Rules: 1. Start point is (0,0)
2. End point is value of 9
3. you can walk through top, left, right, down if value is 1
4. If value is 0, you can not walk through 

Find any solution 

    1   
  1 1 1
    1 

*/


var solveMazeUtil = function(matrix, start, isSeen) {

  if(matrix === null) {
    return null;
  }
  
  var rows = matrix.length;
  var cols = matrix[0].length;
  
  
  var s_x = start[0];
  var s_y = start[1];
  
  isSeen[s_x][s_y] = 1;
  
  var output = [];
  
  //Found soln
  if(matrix[s_x][s_y] === 9) {
    console.log("Found", s_x,s_y);
    output.push([s_x,s_y]);
    return output;
  }
  
  var neighbor_x = [-1, 0, 1, 0];
  var neighbor_y = [0, 1, 0, -1];
  
  //Traverse valid neighbors
  for(var i = 0; i < neighbor_x.length; i++) {
    
    var c_x = s_x + neighbor_x[i];
    var c_y = s_y + neighbor_y[i];
  
    
    if(c_x >= 0 && c_x < rows && c_y >= 0 && c_y < cols) {
       
      
      if( (isSeen[c_x][c_y] === 0) && 
         (matrix[c_x][c_y] === 1 || 
          matrix[c_x][c_y] === 9) ) {
        
        var curOp = 
            solveMazeUtil(matrix, [c_x, c_y], isSeen);
        
        if(curOp.length !== 0) {
          //Found soln
          output.push([s_x,s_y]);
          output = output.concat(curOp);
          return output;
        }
        
      }
    }
  
  }
  
  return output;
  
}
  
  


var solveMaze = function(matrix) {
  
 if(matrix === null) {
   return [];
 }

  var rows = matrix.length;
  var cols = matrix[0].length;
  
  
  var start = [0,0];
  
  var isSeen = [[]];
  
  for(var i = 0; i < rows; i++) {
    
    isSeen[i] = [];
    
    for(var j = 0; j < cols; j++) {
    
      isSeen[i][j] = 0;
    }
  }
  
  return solveMazeUtil(matrix, start, isSeen);
  
}

var matrix = [[1,1,1,0,9],
              [0,0,1,0,1],
              [1,1,1,0,1],
              [0,0,1,0,1],
              [0,1,1,1,1]
             ];



  console.log(solveMaze(matrix));
