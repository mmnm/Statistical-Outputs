/* 

Merge overlapping intervals. 
Checkout the algo below and remember debug points:
1. When you are modifying/splicing the current array, always check 
what the next index looks like in a for loop. See below case: i = i - 1
2. When you are modifying elements from array, please dont forget to write 
back in the array. See below case: sub_arr[i - 1] = prevElem;
*/


var mergeIntervals = function(elem1 , elem2) {

	var smallX = Math.min(elem1[0], elem1[1], elem2[0], elem2[1]);
	var bigX = Math.max(elem1[0], elem1[1], elem2[0], elem2[1]);

	return [smallX, bigX];


}

var isOverlap = function(elem1, elem2) {

	if(elem1[1] >= elem2[0]) {
		return true;
	} else {
		return false;
	}

}



var mergOverlapIntervals = function(sub_arr) {


	if(sub_arr === null) {
		return null;
	}

//Now try to sort the sub_arr based on the first elem of the interval, 
//this is required as we are trying to build consecutive overlaps in O(n) time


//This sorts the array based on first elem
sub_arr.sort(function(arr1, arr2) {
	return arr1[0] - arr2[0];
});


// Now progressively merge the overlapping intervals 

var prevElem = sub_arr[0];

for(var i = 1; i < sub_arr.length; i++) {


	var curElem = sub_arr[i];

//Check if this elem is overlapping
if(isOverlap(prevElem, curElem)) {
	var mergedElem = mergeIntervals(prevElem, curElem);
	prevElem = mergedElem;
	sub_arr[i - 1] = prevElem;
	sub_arr.splice(i, 1);
	i--;

} else {
	prevElem = curElem;
}

}

return sub_arr;
};




// Test cases
var input_arr1 = [[5,7], [1,3], [2,4],  [6,8]];


var input_arr2 = [
[10,12],
[4,8],
[3,5],
[9,10],
[0, 1]

];

// console.log(mergOverlapIntervals(input_arr1));
console.log(mergOverlapIntervals(input_arr2));





