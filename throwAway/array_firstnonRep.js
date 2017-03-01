
/* 
Given a string, find its first non-repeating character
*/


/* Method 1

2 pass, O(n) Time, O(n) Space
*/


var findfirstNonRepeated = function(sub_str) {

	var charSeen = {};


	for(var i = 0; i < sub_str.length; i++) {

		var curElem = sub_str[i];

		if(curElem in charSeen) {
			charSeen[curElem]++;
		} else {
			charSeen[curElem] = 1;
		}

	}

	for(var i = 0; i < sub_str.length; i++) {
		var curElem = sub_str[i];
		if(charSeen[curElem] === 1) {
			return curElem;
		}
	}

	return null;

}

/* Method 2

1 pass, O(n) Time, O(2n) Space
*/

var findfirstNonRepeated_onepass = function(sub_str) {


	var hashCount = {};
	// Some arbit number signifying relative time stamps
	var startCounter = 10;

	var isSeenOnceMap = new Map();

	for(var i = 0; i < sub_str.length; i++) {
		var curElem = sub_str[i];

		if(curElem in hashCount) {
			//Get timestamp id of curElem and delete form isSeenOnceMap
			var isSeenId = hashCount[curElem];

			isSeenOnceMap.delete(isSeenId);

		} else {
			//This is the first time
			hashCount[curElem] = startCounter;
			isSeenOnceMap.set(startCounter, curElem);
			startCounter++;
		}

	}
	// debugger;
	for(var [key,value] of isSeenOnceMap.entries()) {
		return value;
	}

}


//Test cases Function 1
console.log(findfirstNonRepeated_onepass("abbbcdddccefgh".split('')));
console.log(findfirstNonRepeated_onepass("abbbcdddccefagh".split('')));
console.log(findfirstNonRepeated_onepass("bgh".split('')));
console.log(findfirstNonRepeated_onepass("bbbggh".split('')));





//Test cases Function 2
console.log(findfirstNonRepeated("abbbcdddccefgh".split('')));
console.log(findfirstNonRepeated("abbbcdddccefagh".split('')));
console.log(findfirstNonRepeated("bgh".split('')));
console.log(findfirstNonRepeated("bbbggh".split('')));




