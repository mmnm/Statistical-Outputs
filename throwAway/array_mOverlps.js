/*Merge overlapping intervals

[[6,8], [1,3], [2,4], [5,7]  ]

Debugging: 
1. Always remember reset point 
e.g Ln 58
sub_arr[i++] = prev;
 prev = cur;

 The above line 9  was not present and hence causing issues


*/

var mergeElem = function(elem1, elem2) {
  
  var high = Math.max(elem1[0], elem2[0], 
                      elem1[1], elem2[1]);
  var low = Math.min(elem1[0], elem2[0], 
                      elem1[1], elem2[1]);
  
  return [low,high];
  
}


var mergeOverlapping = function(sub_arr) {

 if(sub_arr === null) {
   return sub_arr;
 }
  
 if(sub_arr.length <= 1) {
   return sub_arr;
 }
  
  //Sort on first element
 sub_arr.sort(function(a1, b1) { return a1[0] - b1[0];});
  
  //Do in place merging 
  var i = 0;
  var prev = sub_arr[i];
  
  var len = sub_arr.length;
  for(var j = 1; j < len; j++) {
   var cur = sub_arr[j];
    
    //Check if overlap and merge
    if(prev[1] >= cur[0]) {
      prev = mergeElem(prev, cur);
      
      if(j === len - 1) {
        sub_arr[i++] = prev;
      }
      
    } else {
      sub_arr[i++] = prev;
      prev = cur;
    }
      
  }
    
  
  //Delete remaining entries
  for(; i < len; i++) {
    delete sub_arr[i];
  }
  

  return sub_arr;
  
};
  

console.log(mergeOverlapping([[1,3], [3,5]]));
console.log(
  mergeOverlapping([[6,8], [1,3], [2,4], [5,7]]));
console.log(
  mergeOverlapping([[6,8], [1,9], [2,4], [4,7]]));
  






