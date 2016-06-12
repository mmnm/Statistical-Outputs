/* 
K’th Smallest/Largest Element in Unsorted Array | Set 1
Given an array and a number k where k is smaller than size of array, 

we need to find the k’th smallest element in the given array. 
It is given that ll array elements are distinct.

Examples:

Input: arr[] = {7, 10, 4, 3, 20, 15}
       k = 3
Output: 7

Input: arr[] = {7, 10, 4, 3, 20, 15}
       k = 4
Output: 10

*/

var swapElems = function(sub_arr, source, target) {

	if(sub_arr === null) {
		return;
	}

	var temp = sub_arr[source];
	sub_arr[source] = sub_arr[target];
	sub_arr[target] = temp;

}


var partition = function(sub_arr, start, end) {

	if(sub_arr === null || start < 0 || end >= sub_arr.length) {
		return - 1;
	}

	var randIndex = Math.floor(Math.random() * (end - start + 1)) + start;


	swapElems(sub_arr, start, randIndex);

	var i = start;
	var part_item = sub_arr[i];

	for(var j = start + 1; j <= end; j++) {

		var curElem = sub_arr[j];

		if(curElem < part_item) {
			swapElems(sub_arr, i + 1, j);
			i++;
		}

	}
	swapElems(sub_arr, start, i);
	return i;

}


var findKthLargestElement = function(sub_arr, k, start, end) {

	if(sub_arr === null || k < 0 || k > sub_arr.length) {
		return -1;
	}

	if(start > end) {
		return -1;
	}

	var curRankRand = partition(sub_arr, start, end);

	if(curRankRand === -1) {
		console.log("Debug this, no curRankRand returned");
		return;
	}

	if(curRankRand === (k - 1)) {
		return sub_arr[curRankRand];
	} else if(curRankRand < (k - 1)) {
		return findKthLargestElement(sub_arr, k, curRankRand + 1, end);
	} else if(curRankRand > (k - 1)) {
		return findKthLargestElement(sub_arr, k, start, curRankRand - 1);
	} else {
		console.log("Debug this: ");
	}

}




var array1 = [7, 10, 4, 3, 20, 15];
var array2 = [9,3,1,5,2,8,10,6,4, 7];
console.log(findKthLargestElement(array1, 3, 0, array1.length - 1));
console.log(findKthLargestElement(array1, 4, 0, array1.length - 1));

console.log(findKthLargestElement(array2, 1, 0, array2.length - 1));
console.log(findKthLargestElement(array2, 2, 0, array2.length - 1));
console.log(findKthLargestElement(array2, 3, 0, array2.length - 1));
console.log(findKthLargestElement(array2, 4, 0, array2.length - 1));
console.log(findKthLargestElement(array2, 5, 0, array2.length - 1));
console.log(findKthLargestElement(array2, 6, 0, array2.length - 1));
console.log(findKthLargestElement(array2, 7, 0, array2.length - 1));
console.log(findKthLargestElement(array2, 8, 0, array2.length - 1));
console.log(findKthLargestElement(array2, 9, 0, array2.length - 1));
console.log(findKthLargestElement(array2, 10, 0, array2.length - 1));
console.log(findKthLargestElement(array2, 11, 0, array2.length - 1));








