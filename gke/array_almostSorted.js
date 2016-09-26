/* Insertion sort 


[5, 6, 1, 8, 2, 9, 3]

Algo Have two for loops (i, j)
At each step place the jth element in the correct order


This algo works well if the elements are almost sorted and / or if each elem is
 atmost k elements to its original sorted position, in that case Time complexity will be O(n * k), 
 and since k is constant; it will be O(n)

*/

var insertionSort = function(sub_arr) {


	if(sub_arr === null) {

		return null;
	}

	for(var i = 1; i < sub_arr.length; i++) {

		var curElem = sub_arr[i];
		var j = 0;

		for(j = i - 1;; j--) {
			
			if(j < 0) {
				break;
			}
			if(sub_arr[j] > curElem) {
				sub_arr[j + 1] = sub_arr[j];
			} else {
				break;
			}
		}

		sub_arr[j + 1] = curElem;

	}

	return sub_arr;

}

// Test cases

var array1 = [4, 6, 5, 8, 2, 9, 3];
var array2 = [1,2,3,4,5,6,7,8,9];
var array3 = [1];
var array4 = [1,2];
var array5 = [2,1];
var array6 = [1,3,2];
var array7 = [1,3,2,7];
var array8 = [7,1,3,2];
var array9 = [7,7,3,2];
var array10 = [3,2,1];

console.log(insertionSort(array1));
console.log(insertionSort(array2));

console.log(insertionSort(array3));
console.log(insertionSort(array4));

console.log(insertionSort(array5));
console.log(insertionSort(array6));

console.log(insertionSort(array7));
console.log(insertionSort(array8));

console.log(insertionSort(array9));
console.log(insertionSort(array10));


