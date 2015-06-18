function myFunction() {
    var low, high, text;
    var outputArr = [];

    // Get the value of the input field with id="numb"
    low = document.getElementById("numb").value;
    high = document.getElementById("numbhigh").value;
    text = "Default";    

// If x is Not a Number or less than one or greater than 10
    if ( isNaN(low) || isNaN(high) || (low > high) || (low < 0) 
	|| (high < 0) || (low % 1 != 0) ||(high % 1 != 0) ) {
        text = "Invalid, please enter +ve non-decimal numbers " +  
		"such that num2 > num1";
    } else {
        for(var i = low; i <= high; i++) {
		if( !(i % 5) && !(i % 3) ) {
			outputArr.push("FizzBuzz")
		} else if ( !(i % 3) )
			outputArr.push("Fizz");
		else if( !(i % 5) )
			outputArr.push("Buzz");
		else
			outputArr.push(i);
	}
        text = outputArr.join(", ");

    }
	

	document.getElementById("demofizz").innerHTML = text;
}
