/*
Maximum difference between two elements such that larger element appears after the smaller number
Given an array arr[] of integers, find out the difference between any two elements such that larger 
element appears after the smaller number in arr[].

Examples: If array is [2, 3, 10, 6, 4, 8, 1] then returned value should be 8 
											 1 2 3 4 6 8 10


                                    

(Diff between 10 and 2). If array is [ 7, 9, 5, 6, 3, 2 ] then returned 
			                                 2 3 5 6 7 9
value should be 2 (Diff between 7 and 9)
*/

//Idea 2
//Optimized solution to make the algo O(n)
//Keep track of min_seen till now and process the max_diff seen at each iterative point. The resulting algo is O(N)






var maxDiffSeen = function(sub_array) {

	if(sub_array === null || sub_array === undefined || sub_array.length <= 1) {
		return -1;
	}

	var max_diff_seen = 0;
	var min_num_seen = sub_array[0];
	var len = sub_array.length;
	for(var i = 1; i < len; i++) {

		var cur = sub_array[i];
		var diff = cur - min_num_seen;
		
		if(max_diff_seen < diff) {
			max_diff_seen = diff;
		}

		if(min_num_seen > cur) {
			min_num_seen = cur;
		}


	}

	return max_diff_seen;

}

console.log(maxDiffSeen([2, 3, 10, 6, 4, 8, 1]));
console.log(maxDiffSeen( [7, 9, 5, 6, 3, 2 ]));




