
//randomize an array




var randomize_array = function(sub_arr) {

	if(sub_arr === null) {
		return null;
	}

	if(sub_arr.length <= 1) {
		return sub_arr;
	}


	//Math.floor(Math.random()*(max-min+1)+min);

	var len = sub_arr.length - 1;
	for(var i = 0; i <= len; i++) {

		//Rand index would be between i and array_len - 1
		var rand_index = Math.floor(Math.random()*(len - i + 1) + i);
		//Swap these
		console.log("i val and rand_index are: ", i, ",", rand_index);
		var temp = sub_arr[rand_index];
		sub_arr[rand_index] = sub_arr[i];
		sub_arr[i] = temp;

	}

	return sub_arr;

}


console.log(randomize_array([1,2,3,4,5,6,7,8,9,10]));