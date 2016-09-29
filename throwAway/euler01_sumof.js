/* 
Find the sum of all the multiples of 3 or 5 below 1000.

*/



var sumOf3And5 = function(n) {

	if(n < 3) {
		return 0;
	}

	var sum = 0;
	for(var i = 0; i < n; i++) {

		if((i % 3 === 0) || (i % 5 === 0)) {
			sum += i;
		}

	}

	return sum;

}

console.log(sumOf3And5(1000));