
/* Solve a maze

1 -> you can pass through 
0 -> Not pass through
9 - destination

You can poke only your neigbors (adjacent)
*/




// Assume start is [0,0] Always

/*

1 1 1
1 1 1
1 1 1

rows = [-1, 0, 1, 1, 1, 0, -1, -1];
cols = [1, 1, 1, 0, -1, -1, -1, 0];



*/

var solveMazeUtil = function(matrix, isSeen, start) {
  
 //Error checks
  var start_x = start[0];
  var start_y = start[1];
  
  isSeen[start_x][start_y] = true;
  
  
  if(matrix[start_x][start_y] === 9) {
    var res = [start_x, start_y];
    var output = [];    
    output.push(res);
    return output;
  }
  
  
  
  var rows = matrix.length;
  var cols = matrix[0].length;

  var neighbor_rows = [-1, 0, 1, 1, 1, 0, -1, -1];
  var neighbor_cols = [1, 1, 1, 0, -1, -1, -1, 0];
  
  for(var i = 0; i < neighbor_rows.length; i++) {
    
    var cur_x = start_x + neighbor_rows[i];
    var cur_y = start_y + neighbor_cols[i];
    
    if(cur_x >= 0 && cur_y >= 0 && cur_x < rows && 
       cur_y < cols) {
      
      if(!(isSeen[cur_x][cur_y]) && 
         matrix[cur_x][cur_y] !== 0) {
        var ret = solveMazeUtil(matrix, 
                                isSeen, [cur_x, cur_y]);
        if(ret !== null) {
    
          ret.unshift([start_x, start_y]);
          return ret;
        }
      
      
      }
     
    }
    
  
  }
  
  
  return null;
  

};
  


var solveMaze = function(matrix) {
  
 //Error checks
  
  var rows = matrix.length;
  var cols = matrix[0].length;
  
  
  //Define isSeen for tracking seen states
  
  var isSeen = [[]];
  var start = [0,0];
  
  for(var i = 0; i < rows; i++) {
   isSeen[i] = [];
    
    for(var j = 0; j < cols; j++) {
      
     isSeen[i][j] = false; 
      
    }
    
  };
  
  
  return solveMazeUtil(matrix, isSeen, start);
};
  
  
  
  
  
var matrix1 = [[1,0,0,0,0],
                [0,1,0,0,0],
                [1,0,0,0,0],
                [1,0,0,0,0],
                [1,1,9,0,0]
                ];



console.log(solveMaze(matrix1));
  
  
  
var matrix1 = [[1,0,0,0,0],
                [0,1,0,0,0],
                [1,0,0,0,0],
                [0,0,0,0,0],
                [1,1,9,0,0]
                ];



console.log(solveMaze(matrix1));
  
  
    
  
  
  
  
  
  
  
  
  
  
  





 
 
 
 
 
 
 