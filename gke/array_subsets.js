/*
 * Return an array with the power set of a given string.
 * Definition of power set: The set of all possible subsets including the empty set.
 *
 * Example:
 *
 * powerSet("abc")
 * -> [ '' , 'a', 'b', 'c', 'ab', 'ac', 'bc', 'abc' ]
 *
 * Note: 
 *  1. All characters in a subset should be sorted.
 *  2. Sets of the same characters are considered duplicates regardless of order and count only once, e.g. 'ab' and 'ba' are the same. 
 * 
 * Example 2 :
 * 
 * powerSet("jump")
 * -> ["", "j", "ju", "jm", "jp", "jmu", "jmp", "jpu", "jmpu", "u", "m", "p", "mu", "mp", "pu", "mpu"]
 */



 var output = [];
 var powerSet = function(str){
	//Calculate max size for the subset
	var superSetSize;

	superSetSize = (2 << str.length - 1);
	console.log(superSetSize);


	//Now print the combination sets
	for (var i = 0; i < superSetSize; i++) {

		var subset = [];
		var k = 1;
		for (var j = 0; j < str.length; j++) {

			if(i & k) {
				subset.push(str[j]);		
			}
			k = k << 1;
		}

		var loc = subset.slice();
		output.push(loc);


	}


}

console.log(powerSet([1,2,3]));
console.log(output);