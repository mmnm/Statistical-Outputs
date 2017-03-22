/* merge two sorted lists */


var mergeLists = function(sub_arr1, sub_arr2) {

	if(sub_arr2 === null) {
		return sub_arr1;
	}
	
	if(sub_arr1 === null) {
		return sub_arr2;
	}

	var output_arr = [];

	for(var i = 0, j = 0; i < sub_arr1.length || j < sub_arr2.length;) {

		if(i < sub_arr1.length && j < sub_arr2.length) {
			if(sub_arr1[i] < sub_arr2[j]) {
				output_arr.push(sub_arr1[i++]);
			} else {
				output_arr.push(sub_arr2[j++]);
			}
		} else if(i < sub_arr1.length) {
			output_arr.push(sub_arr1[i++]);
		} else if(j < sub_arr2.length) {
			output_arr.push(sub_arr2[j++]);
		} else {
			console.log("Debug this: mergeLists");
		}

	}

	return output_arr;


};

console.log(mergeLists([1,2], [3,4,5]));
console.log(mergeLists([2,3], [1]));
console.log(mergeLists([1,3,5], [2,4,6]));
console.log(mergeLists([1,3], [2,4,6]));
console.log(mergeLists([1,3], [2,4,6,8,10]));









