


/*


Find the 5th largest element in an array of unsorted elements


how does quick sort work



5 4 8 4 5 5 6 7 7 7 7 8 8 8 8 
i
j




*/


var isValidRange = function(arr, elem) {

  if(arr == null || elem < 0 || elem >= arr.length) {
    return false;
  }
  return true;

};

var swapElems = function(arr, index1, index2) {

  var temp = arr[index1];
  arr[index1] = arr[index2];
  arr[index2] = temp;

}

var swapRandomIndex = function(arr, start, end) {

  if(arr === null) {
    return;
  }

  if(start >= end) {
    return;
  }

  var rand_index = Math.floor(Math.random() * (end - start + 1)) + start;

  swapElems(arr, start, rand_index);

}

var partition = function(arr, start, end) {

  if(arr === null || start > end) {
    return -1;
  }

//Choose a random partition index in between start and end
swapRandomIndex(arr, start, end);

//Now partition based on start index
var i = start;
var part_item = arr[start];

for(var j = i + 1; j <= end; j++) {

  if(part_item >= arr[j]) {
    swapElems(arr, i + 1, j);
    i++;
  }
}

//Last swap
swapElems(arr, i, start);

return i;

}


var findKLargestElemUtil = function(arr, start, end, k) {

  if(arr === null || !isValidRange(arr, k - 1)) {
    return null;
  }

  var part_rank = partition(arr, start, end);

  if(part_rank === -1) {
// console.log("Debug this", start, " ", end);
return null;
}

if(part_rank === k - 1) {

  return arr[part_rank];

} else if( part_rank > k - 1) {
  return findKLargestElemUtil(arr, start, part_rank - 1, k);
} else {
  return findKLargestElemUtil(arr, part_rank + 1, end, k);
}


};

var findKLargestElem = function(arr, k) {

  if(arr === null) {
    return null;
  }

  return findKLargestElemUtil(arr, 0, arr.length - 1, k); 

}



var arr1 = [5,3,6,10,2,9,1,8,7,4];
var arr2 = [1,2,3,4,5,6,7,8,9];
var arr3 = [9,8,7,6,5,4,3,2,1];


console.log(findKLargestElem(arr1, 1));
console.log(findKLargestElem(arr1, 2));
console.log(findKLargestElem(arr1, 3));
console.log(findKLargestElem(arr1, 4));
console.log(findKLargestElem(arr1, 5));
console.log(findKLargestElem(arr1, 6));
console.log(findKLargestElem(arr1, 7));
console.log(findKLargestElem(arr1, 8));
console.log(findKLargestElem(arr1, 9));
console.log(findKLargestElem(arr1, 10));
console.log(findKLargestElem(arr1, 11));

console.log("\n");

console.log(findKLargestElem(arr2, 1));
console.log(findKLargestElem(arr2, 2));
console.log(findKLargestElem(arr2, 3));
console.log(findKLargestElem(arr2, 4));
console.log(findKLargestElem(arr2, 5));
console.log(findKLargestElem(arr2, 6));
console.log(findKLargestElem(arr2, 7));
console.log(findKLargestElem(arr2, 8));
console.log(findKLargestElem(arr2, 9));
console.log(findKLargestElem(arr2, 10));


console.log("\nYYYY");

console.log(findKLargestElem(arr3, 1));
console.log(findKLargestElem(arr3, 2));
console.log(findKLargestElem(arr3, 3));
console.log(findKLargestElem(arr3, 4));
console.log(findKLargestElem(arr3, 5));
console.log(findKLargestElem(arr3, 6));
console.log(findKLargestElem(arr3, 7));
console.log(findKLargestElem(arr3, 8));
console.log(findKLargestElem(arr3, 9));
console.log(findKLargestElem(arr3, 10));


