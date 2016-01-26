/* Write a program to print all anagrams in one line
Given a sequence of words, print all anagrams together 
Input: {“cat”, “dog”, “tac”, “god”, “act”}
Output:  “cat tac act" 
         "dog god”

         */


/*
Think about it what are the things that come to your mind??

solution 1:
sort all individual strings chars in first pass 
sort strings in 2nd pass
print in line all the same strings 

Time Complexity 
O(nlogn)

solution 2
hashing solution - create hashes of all characters, group indexes belonging to same hash group
print all group belonging to same hash group

*/
//A prime number
var q = 101;
//Base system for characters
var b = 256;

var createHashSum = function(text) {
	
	if(text === undefined || text.length === 0) {
		return -1;
	}
	var HashSum = 0;
	var m = text.length;

	//Create hash code based on Rabin-Karp
	for(var i = 0; i < m; i++) {
		HashSum = parseInt(( HashSum * b + text[i].charCodeAt(0) ) % q);
	}
	
	return HashSum;
	
}


var printAllAnagramsInLine = function(strings) {

	//Create hashes for characters as well group them if a hash is previously seen

	if((strings === null) || (strings.length === 0)) {
		return;
	}

	var stringsCopy = strings.slice();

	//Sort the chars in the string in strings
	for (var i = 0; i < strings.length; i++) {
		var cur = strings[i].split('').sort().join('');
		strings[i] = cur;
	};

	//Create a hashTable for the sums
	var hashElems = {};

	for(var i = 0; i < strings.length; i++) {
		var curElem = strings[i];
		var curCopyElem = stringsCopy[i];
		var hashForCur = createHashSum(curElem);

		if(hashForCur in hashElems) {
			var curArr = hashElems[hashForCur];
			curArr.push(curCopyElem);

		} else {

			var curArr = [];
			curArr.push(curCopyElem);
			hashElems[hashForCur] = curArr;
		}

	}


	for(var key in hashElems) {
		var curElem = hashElems[key];
		var output_str = "";
		for(var j = 0; j < curElem.length; j++) {
			output_str = output_str + " " + curElem[j];
		}
		console.log(output_str);
	}

	return;
}

var testArr = ["cat", "dog", "tac", "god", "act"];
printAllAnagramsInLine(testArr);

