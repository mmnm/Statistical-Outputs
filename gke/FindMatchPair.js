/* 
"Sometimes (when I nest them (my parentheticals) 
too much (like this (and this))) they get confusing."

Write a function that, given a sentence like the one above,
 along with the position of an opening parenthesis, 
 finds the corresponding closing parenthesis.

*/





var findParantheticalPosition = function(sub_str, initPos) {


	if(sub_str === null) {
		return -1;
	}

	if((initPos >= sub_str.length) || (initPos < 0)) {
		return -1;
	}

	if(sub_str[initPos] !== '(') {
		return -1;
	}
	var count = -1;

	for(var i = initPos + 1; i < sub_str.length; i++) {
		
		var cur = sub_str[i];
		if(cur === ')') {
			count++;
		} else if(cur === '(') {
			count--;
		}

		if(count === 0) {
			return i;
		}


	}

	return -1;
}

var str1 = 
"Sometimes (when I nest them (my parentheticals) too much (like this (and this))) they get confusing."

console.log(findParantheticalPosition(str1, 10));





