/* 

Minimum number of jumps to reach end
Given an array of integers where each element 
represents the max number of steps that can be made forward from that 
element. Write a function to return the minimum number of jumps to reach 
the end of the array (starting from the first element). If an element is 0, 
then cannot move through that element.

Example:

Input: arr[] = {1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9}
Output: 3 (1-> 3 -> 8 ->9)

start with curIndex 

From this 
	traverse all its neighbors countSteps

	if countSteps + 1 < minSeen ; update minSeen;

	*/




	var minJumps = function(sub_array, startIndex) {

		if(sub_array === null) {
			return -1;
		}

		if(startIndex === sub_array.length - 1) {
			return 0;
		}

		var minSteps = Number.MAX_VALUE;

		var maxSteps = sub_array[startIndex];

		for(var i = startIndex + 1; (i <= (startIndex + maxSteps)) && 
			(i < sub_array.length); i++) {

			var curMinStep = minJumps(sub_array, i);

		if((curMinStep + 1) < minSteps) {
			minSteps = curMinStep + 1;
		}

	}

	return minSteps;

}

var array1 = [1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9];
console.log("Minimum steps: ", minJumps(array1, 0));



