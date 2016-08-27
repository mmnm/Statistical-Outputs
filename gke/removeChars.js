
/*
Remove characters from the first string which are present in the second string
Write an efficient C function that takes two strings as arguments and
removes the characters from first string which are present in second string 
(mask string).

Example 
char str[]         = "geeksforgeeks";
char mask_str[]  = "mask";

Output: geeforgee


*/



var removeCharsFromFirstStr = function(str1, str2) {

	var output_str = [];

//Create a hashObj for second string

var hash_str2 = {};

for(var i = 0; i < str2.length; i++) {

	var cur = str2[i];

	if(!(cur in hash_str2)) {
		hash_str2[cur] = true;
	}

}


//Now process the resulting string

for(var i = 0; i < str1.length; i++) {

	var cur = str1[i];

	if(!(cur in hash_str2)) {
		output_str.push(cur);
	}

}

return output_str.join('');

}

console.log(removeCharsFromFirstStr("geeksforgeeks", "mask"));


