/*
  var words = [
    'ptolemaic',
    'retrograde',
    'supplant',
    'undulate',
    'xenoepist',
    'asymptote', // <-- rotates here!
    'babka',
    'banoffee',
    'engender',
    'karpatka',
    'othellolagkage',
];

Write a function for finding the index of the "rotation point,"
 which is where I started working from the beginning of the dictionary. 
 This array is huge (there are lots of words I don't know) so we want to be efficient here.
 */

//Returns true if string2 is greater than string1 else false

var isGreater = function(string1, string2) {


	for(var i = 0, j = 0; i < string1.length || j < string2.length; i++, j++) {

		if(i < string1.length && j < string2.length) {

			if(string1.charCodeAt(i) === string2.charCodeAt(j)) {
				continue;
			} else if(string1.charCodeAt(i) > string2.charCodeAt(j)) {
				return false;
			} else if(string1.charCodeAt(i) < string2.charCodeAt(j)) {
				return true;
			}

		} else if(i < string1.length) {
			return true;
		} else if(j < string2.length) {
			return false;
		}

	}


}


var findRotatePointUtil = function(words, start , end) {


	if(start > end) {
		return 0;
	}

	var middle = parseInt((start + end) / 2);

	if((middle - 1) < 0) {
		return -1;
	}

	if(!isGreater(words[middle - 1], words[middle])) {
		return middle;
	} else if(isGreater(words[start], words[middle - 1]) || (middle === start)) {
		return findRotatePointUtil(words, middle + 1, end);
	} else {
		return findRotatePointUtil(words, start, middle - 1);
	}


}


var findRotatePoint = function(words) {

	return findRotatePointUtil(words,  0, words.length - 1);


}



// Test cases
 var words = [
    'ptolemaic',
    'retrograde',
    'supplant',
    'undulate',
    'xenoepist',
    'asymptote', // <-- rotates here!
    'babka',
    'banoffee',
    'engender',
    'karpatka',
    'othellolagkage',
];

console.log(findRotatePoint(words));


// --------------------

 var words1 = [
    'undulate',
    'xenoepist',
    'asymptote', // <-- rotates here!
    'babka',
    'banoffee',
    'engender',
    'karpatka',
    'othellolagkage',
    'ptolemaic',
    'retrograde',
    'supplant'
];

console.log(findRotatePoint(words1));


// --------------------

// --------------------

 var words2 = [
    'asymptote', // <-- rotates here!
    'babka',
    'banoffee',
    'engender',
    'karpatka',
    'othellolagkage',
    'ptolemaic',
    'retrograde',
    'supplant',
    'undulate',
    'xenoepist'
];

console.log(findRotatePoint(words2));


// --------------------
//Test cases
 var words3 = [
   	
    'banoffee',
    'engender',
    'karpatka',
    'othellolagkage',
    'ptolemaic',
    'retrograde',
    'supplant',
    'undulate',
    'xenoepist',
    'asymptote', // <-- rotates here!
    'babka'
];

console.log(findRotatePoint(words3));


// --------------------



 var words4 = [
   	'babka',
    'banoffee',
    'engender',
    'karpatka',
    'othellolagkage',
    'ptolemaic',
    'retrograde',
    'supplant',
    'undulate',
    'xenoepist',
    'asymptote' // <-- rotates here!
    
];

console.log(findRotatePoint(words4));
