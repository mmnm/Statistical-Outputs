/* Write a function to check parenthesis match. 
Only one type of parenthesis is
provided. 
You can not use stack
E.g, 

Valid: "((()))"
Valid: "(())(())"
       "((()()()))"

Empty string may be considered valid

*/


var isValidParen = function(expression) {

	if(expression === null || expression === undefined) {
		return false;
	}



	var count = 0;

	for(var i = 0; i < expression.length; i++) {

		if(count < 0) {
			return false;
		}

		var curElem = expression[i];

		if(curElem === "(") {
			count++;
		} else if(curElem === ")"){
			count--;
		} else {
			console.log("Invalid input expression");
			return false;
		}

	}

	if(count === 0) {
		return true;
	} else {
		return false;
	}

}

console.log(" is valid ? ", isValidParen(""));
console.log("((())) is valid ? ", isValidParen("((()))"));
console.log("(())(())is valid ? ", isValidParen("((())(())"));
console.log("((()()())) is valid ? ", isValidParen("((()()()))"));
console.log("(( is valid ? ", isValidParen("(("));
console.log(")) is valid ? ", isValidParen("))"));
console.log("()))(()) is valid ? ", isValidParen("()))(())"));


