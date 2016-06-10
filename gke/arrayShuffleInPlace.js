


/* Shuffle an array inplace with each element having equal chance of fairness
*/

var getRandIndex = function(min, max) {

	//returns a random element between start and end

	return Math.floor(Math.random() * (max - min + 1)) + min;
}


var inplaceShuffle = function(sub_arr) {

// debugger;
	if(sub_arr === null) {
		return null;
	}

	/* 
	take one random element, place it on the first; take another random 
	elem from remaining and place and so forth.....	

	*/

	for(var i = 0; i < sub_arr.length - 1; i++) {

		var rand_index = getRandIndex(i + 1, sub_arr.length - 1);
		//Now swap this index with the current index

		var curElem = sub_arr[i];
		sub_arr[i] = sub_arr[rand_index];
		sub_arr[rand_index] = curElem;


	}
	console.log("Yayyy");
	return sub_arr;

}

var array1 = [1,2,3,4,5,6,7,8,9,10];

console.log(inplaceShuffle(array1));






