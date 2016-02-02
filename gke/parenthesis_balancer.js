//Solving for a parentheses balancer
//input -> arithmetic expression
//output -> false, true
//1. (a+b) -> true
//2. (a+b)) -> false
// (a + b) + (c + d)()

//((a + b)c)

var isValid = function(string_val) {
  
  if(string_val === null || string_val.length <= 0) {
    return true;
  }
  
  var count_par = 0;
  var len = string_val.length;
  
  for(var i = 0; i < len; i++) {
    
    var cur_elem = string_val[i];
    
    if(cur_elem === '(') {
      count_par++;
    } else if(cur_elem === ')') {
      count_par--;
    }
    
    if(count_par < 0) {
      return false;
    }
    
  }
  
  if(count_par === 0) {
    return true;
  } else {
    return false;
  }
  
  
}

console.log(isValid("(a + b)"));
console.log(isValid("(a + b))"));
console.log(isValid(""));
console.log(isValid("(a)"));

console.log(isValid(")a("));



