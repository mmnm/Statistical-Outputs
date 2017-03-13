/* 
Merge routine

Debugging:
1. Ln 30: Mistake of using start > end instead of start >= end
Please remember that merge routine is different than binary search
In binary serach start is guranteed to become less than end
as we are substracting in the recursion stack
In case of merge routine, we are getting mid and recursing, 
hence there is an edge case with infinite recursion:
mid = (0 + 0)/ 2  = 0
infinitely repeating for call (0, mid) recursive call  

*/



var merge_sort = function(sub_arr) {

	if(sub_arr === null || sub_arr.length <= 1) {
		return sub_arr;
	}


	return merge_sortUtil(sub_arr, 0, sub_arr.length - 1);

};


var merge_sortUtil = function(sub_arr, start, end) {

	if(sub_arr === null || sub_arr.length <= 1 || start >= end) { 
		return sub_arr;
	}

	var middle = parseInt((start + end) / 2);
	merge_sortUtil(sub_arr, start, middle);
	merge_sortUtil(sub_arr, middle + 1, end);
	combine(sub_arr, start, middle, middle + 1, end);

	return sub_arr;

};

var combine = function(sub_arr, start1, end1, start2, end2) {

	if(sub_arr === null) {
		return sub_arr;
	}

	var output_arr = [];
	var i = start1;
	var j = start2;

	for(; i <= end1 || j <= end2;) {

		if(i <= end1 && j <= end2) {
			if(sub_arr[i] < sub_arr[j]) {
				output_arr.push(sub_arr[i++]);
			} else {
				output_arr.push(sub_arr[j++]);
			}
		} else if(i <= end1) {
			output_arr.push(sub_arr[i++]);
		} else if(j <= end2) {
			output_arr.push(sub_arr[j++]);
		} else {
			console.log("Debug this: combine");
		}

	}
	var k = start1;
	for(var i = 0; i < output_arr.length; i++) {
		sub_arr[k++] = output_arr[i];
	}

	return output_arr;

}

// Test cases
console.log(merge_sort([10,1,5,2,8,6,9,3,7,4]));
console.log(merge_sort([5,4]));
console.log(merge_sort([5,4, 2]));
console.log(merge_sort([2,3,4]));
console.log(merge_sort([2]));




