



//Fib numbers



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


console.log(fib(4));

console.log(fib(5));