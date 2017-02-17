
var mergeSortedLists = function(list1, list2) {
	
	if(list1 === null) {
		return list2;
	}

	if(list2 === null) {
		return list1;
	}

	var output_list = [];

	var i = 0;
	var j = 0;

	for(; i < list1.length || j < list2.length;) {

		if(i < list1.length && j < list2.length) {
			if(list1[i] < list2[j]) {
				output_list.push(list1[i++]);
			} else {
				output_list.push(list2[j++]);
			}
		} else if(i < list1.length) {
			output_list.push(list1[i++]);
		} else if(j < list2.length) {
			output_list.push(list2[j++]);
		} else {
			console.log("mergeSortedLists: Debug this");
		}

	}

	return output_list;

}


console.log(mergeSortedLists([1,5,7,9], [2,4,6]));
console.log(mergeSortedLists([1,5,7], [2,4,6]));
console.log(mergeSortedLists([1,2,3], [4,5,6]));
console.log(mergeSortedLists([], [4,5,6]));
console.log(mergeSortedLists([8], [4,5,6]));
console.log(mergeSortedLists([4,5,6], [1]));
console.log(mergeSortedLists([1,9], [2,4,6]));
