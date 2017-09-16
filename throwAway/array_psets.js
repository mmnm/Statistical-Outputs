



/* 
Power Set
Power Set Power set P(S) of a set S is the set of all subsets of S. For example S = {a, b, c} then P(s) = {{}, {a}, {b}, {c}, {a,b}, {a, c}, {b, c}, {a, b, c}}.


  */

var power2 = function(len) {
  
  
  if(len === undefined || len === 0) {
    return 0;
  }
  var answer = 1;
  for(var i = 0; i < len; i++) {
    answer *= 2;
  }
  
  return answer;
  
};



var gen_set = function(num, sub_arr) {

  
  
  var ans = [];
  
  for(var i = 0; i < sub_arr.length; i++) {
    
   
    var mask = 1 << i;

    if((mask & num) > 0) {

      
      ans.push(sub_arr[i]);
    }
  }
  
   // console.log("Returning" , ans);
  return ans;
  
};
    
    

var powerSet = function(sub_arr) {
  
  var output = [];
  
  if(sub_arr === null || sub_arr.length === 0) {
    return output;
  }
  
  var answer_len = power2(sub_arr.length);
  
  for(var i = 0; i < answer_len; i++) {
    
    var cur_output = gen_set(i, sub_arr);
    output.push(cur_output);
  }
  return output;
  
};

console.log(powerSet(["a", "b", "c"]));
console.log(powerSet(["a"]));
console.log(powerSet(["a", "b"]));  
    
  
  
  
                         
                         
                         
                  


  
  





