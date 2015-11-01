var findMaxOccurenceInSortedArray = function(array, num) {
	if(array === undefined || array.length <= 0) {
		return -1;
	}

	var startIndex = findStartIndexInSortedArrayUtil(array, num, 0, array.length - 1);
	if(startIndex === -1) {
		return -1;
	}
	// console.log("start" , startIndex);

	var endIndex = findEndIndexInSortedArrayUtil(array, num, 0, array.length - 1);
	if(startIndex === -1) {
		return -1;
	}
	// console.log("end", endIndex);

	//This is the length of the sequence
	return endIndex - startIndex + 1;



}

var findStartIndexInSortedArrayUtil = function(array, num, low, high) {
	if(low > high) {
		return -1;
	}

	var mid = parseInt((low + high) / 2);

	if(array[mid] === num) {
		
		if((mid === 0) || (array[mid - 1] !== num)) {
			return mid;
		} else {
			return findStartIndexInSortedArrayUtil(array, num, low, mid - 1)
		}

	} else if(array[mid] > num) {
		return findStartIndexInSortedArrayUtil(array, num, low, mid - 1);

	} else if(array[mid] < num) {

		return findStartIndexInSortedArrayUtil(array, num, mid + 1, high);
	}
	
}


var findEndIndexInSortedArrayUtil = function(array, num, low, high) {
	if(low > high) {
		return -1;
	}

	var mid = parseInt((low + high) / 2);

	if(array[mid] === num) {
		
		if((mid === array.length - 1) || (array[mid + 1] !== num)) {
			return mid;
		} else {
			return findEndIndexInSortedArrayUtil(array, num, mid + 1, high)
		}

	} else if(array[mid] > num) {
		return findEndIndexInSortedArrayUtil(array, num, low, mid - 1);

	} else if(array[mid] < num) {

		return findEndIndexInSortedArrayUtil(array, num, mid + 1, high);
	}
	
}


//Test cases

console.log(findMaxOccurenceInSortedArray([1,2,3,3,4,4,4,4,4,4,5,5,6,6,6,6,6,6,7,7,7,7,7,7,7,7,8,8,8,8,9,9], 4));
console.log(findMaxOccurenceInSortedArray([1,2,3,3,4,4,4,4,4,4,5,5,6,6,6,6,6,6,7,7,7,7,7,7,7,7,8,8,8,8,9,9], 9));
console.log(findMaxOccurenceInSortedArray([1,2,3,3,4,4,4,4,4,4,5,5,6,6,6,6,6,6,7,7,7,7,7,7,7,7,8,8,8,8,9,9], 1));

