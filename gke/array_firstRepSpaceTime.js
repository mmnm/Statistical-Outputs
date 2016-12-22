
/* 
Given a string, find its first non-repeating character
Given a string, find the first non-repeating character in it. 

*/

//The below solution is T = O(2n), Space = O(n) 
var findFirstNonRepeated_soln1 = function(sub_arr) {

	if(sub_arr === null || sub_arr.length <= 0) {
		return null;
	}


	var hashCount = {};

	for(var i = 0; i < sub_arr.length; i++) {

		var curElem = sub_arr[i];

		if(curElem in hashCount) {
			hashCount[curElem]++;
		} else {
			hashCount[curElem] = 1;
		}

	}


	for (var i = 0; i < sub_arr.length; i++) {
		var curElem = sub_arr[i];
		if(hashCount[curElem] === 1) {
			return curElem;
		}
	}

	return null;

}


//The below solution is T = O(n), Space = O(2n) 
var findFirstNonRepeated_soln2 = function(sub_arr) {

	if(sub_arr === null || sub_arr.length <= 0) {
		return null;
	}


	var hashCount = {};
	var firstIndexSeenChar = {};
	var onlySeenOnceHash = {};


	for(var i = 0; i < sub_arr.length; i++) {

		var curElem = sub_arr[i];

		if(curElem in hashCount) {
			hashCount[curElem]++;

			if(curElem in onlySeenOnceHash) {
				delete firstIndexSeenChar[onlySeenOnceHash[curElem]];
				delete onlySeenOnceHash[curElem];
			}

		} else {
			hashCount[curElem] = 1;
			onlySeenOnceHash[curElem] = i;
			firstIndexSeenChar[i] = curElem;

		}

		if(i === sub_arr.length - 1) {
 			//Return the first char which is non - repeated
 			//In chrome object are sorted by keys for numbers, (BST store)
 			//Sort if required for other use cases

 			for(var key in firstIndexSeenChar) {
 				return firstIndexSeenChar[key];
 			}
 		}


 	}



 	return null;

 }


//Test case 1
console.log(findFirstNonRepeated_soln1("TeeksforTeeks".split('')));

//Test case 2
console.log(findFirstNonRepeated_soln1("TeeksQuiz".split('')));




//Test case 1 - Time Optimized
console.log(findFirstNonRepeated_soln2("TeeksforTeeks".split('')));

//Test case 2 - Time Optimized
console.log(findFirstNonRepeated_soln2("TeeksQuiz".split('')));









