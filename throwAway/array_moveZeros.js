/* Move all zeros to end*/


var moveZerosToEnd = function(sub_arr) {
  
 if(sub_arr === null || sub_arr.length <= 0) {
   return sub_arr;
 }
  
 var i = 0;
  
 for(var j = 0; j < sub_arr.length; j++) {
  var curElem = sub_arr[j];
   
   if(curElem !== 0) {
     sub_arr[i++] = curElem;
   } 
 }
  
 for(; i < sub_arr.length; i++) {
   
   sub_arr[i] = 0;
 }
  
  return sub_arr;
  
  
}

console.log(moveZerosToEnd([1,2,0,0,3,5,0,9,0]));
console.log(moveZerosToEnd([0,0,0,0,1,2,3,4,5]));
console.log(moveZerosToEnd([1,2,3,4,5]));
console.log(moveZerosToEnd([0,0]));









