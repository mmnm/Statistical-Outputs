
/*
Find minimum nunber of coins

Given coins with values 1, 3, and 5.
And the sum S is set to be 11.
*/



var mincoins = function(coin_arr, totalsum) {


	//Build the sum array and return for totalsum
	if(coin_arr === null || coin_arr === undefined) {
		return -1;
	}

	var sumArr = [];

	//Specify an initial default state
	for(var i = 0; i <= totalsum; i++) {
		sumArr[i] = Number.MAX_VALUE;
	}


	//Now build this array
	sumArr[0] = 0;

	for(var i = 1; i <= totalsum; i++) {


		//Go through the coin_arr to see if solution can be found
		for(var j = 0; (j < coin_arr.length) && (coin_arr[j] <= i); j++) {

			var partial_sum = i - coin_arr[j];
			//Sum exists
			if(sumArr[partial_sum] !== Number.MAX_VALUE) {
				//Solution found, check if it is the smaller solution
				if( ((sumArr[partial_sum] + 1) < sumArr[i]) ) {
					sumArr[i] = 1 + sumArr[partial_sum];
				}
			}

		}

	}

	return sumArr[totalsum];

}

console.log(mincoins([1,3,5], 11));






