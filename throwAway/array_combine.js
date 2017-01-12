/* Combine two sorted arrays */



var combine = function(array1, array2) {


	if(array1 === null || array1 === undefined) {
		return array2;
	}

	if(array2 === null || array2 === undefined) {
		return array1;
	}

	var output_arr = [];

	for(var i = 0, j = 0; i < array1.length || j < array2.length;) {

		if(i < array1.length && j < array2.length) {

			if(array1[i] <= array2[j]) {
				output_arr.push(array1[i++]);
			} else {
				output_arr.push(array2[j++]);
			}
		} else if(i < array1.length) {
			output_arr.push(array1[i++]);
		} else {
			output_arr.push(array2[j++]);
		}

	}

	return output_arr;

}



//Test cases
console.log(combine([3]));
console.log(combine([3], [1]));
console.log(combine([1,2,5,7], [3,9]));
console.log(combine([1,2,5,12], [3,9,11,15]));
console.log(combine([1,2,5,12], [3,9,11,15,17]));


