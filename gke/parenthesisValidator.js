/* 
Write an efficient function that tells us whether or not an input 
string's openers and closers are properly nested.

Examples:

"{ [ ] ( ) }" should return true
"{ [ ( ] ) }" should return false
"{ [ }" should return false


{ [ (     }

*/


var pairOf = function(elem) {

	if(elem === null) {
		return -1;
	}


	switch(elem) {

		case "{": return "}";
		case "(": return ")";
		case "[": return "]";
	
	};

	return -1;

}

var isClosingBrace = function(elem) {

	if( (elem === "}") || (elem === ")") || (elem === "]") ) {
		return true;
	} else {
		return false;
	}

}


var validateString = function(sub_str) {

	if(sub_str === null) {
		return -1;
	}

	var validatorStack = [];

	for(var i = 0; i < sub_str.length; i++) {

		var cur = sub_str[i];

		if(isClosingBrace(cur)) {
			var popElem = validatorStack.pop();
			if( (popElem === undefined) || !(pairOf(popElem) === cur) ) {
				return false;
			}

		} else {
			validatorStack.push(cur);
		}

	}

	if(validatorStack.length !== 0) {
		return false;
	}

	return true;


}



var str1 = "{ [ ] ( ) }";
var str2 = "{ [ ( ] ) }";
var str3 = "{ [ }";



console.log(validateString(str1.split(' ')));
console.log(validateString(str2.split(' ')));
console.log(validateString(str3.split(' ')));




