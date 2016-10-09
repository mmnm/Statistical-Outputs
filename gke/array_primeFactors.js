var primeFactorization = function(number_input) {


  if(number_input === null) {
    return null;
  }

  if(number_input === 0) {
    return [];
  }


  var output_arr = [];
//12 % 2   ; 12 / 2 --  3   [2, 2, 

// var max_counter = number_input;

for(var i = 2; i <= number_input; i++) {

  var curInput = i;

  if(number_input === 1) {
    break;
  }


  while((parseInt(number_input % curInput) === 0)){
    number_input = parseInt(number_input/curInput);
    output_arr.push(curInput);
  }

}

return output_arr;



}

//Test cases
console.log(primeFactorization(12));
console.log(primeFactorization(15));
console.log(primeFactorization(2));
console.log(primeFactorization(1));
console.log(primeFactorization(0));
console.log(primeFactorization(7));
