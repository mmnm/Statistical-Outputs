/* Implement Randomized Quick sort 

[2,7,3,9,5,4,1]



*/


var swapElems = function(sub_arr, source, target) {

	if(sub_arr === null || source < 0 || target >= sub_arr.length) {
		return;
	}

	var temp = sub_arr[source];
	sub_arr[source] = sub_arr[target];
	sub_arr[target] = temp;

}

var partition = function(sub_arr, start, end) {

	if( (sub_arr === null) || (start >= end) ) {
		return -1;
	}

	var randIndex = Math.floor(Math.random() * (end - start + 1)) + start;
	//Swap the randIndex

	swapElems(sub_arr, start, randIndex);

	var i = start;
	var part_elem = sub_arr[start];
	for(var j = start + 1; j <= end; j++) {

		var cur = sub_arr[j];

		if(cur < part_elem) {
			swapElems(sub_arr, i + 1, j);
			i++;
		}

	}

	//Last swap
	swapElems(sub_arr, start, i);
	return i;


}



var quickSortUtil = function(sub_arr, start, end) {

	if(start >= end) {
		return sub_arr;
	}


	var partIndex = partition(sub_arr, start, end);
	if(partIndex === -1) {
		return sub_arr;
	}
	quickSortUtil(sub_arr, start, partIndex - 1);
	quickSortUtil(sub_arr, partIndex + 1, end);

	return sub_arr;

}



var quickSort = function(sub_arr) {

	if(sub_arr === null) {

		return null;
	}

	return quickSortUtil(sub_arr, 0, sub_arr.length - 1);

}


var array1 = [2,7,3,9,5,4,1];
var array2 = [2];
var array3 = [2,7];
var array4 = [7,2];
var array5 = [7,4,1];
var array6 = [1,7,4];
var array7 = [7,1,2,3];
var array8 = [7,3,2,1];
var array9 = [1,2,3,4];

console.log(array1.slice(), "sorting is: ", quickSort(array1));
console.log(array2.slice(), "sorting is: ", quickSort(array2));
console.log(array3.slice(), "sorting is: ", quickSort(array3));
console.log(array4.slice(), "sorting is: ", quickSort(array4));
console.log(array5.slice(), "sorting is: ", quickSort(array5));
console.log(array6.slice(), "sorting is: ", quickSort(array6));
console.log(array7.slice(), "sorting is: ", quickSort(array7));
console.log(array8.slice(), "sorting is: ", quickSort(array8));
console.log(array9.slice(), "sorting is: ", quickSort(array9));



