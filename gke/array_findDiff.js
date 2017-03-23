
/* 

findDifference(
  [3, 6, 8, 12, 4],
  [4, 6, 8, 12]
) =

4 - true
6 - true
8 - true
12 - true


*/


var findDifference = function(sub_arr1, sub_arr2) {
  
  if(sub_arr1 === null || sub_arr2 === null) {
    return null;
  }
  
  if(sub_arr1.length === sub_arr2.length) {
    return null;
  }
  
  var hash_array = [];
  var base_array = [];
  if(sub_arr1.length > sub_arr2.length) {
    
    base_array = sub_arr1;
    hash_array = sub_arr2;
  } else {
    base_array = sub_arr2;
    hash_array = sub_arr1;
  }
  
  //Return null if diff more than 1
  //
  
  var hashObj = {};
  for(var i = 0; i < hash_array.length; i++) {
    
    var cur = hash_array[i];
    
    if(!(cur in hashObj)) {
      hashObj[cur] = true;
    }
  }
  
  //Find the diff elem
  for(var i = 0; i < base_array.length; i++) {
    
    var cur = base_array[i];
    
    if(!(cur in hashObj)) {
      return cur;
    }
  }
  
  return null;

};


var findDifferenceSpaceOptimized1 = function(sub_arr1,
                                             sub_arr2) {
  
  //Blah blah checks
    
  var xorSum = 0;
  
  for(var i = 0; i < sub_arr1.length; i++) {
    xorSum = parseInt(xorSum ^ sub_arr1[i]);
  }
  
    for(var i = 0; i < sub_arr2.length; i++) {
    xorSum = parseInt(xorSum ^ sub_arr2[i]);
  }
 
  return xorSum;
    
}


var findDifferenceSpaceOptimized2 = function(sub_arr1,
                                             sub_arr2) {
  
  //Blah blah checks
    
  var sum = 0;
  
  for(var i = 0; i < sub_arr1.length; i++) {
    sum += sub_arr1[i];
  }
  
    for(var i = 0; i < sub_arr2.length; i++) {
    sum -= sub_arr2[i]
  }
 
  return Math.abs(sum);
    
}


console.log(findDifference([3, 6, 8, 12, 4],
                           [4, 6, 8, 12]));
console.log(findDifference([4, 6, 8, 12], 
                           [3, 6, 8, 12, 4]));
console.log(findDifference([4, 6, 8, 12], 
                           [6, 8, 12, 4]));

console.log("Test 2 function");

console.log(findDifferenceSpaceOptimized1([3, 6, 8, 12, 4],
                           [4, 6, 8, 12]));
console.log(findDifferenceSpaceOptimized1([4, 6, 8, 12], 
                           [3, 6, 8, 12, 4]));
console.log(findDifferenceSpaceOptimized1([4, 6, 8, 12], 
                           [6, 8, 12, 4]));

console.log("Test 3 function");

console.log(findDifferenceSpaceOptimized2([3, 6, 8, 12, 4],
                           [4, 6, 8, 12]));
console.log(findDifferenceSpaceOptimized2([4, 6, 8, 12], 
                           [3, 6, 8, 12, 4]));
console.log(findDifferenceSpaceOptimized2([4, 6, 8, 12], 
                           [6, 8, 12, 4]));






