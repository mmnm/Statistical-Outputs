
	/* 


	Write an efficient function that checks whether any permutation 
	↴ of an input string is a palindrome ↴ .
	Examples:

	"civic" should return true
	"ivicc" should return true
	"civil" should return false
	"livci" should return false

	*/




	var anyPairIsPalindrome = function(sub_str) {

		if(sub_str === null) {
			return false;
		}

		var hashPairSeen = {};


		for(var i = 0; i < sub_str.length; i++) {

			var cur = sub_str[i];

			if(cur in hashPairSeen) {
				delete hashPairSeen[cur];
			} else {
				hashPairSeen[cur] = true;
			}

		}

		if(Object.keys(hashPairSeen).length > 1) {
			return false;
		} else {
			return true;
		}


	}


	console.log(anyPairIsPalindrome("civic"));
	console.log(anyPairIsPalindrome("ivicc"));
	console.log(anyPairIsPalindrome("civil"));
	console.log(anyPairIsPalindrome("livci"));




