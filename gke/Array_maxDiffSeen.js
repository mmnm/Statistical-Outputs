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

//Idea 1
//I have no idea for best solution  at this moment - Lets just do worst case solution O(n2)
//Traverse through the array and keep max_diff_seen in forward direction






var maxDiffSeen = function(sub_array) {

	if(sub_array === null || sub_array === undefined || sub_array.length <= 1) {
		return -1;
	}

	var max_diff_seen = 0;
	var len = sub_array.length;
	for(var i = 0; i < len - 1; i++) {

			var cur_elem = sub_array[i];

			for(var j = i + 1; j < len; j++) {
				var diff = sub_array[j] - cur_elem;

				if(max_diff_seen < diff) {
					max_diff_seen = diff;
				}
			}

	}

	return max_diff_seen;

}
//Time complexity of the above implementation is O(n*n)


console.log(maxDiffSeen([2, 3, 10, 6, 4, 8, 1]));
console.log(maxDiffSeen( [7, 9, 5, 6, 3, 2 ]));




