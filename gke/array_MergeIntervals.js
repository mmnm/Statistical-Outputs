//Merge overlap sets

// // [[1, 3], [2, 9], [10, 11]] => [[1, 9], [10, 11]] =>
//      i  j    k l     m n
//      1 - 3   2 - 9   1  9  10 11
//      2 - 3   2 - 9
//      3 - 5   2 -9    2 - 9

//Assumption x < y for each set
//Debug: Please assign values out of loop to correct data type
//Made a debug error assigning set_array[i] at line 70 to merge_set instead of cur_set




var mergeSets = function(x1, x2, x3, x4) {
	var min = Math.min(x1, x2, x3, x4);
	var max = Math.max(x1, x2, x3, x4);

	var output_arr = [];
	output_arr.push(min, max);
	return output_arr;

}

var isDisjointSets = function(set1, set2) {

	if(set1 === null || set2 === null) {
		return true;
	}

	if(set1[1] < set2[0]) {
		return true;
	} else {
		return false;
	}

}


var mergeOverLapSets = function(set_array) {


	if(set_array === null || set_array.length <= 1) {
		return set_array;
	}

	//Sort step
	set_array.sort(function(interval1, interval2) {
		return interval1[0] - interval2[0];
	});



	for(var i = 0; i < set_array.length - 1; i++) {

		var cur_set = set_array[i];

		for(var j = i + 1; j < set_array.length; j++) {

			var merge_set = set_array[j]; 
			if(isDisjointSets(cur_set, merge_set) === true) {
				break;
			}

			cur_set = mergeSets(cur_set[0], cur_set[1], merge_set[0], merge_set[1]);
			set_array.splice(j, 1);
			j = j - 1;
		}
		set_array[i] = cur_set;

	}


	return set_array;

}

/*
len - 3
   0        1        2
[[1, 3], [2, 9], [10, 11]]
  i
           j

     [1,9]


*/


console.log(mergeOverLapSets([[1, 3], [2, 9], [10, 11]]));



