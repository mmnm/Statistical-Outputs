/*

Merge Overlapping Intervals
Given a set of time intervals in any order, 
merge all overlapping intervals into one and output the result 
which should have only mutually exclusive intervals. Let the intervals 
be represented as pairs of integers for simplicity. 
For example, let the given set of intervals be
 {{6,8}, {1,3}, {2,4}, {5,7} } 
 The intervals {1,3} and {2,4} overlap with each other, 
 so they should be merged and become {1, 4}. 
 Similarly {5, 7} and {6, 8} should be merged and become {5, 8}
*/




var mergedIntervals = function(int1, int2) {

	var x1 = int1[0];
	var x2 = int2[0];
	var y1 = int1[1];
	var y2 = int2[1];

	var merged = [];
	merged.push(Math.min(x1, x2));
	merged.push(Math.max(y1, y2));


	return merged;


}


var mergeOverlappingIntervals = function(sub_array) {


	if(sub_array === null) {

		return null;
	}

	//Sort the array based on the first interval


	sub_array.sort(function(int1, int2) { return int1[0] - int2[0]});


	for(var i = 1; i < sub_array.length; ) {

		var prevInt = sub_array[i - 1];
		var curInt = sub_array[i];

		//Overlap not possible
		if(prevInt[1] < curInt[0]) {
			i++;
			continue;
		} else {

			var merged = mergedIntervals(prevInt, curInt);
			sub_array[i - 1] = merged; 
			sub_array.splice(i, 1);
			
		}

	}


	return sub_array;


}

var array1 =  [[6,8], [1,3], [2,4], [5,7] ] ;
console.log(mergeOverlappingIntervals(array1));









