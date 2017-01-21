/*

# input: “iamhappy” (all chars must be used, and can only be used once. 
The given string is guaranteed to be able to split into valid words)
# output: ["i", "am", "happy"]

# (Returns T/F)
def _is_word_in_dictionary(given_string):
 return given_string in ("i", "a", "am", "happy", "after", "noon", "afternoon", "elephant", "ant", "antelope")


Debugging errors: Things I re-learnt debugging this:

1. The return type of all library functions is some status code so 
					Error code: //return array1.push(array2);
					will just return the status code and not actual array
					The correct version is below if you wanted to return the 
					array1
					Correct code:
					// array1.push(array2);
					//return array1;

2. If copying and modifying the local parameter in a loop for a variable
always take a sliced copy and not just assignment
Error code: //for(var i = 0; i < cur_str.length; i++) {
								//var locStr = cur_str;
Correct code: //for(var i = 0; i < cur_str.length; i++) {
									//var locStr = cur_str.slice();


3. Always check what is passed to a function while working with arrays and
		strings while using split, join or performing modifications to array
		E.g, isWordInDictionary function expects a string as input, so pass
		a string and not an array
		Error code: //var leftPortion = locStr.splice(0, i + 1);
								//isWordInDictionary(leftPortion);
		Correct code: 
								//var leftPortion = locStr.splice(0, i + 1).join('');
								////isWordInDictionary(leftPortion);


*/






var isWordInDictionary = function(given_string) {

	if(given_string === null) {
		return false;
	}


	var curDictionary = {"i":true, "a":true, "am":true, "happy":true, 
											"after":true, "noon":true, "afternoon":true, 
											"elephant":true, "ant":true, "antelope":true};

	if(given_string in curDictionary) {
		// debugger;
			// console.log("Yo", given_string);
		return true;
	} else {
		return false;
	}

};


/*

Example
At position 2, add the new items, and remove 1 item:

var fruits = ["Banana", "Orange", "Apple", "Mango"];
fruits.splice(2, 1, "Lemon", "Kiwi");
The result of fruits will be:

Banana,Orange,Lemon,Kiwi,Mango

*/




var splitWords = function(cur_str) {

	if(cur_str === null || cur_str === undefined) {
		return null;
	}

	var curWord = "";

	for(var i = 0; i < cur_str.length; i++) {
		var locStr = cur_str.slice();
		var leftPortion = locStr.splice(0, i + 1).join('');


		if(isWordInDictionary(leftPortion)) {

				var curWords = [];
				if(locStr.length === 0) {
					curWords.push(leftPortion);
					return curWords;
				}

				curWords = splitWords(locStr);
	
				console.log("Yo", curWords);
				if(curWords !== null) {
					console.log("split: ", curWords)
					curWords.unshift(leftPortion);
					return curWords;
				}

		}

}

return null;

}

console.log(splitWords("iamhappy".split("")));
