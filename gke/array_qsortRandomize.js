// Randomize QSort



var swap = function(arr, index1, index2) {

	var temp = arr[index1];
	arr[index1] = arr[index2];
	arr[index2] = temp;

}

var randomizePivot = function(arr, start , end) {

	var index = Math.floor((Math.random() * end) + start);
	swap(arr, start, index);

}

var partition = function(arr, start, end) {

	randomizePivot(arr, start, end);
	var pivotElem = arr[start];

	var i = start;
	for(var j = start + 1; j <= end; j++) {

		if(arr[j] < pivotElem) {
			swap(arr, i + 1, j);
			i++;
		}

	}



	//Last swap is with pivot
	swap(arr, i, start);
	return i;

}



var QuicksortUtil = function(arr, start, end) {

	if(arr === null || (start >= end)) {
		return arr;
	}

	// partionElemIndex(arr, start, end);
	var pivotIndex = partition(arr, start, end);

	QuicksortUtil(arr, start, pivotIndex - 1);
	QuicksortUtil(arr, pivotIndex + 1, end);

	return arr;

}




var Quicksort = function(arr) {

	if(arr === null) {
		return null;
	}

	return QuicksortUtil(arr, 0, arr.length - 1);


}


// Test cases
console.log(Quicksort([2,5,1,9,6,3,8,10,4,7]));
console.log(Quicksort([2,5]));
console.log(Quicksort([5,2]));
console.log(Quicksort([5]));
console.log(Quicksort([5,2,1]));
console.log(Quicksort([5,7,9]));
console.log(Quicksort([]));


