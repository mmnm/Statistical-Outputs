var pow2 = function(elem) {
	if(elem === null) {
		return null;
	}

	var output = 1;
	for(var i = 0; i < elem; i++) {
		output *= 2;
	}

	return output;


}

var convertBinary = function(num) {

	if(num === null) {
		return null;
	}

	var output = []
	while(num !== 0) {

		var remainder = parseInt(num % 2);
		output.push(remainder);
		num = parseInt(num / 2);
	}

	return output;

}

var curOutput = function(binary, sub_str) {

	if(binary === null || sub_str === null) {
		return null;
	}

	var output = [];
	for(var i = 0; i < sub_str.length; i++) {

			var binaryElem = binary[i];

			if(binaryElem === 1) {
				output.push(sub_str[i]);
			}


	}

	return output.join('');

}


var printPerm = function(sub_str) {

	if(sub_str === null) {
		return null;
	}

	var answer = [];
	var answer_len = pow2(sub_str.length);
	var curElem = '';

	for(var i = 0; i < answer_len; i++) {
		// debugger;
		var curElem = i;
		var binary = convertBinary(curElem);

		var cur = curOutput(binary, sub_str);

		answer.push(cur);

	}

	return answer;

}



console.log(printPerm("abc".split('')));
console.log(printPerm("ab".split('')));
console.log(printPerm("a".split('')));
console.log(printPerm("".split('')));


