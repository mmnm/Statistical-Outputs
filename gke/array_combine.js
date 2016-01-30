/* Write a combine routine for sorted lists */
// Input:[2,6] , [3,4,9,11]

//Walk through
// [2,6] 
//      i

// [3,4,9,11]
//      j

// output_list
// 2 3 4 6 9 11


// Output: [2, 3, 4, 6, 9, 11]




var combineLists = function(list1, list2) {


	if(list1 === (null || undefined) && list2 === (null || undefined) ) {
		return;
	} else if(list1 === (null || undefined) ) {
		return list2;
	} else if(list2 === (null || undefined) )  {
		return list1;
	}

	var output_list = [];

	for(var i = 0, j = 0; i < list1.length && j < list2.length;) {

		//Determine if one list is ended
		if(list1[i] > list2[j]) {
			output_list.push(list2[j++]);
		} else {
			output_list.push(list1[i++]);
		}

	}

	while (i < list1.length) {
		output_list.push(list1[i++]);
	}

	while(j < list2.length) {
		output_list.push(list2[j++]);
	}

	return output_list;

} 

//Test cases
console.log(combineLists([2,6], [3,4,9,11]));
console.log(combineLists([2,6]));
console.log(combineLists([6], [2]));


