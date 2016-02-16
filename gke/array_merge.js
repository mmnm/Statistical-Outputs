// Merge subroutine


var combineLists = function(sub_array, start, mid, end) {

	if( (start >= end) || ((mid > end) || (mid < start)) ){

		return sub_array;
	}

	var list1 = [];
	var list2 = [];
	//Copy lists
	var key = 0; 
	for(var i = start; i <= mid; i++) {
		list1[key++] = sub_array[i];
	}
	
	key = 0; 
	for(var j = mid + 1; j <= end; j++) {
		list2[key++] = sub_array[j];
	}

	//Combine the lists now
	i = 0; 
	j = 0;
	while( (i < list1.length) || (j < list2.length) ) {

		if((i < list1.length) && (j < list2.length)) {

			if(list1[i] < list2[j]) {
				sub_array[start++] = list1[i++];
			} else {
				sub_array[start++] = list2[j++];
			}

		} else if((i < list1.length)) {
			sub_array[start++] = list1[i++];
		} else if((j < list2.length)) {
			sub_array[start++] = list2[j++];
		}

	}

	return sub_array;

}



var mergeSortUtil = function(sub_array, start, end) {

	if(sub_array === undefined || start >= end) {
		return sub_array;
	}

	var mid = parseInt((start + end) / 2);

	mergeSortUtil(sub_array, start, mid);
	mergeSortUtil(sub_array, mid + 1, end);

	return combineLists(sub_array, start, mid, end);

}



var mergeSort = function(sub_array) {

	if(sub_array === undefined || sub_array.length <= 0) {
		return sub_array;
	}

	return mergeSortUtil(sub_array, 0, sub_array.length - 1);

}

// Test cases
console.log(mergeSort([10,9,8,3,2,5,11,14]));
console.log(mergeSort([10,9,8,7,6,5,4,3,2,1]));
console.log(mergeSort([1,2]));
console.log(mergeSort([10]));
console.log(mergeSort([2,1]));
console.log(mergeSort([]));


