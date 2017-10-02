/* SOLVE A MAZE 

0 - Represents you can not move / blockage
start cords are given
end_coords is 9
1 - Represents you can pass through 
You can pass thru neighbors if no blocakge

*/

var matrix1 = 
[
  [1,0,1,1,1,0],
  [1,1,0,0,0,0],
  [1,0,1,1,0,0],
  [1,1,1,1,0,0],
  [1,0,1,1,1,9] 
];

var matrix2 = 
    [
      [1,1,1,1],
      [1,1,1,1],
      [1,1,1,9]
      ];


var matrix3 = 
    [
      [1,1],
      [1,9]
      ];

var solveMazeUtil = function(matrix, start, isSeen) {
  
 //Error checks
  
  var cur_output = [];
  
  var rows = matrix.length;
  var cols = matrix[0].length;
  
  /* 
   1 1 1 
   1 1 1 
   1 1 1 
  
  */
  isSeen[start[0]][start[1]] = true;
  
  if(matrix[start[0]][start[1]] === 9) {
    cur_output.push(start);
    return cur_output;
  }
  
  
  
  var neigbor_x = [-1, 0, 1, 1, 1, 0, -1, -1];
  var neighbor_y = [1, 1, 1, 0, -1, -1, -1, 0];

  
  //Check if path exists through neighbor
  for(var i = 0; i < neigbor_x.length; i++) {
   
    var cur_x = neigbor_x[i] + start[0];
    var cur_y = neighbor_y[i] + start[1];
    
         //Valid neighbor
    if(cur_x > 0 && cur_y > 0 &&
       cur_x < rows && cur_y < cols) {
 
      if(!isSeen[cur_x][cur_y]) {
           
        if(matrix[cur_x][cur_y] !== 0) {
          var postfix_output = 
              solveMazeUtil(matrix, 
                            [cur_x, cur_y], isSeen);
          
          if(postfix_output.length !== 0) {
            //Found answer
            cur_output.push(start);
            cur_output = cur_output.concat(postfix_output);
            return cur_output;
          }
        }
      }
    }
  }
    
  return cur_output;
  
};


var solveMaze = function(matrix, start) {
  
 debugger;
  //Error checks
  if(matrix === null) {
    return [];
  }
  
  var rows = matrix.length;
  var cols = matrix[0].length;
  var isSeen = [[]];
  
  for(var i = 0; i < rows; i++) {
    isSeen[i] = [];
    for(var j = 0; j < cols; j++) {
      isSeen[i][j] = false;
    }
  }
  
  return solveMazeUtil(matrix, start, isSeen);

};


console.log(solveMaze(matrix3, [0,0]));
console.log(solveMaze(matrix2, [0,0]));
console.log(solveMaze(matrix1, [0,0]));