/* Find element index in sorted rotated
If not present then return -1*/



var findRotatedIndex = function(sub_arr, start, end) {
  
  if(sub_arr === null || sub_arr.length <= 0) {
    return -1;
  }
  
  if(start > end) {
    return -1;
  }
  var mid = parseInt((start + end) / 2);
  
  if(mid === sub_arr.length - 1) {
    return -1;
  }
  
  if(sub_arr[mid + 1] < sub_arr[mid]) {
    return mid + 1;
  } else if(sub_arr[start] < sub_arr[mid]) {
    return findRotatedIndex(sub_arr, mid + 1, end);
  } else {
    return findRotatedIndex(sub_arr, start, mid - 1);
  }
  
}

var binSearchUtil = function(sub_arr, target, start, end) {
  
 if(start > end) {
   return -1;
 }
  
 var mid = parseInt((start + end) / 2);
  if(sub_arr[mid] === target) {
    return mid;
  } else if( sub_arr[mid] < target) {
    return binSearchUtil(sub_arr, target, mid + 1, end);
  } else {
    return binSearchUtil(sub_arr, target, start, mid - 1);
  }
  
  
}

var find_element_index = function(sub_arr, target) {
  
  if(sub_arr === null) {
    return -1;
  }
  
  if(sub_arr.length <= 0) {
    return -1;
  }
  
  var len = sub_arr.length;
  
  var rot_index = findRotatedIndex(sub_arr, 0, len - 1);
  
  //Not rotated
  if(rot_index === -1) {
    return binSearchUtil(sub_arr, target, 0, len - 1);
  }
  
  //Do two bin searches
  var ret_index = 
      binSearchUtil(sub_arr, target, 0, rot_index - 1);
  
    if(ret_index !== -1) {
    return ret_index;
  }
  
  return binSearchUtil(sub_arr,target, rot_index, len - 1);
  
}

console.log(find_element_index([3,4,5,1,2], 3));
console.log(find_element_index([3,4,5,1,2], 4));
console.log(find_element_index([3,4,5,1,2], 5));
console.log(find_element_index([3,4,5,1,2], 1));
console.log(find_element_index([3,4,5,1,2], 2));

console.log(find_element_index([1,2,3,4,5], 3));
console.log(find_element_index([1,2,3,4,5], 4));
console.log(find_element_index([1,2,3,4,5], 5));
console.log(find_element_index([1,2,3,4,5], 1));
console.log(find_element_index([1,2,3,4,5], 2));

console.log(find_element_index([5,1,2,3,4], 1));
console.log(find_element_index([5,1,2,3,4], 2));
console.log(find_element_index([5,1,2,3,4], 3));
console.log(find_element_index([5,1,2,3,4], 4));
console.log(find_element_index([5,1,2,3,4], 5));

console.log(find_element_index([2,3,4,5,1], 1));
console.log(find_element_index([2,3,4,5,1], 2));
console.log(find_element_index([2,3,4,5,1], 3));
console.log(find_element_index([2,3,4,5,1], 4));
console.log(find_element_index([2,3,4,5,1], 5));