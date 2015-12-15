/*
the first 12 digits of pi are 314159265358. 
We can make these digits into an expression evaluating to 27182 (first 5 digits of e) as follows:

3141 * 5 / 9 * 26 / 5 * 3 - 5 * 8 = 27182
or
3 + 1 - 415 * 92 + 65358 = 27182

Notice that the order of the input digits is not changed. Operators (+,-,/, or *) are simply inserted to create the expression.

Write a function to take a list of numbers and a target, and return all the ways that those numbers can be formed into expressions evaluating to the target

For example:
f("314159265358", 27182) should print:

3 + 1 - 415 * 92 + 65358 = 27182
3 * 1 + 4 * 159 + 26535 + 8 = 27182
3 / 1 + 4 * 159 + 26535 + 8 = 27182
3 * 14 * 15 + 9 + 26535 + 8 = 27182
3141 * 5 / 9 * 26 / 5 * 3 - 5 * 8 = 27182
*/



var f = function(numbers, sum) { 

  for(var i = 1; i <= numbers.length; i++) {
   var cur = numbers.substr(0, i);
    printSum(0, parseFloat(cur), numbers.substr(i), sum, cur);
  }
}

var printSum = function(sum, prev, digits, target, expr) {

  if(digits.length === 0) {
    if( (sum + prev) === target ) {
      console.log(expr + " = " + target);
    }
  } else {

    for(var i = 1; i <= digits.length; i++) {
      
      var cur = parseFloat(digits.substr(0, i));
      var remaining = digits.substr(i);


      printSum(sum + prev, cur, remaining, target, expr + " + " + cur);
      printSum(sum, prev * cur, remaining, target, expr + " * " + cur);
      printSum(sum, prev / cur, remaining, target, expr + " / " + cur);
      printSum(sum + prev, -cur, remaining, target, expr + " - " + cur);

    } 
  
  }
  
}

//Test This
f("314159265358", 27182)


