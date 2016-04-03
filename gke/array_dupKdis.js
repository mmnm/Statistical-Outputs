/*
Check if a given array contains duplicate elements within k distance from each other
Given an unsorted array that may contain duplicates.
 Also given a number k which is smaller than size of array. 
 Write a function that returns true if array 
 contains duplicates within k distance.

Examples:

Input: k = 3, arr[] = {1, 2, 3, 4, 1, 2, 3, 4}
Output: false
All duplicates are more than k distance away.

Input: k = 3, arr[] = {1, 2, 3, 1, 4, 5}
Output: true
1 is repeated at distance 3.

Input: k = 3, arr[] = {1, 2, 3, 4, 5}
Output: false

Input: k = 3, arr[] = {1, 2, 3, 4, 4}
Output: true


*/


/*

Idea is to keep a rolling hash which will keep track of the current k window, roll the window to see if there is any dup
Return false on any such occurrence

*/


var checkDupInArrayWithinK = function(sub_arr, k) {

	if(sub_arr === null) {
		return -1;
	}
 	k = k + 1;

 //Zero window
 if(k <= 0) {
 	return false;
 }

 var hashForKElems = {};

 if(k > sub_arr.length) {
 	k = sub_arr.length;
 }

 //Build for first window - k

 for(var i = 0; i < k; i++) {
 	var curElem = sub_arr[i];
 	
 	if(curElem in hashForKElems) {
 		return true;
 	}

 	hashForKElems[curElem] = true;
 }

//Now roll the k window
for(var i = 1; i < (1 + sub_arr.length - k); i++) {
	//Remove the first element from the sliding hash and add the new hash
	delete hashForKElems[sub_arr[i - 1]];

	var curElem = sub_arr[i + k - 1];

	if(curElem in hashForKElems) {
 		return true;
 	}

 	hashForKElems[curElem] = true;


}

return false;

}


var arr1 = [1, 2, 3, 4, 1, 2, 3, 4];
console.log(checkDupInArrayWithinK(arr1, 3));

// Output: false
// All duplicates are more than k distance away.

var arr2 = [1, 2, 3, 1, 4, 5];

console.log(checkDupInArrayWithinK(arr2, 3));
// Output: true
// 1 is repeated at distance 3.

var arr3 = [1, 2, 3, 4, 5];
console.log(checkDupInArrayWithinK(arr3, 3));
// Output: false

var arr4 = [1, 2, 3, 4, 4];
console.log(checkDupInArrayWithinK(arr4, 3));
// Output: true











