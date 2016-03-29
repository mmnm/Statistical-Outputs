



//Fib numbers


//Bottom up O(n) space
var fib = function(n) {


	if(n <= 0) {
		return null;
	}



	//Lets do bottom up
	var fib = [];
	fib[0] = 0;
	fib[1] = 1;

	for(var i = 2; i <= n; i++) {
		fib[i] = fib[i - 1] + fib[ i - 2];

	}


	return fib[n];


}

//Bottom up O(1) space
var fib1 = function(n) {


	// O(1) Space complexity 
	if(n < 0) {
		return null;
	}



	//Lets do bottom up

	if(n === 1 || n === 0) {
		return n;
	}

	var prev1 = 0;
	var prev2 = 1;

	for(var i = 2; i <= n; i++) {
		var temp = prev1 + prev2;
		prev1 = prev2;
		prev2 = temp;


	}


	return temp;


}


//Meomized 
var arr_fib = [];
//Top down with memoization
var fib2 = function(n) {


	if(!(arr_fib[n] === undefined)) {
		console.log("Saving done");
		return arr_fib[n];
	}


	if(n === 0) {
		arr_fib[n] = 0;

	} else if( n === 1) {
		arr_fib[n] = 1;
		
	} else {

		arr_fib[n] =  fib2(n - 1) + fib2(n - 2);
	} 

	return arr_fib[n];


}




// Test cases
console.log(fib(4));

console.log(fib(5));
console.log(fib(6));
console.log(fib1(7));

// ----------
console.log(fib1(4));

console.log(fib1(5));
console.log(fib1(6));


console.log(fib1(7));


// --------------


console.log(fib2(4));

console.log(fib2(5));
console.log(fib2(6));


console.log(fib2(7));



