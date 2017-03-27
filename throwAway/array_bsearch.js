
/* Debugging mistakes 
1. While modularizing as utils, all params were not
passed correctly.
2. in recursion scope, incorrect function name was 
used. *_utils was not used. 

*/



var bin_search_util = function(sub_arr, start, end, elem) {
  
  if(sub_arr === null || sub_arr.length <= 0 ||
     start > end) {
    return -1;
  }
  
  var mid = parseInt((start + end) / 2);
  
  var curElem = sub_arr[mid];
  
  if(curElem === elem) {
    return mid;
  } else if(curElem  < elem) {
    return bin_search_util(sub_arr, mid + 1, end, elem);
  } else {
    return bin_search_util(sub_arr, start, mid - 1, elem);
  }
  
  return null;
};

var bin_search = function(sub_arr, elem) {
 
  if(sub_arr === null) {
    return -1;
  }
  return bin_search_util(sub_arr, 0, sub_arr.length - 1,
                         elem);
  
};

console.log(bin_search([1,2,3,4,5,6,7,8,9,10], 1));
console.log(bin_search([1,2,3,4,5,6,7,8,9,10], 2));
console.log(bin_search([1,2,3,4,5,6,7,8,9,10], 3));
console.log(bin_search([1,2,3,4,5,6,7,8,9,10], 4));
console.log(bin_search([1,2,3,4,5,6,7,8,9,10], 5));
console.log(bin_search([1,2,3,4,5,6,7,8,9,10], 6));
console.log(bin_search([1,2,3,4,5,6,7,8,9,10], 7));
console.log(bin_search([1,2,3,4,5,6,7,8,9,10], 8));
console.log(bin_search([1,2,3,4,5,6,7,8,9,10], 9));
console.log(bin_search([1,2,3,4,5,6,7,8,9,10], 10));
console.log(bin_search([1,2,3,4,5,6,7,8,9,10], 11));
console.log(bin_search([1,2,3,4,5,6,7,8,9,10], 0));


