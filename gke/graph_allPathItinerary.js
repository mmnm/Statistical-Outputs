/* 

SFO - DEN
DEN - AUS
AUS - MIA
MIA - SAN
SAN - LOS
LOS - LAS

Find the complete path for this trip


 [["MIA", "SAN"], ["AUS", "MIA"], ["DEN", "AUS"], 
 ["LOS", "LAS"], ["SAN", "LOS"], ["SFO", "DEN"]]
 
 Debug:
 
1. Remember the concat function signature update
If you want to update array use below statement:
array = array.concat(array2) instead of 
array.concat(array2);

2. Keep track of elements that are not to be used
Example, all visited subproblems need not be visited again


*/



var processHashPath = function(sub_arr) {
  
  if(sub_arr === null || sub_arr.length <= 0) {
    return null;
  }
  
   var hashPaths = {};
  for(var i = 0; i < sub_arr.length; i++) {
    var curElem = sub_arr[i];
    
    var key = curElem[0];
    var val = curElem[1];
    
    if(!(key in hashPaths)) {
      hashPaths[key] = val;
    } else {
      console.log("Not supported case yet");
    }
  }
  return hashPaths;
  
}



var findSinglePath = function(hashPaths, start, 
                               uniquePaths) {
  
  var output_path = [];
  var start_copy = start;
  
  if(hashPaths === null || start === null) {
    return output_path;
  }
  
   if((start in uniquePaths) && 
       (uniquePaths[start].length !== 0)) {
      
      return;
  }
  
  while(start !== null) {
    
    if((start in uniquePaths) && 
       (uniquePaths[start].length !== 0)) {
      var remaining_path = uniquePaths[start];
      
      output_path = output_path.concat(remaining_path);
      delete uniquePaths[start];
      break;
      
    }
    
    output_path.push(start);
    delete uniquePaths[start];
    
    if(start in hashPaths) {
      start = hashPaths[start];
    } else {
      start = null;
    }
    
   
  }
   
  uniquePaths[start_copy] = output_path;
  return;
  
};
  
  
var combine_paths = function(uniquePaths) {
  
  var output_arr = [];
  
  if(uniquePaths  === null || Object.keys(uniquePaths).length === 0) {
    return output_arr;
  }

  for(var key in uniquePaths) {
    
    var curPath = uniquePaths[key];
    output_arr = output_arr.concat(curPath);
  }
  
  return output_arr;
  
}
  
  

var findCompletePath = function(sub_arr) {
  
  
  if(sub_arr === null || sub_arr.length <= 0) {
    return;
  }
  var hashPaths = processHashPath(sub_arr);
  
  var uniquePaths = {};
  
  for(var key in hashPaths) {
  
    uniquePaths[key] = [];
  }
  
  //Process all paths to find all unique paths
  for(var key in uniquePaths) {
    
    var curPath = uniquePaths[key];
    
    if(curPath.length === 0) {
      //Find curpath and update uniquePaths for this
      findSinglePath(hashPaths, key, uniquePaths);
    } 
  };
  
  //Now combine all disjoint paths and return
  
  return combine_paths(uniquePaths);
      
      
};


var test_arr1 =  [["MIA", "SAN"], ["AUS", "MIA"], 
                 ["DEN", "AUS"], ["LOS", "LAS"], 
                 ["SAN", "LOS"], ["SFO", "DEN"]];

var test_arr2 =  [["MUM", "DEL"], ["MIA", "SAN"], 
                  ["AUS", "MIA"], ["BER","MUN"], 
                  ["DEL", "HYD"],["DEN", "AUS"], 
                  ["LOS", "LAS"], ["SAN", "LOS"], 
                  ["SFO", "DEN"], 
                  ["GOA","BLR"],["HYD","GOA"]];

console.log("Test case 1: ", findCompletePath(test_arr1));
console.log("Test case 2: ", findCompletePath(test_arr2));
