/* Given the array of IDs, which contains many duplicate integers and one 
unique integer, find the unique integer.

Example 
arr1 = {2, 3, 7, 9, 11, 2, 3, 11, 7};
output : 9


*/



var findNonRepeated_usingMap = function(array1) {


	if(array1 === undefined || array1 === null) {
		return null;
	}


	var hashMap = {};

	for(var i = 0; i < array1.length; i++) {
		var curElem = array1[i];

		if(curElem in hashMap) {
			hashMap[curElem] = true;
		} else {
			hashMap[curElem] = false;
		}

	}

	//Now return the element non - repeated while will have false as hashMap

	for(var key in hashMap) {
		if(hashMap[key] === false) {
			return key;
		}
	}


	return null;

}

var array1 = [2, 3, 7, 9, 11, 2, 3, 11, 7];
console.log(findNonRepeated_usingMap(array1));


var array2 = [2, 3, 7, 9, 12, 11, 2, 3, 11, 7, 9];
console.log(findNonRepeated_usingMap(array2));


var array3 = [2,2];
console.log(findNonRepeated_usingMap(array3));


var array4 = [2];
console.log(findNonRepeated_usingMap(array4));
