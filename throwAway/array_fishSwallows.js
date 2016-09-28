

/* Find then k largest element in the n element array 

Use the partition routine to try the k compare and return when found 

T(n) = T(n/2) + O(1)


[1,2,7,9,1,5,11]
i          j

[4,1,5,2,3,7,8,9]
i j



*/


var kLargestElem = function(sub_arr, k) {

	if(sub_arr === null || k <= 0 || k > sub_arr.length) {
		return null;
	}

	return kLargestElem(sub_arr, k, 0, sub_arr.length - 1);


}



var partition = function(sub_arr, start, end) {

	if(sub_arr === null || start > end) {
		return -1;
	}

	if(start === end) {
		return start;
	}

//Partition based on the pivot which is the elem at the start
//You may randomize this 

var pivot_elem = sub_arr[start];

var i = start;

for(var j = start + 1; j <= end; j++) {

	if(sub_arr[j] < pivot_elem) {
		var temp = sub_arr[i + 1];
		sub_arr[i + 1] = sub_arr[j];
		sub_arr[j] = temp; 
		i++;
	}

}


}


var kLargestElemUtil = function(sub_arr, k, start, end) {


	if(sub_arr === null || k <= 0 || k > sub_arr.length || start > end) {
		return null;
	}


	var partIndex = partition(sub_arr, start, end);

	if(partIndex === -1) {
		console.log("Debug this");
		return null;
	}

	if(partIndex === (k - 1)) {
		return sub_arr[partIndex];
	} else if(partIndex > (k - 1)) {
		return kLargestElemUtil(sub_arr, k, start, partIndex - 1);
	} else {
		return kLargestElemUtil(sub_arr, k, partIndex + 1, end);
	}

}



var array1 = [2,9,8,1,3,5,6,7,10,4];

console.log(kLargestElem(array1,5));








