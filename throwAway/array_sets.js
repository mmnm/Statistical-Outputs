
/* 
Generate all unique perms of a set 
abc - > [""], [a], [b],[c], [a,b],[b,c], [c,a], [a,b,c]

It looks like the answer scenario is 2powelems
if we append binary value, then it serves

*/


var power2 = function(num) {
  
  var elem = 1;
  for(var i = 0; i < num; i++) {
    elem *= 2;
  }
  return elem;
}

var generateSet = function(num, sub_arr) {
  
 var curSet = [];
  
  for(var i = 0; i < sub_arr.length; i++) {
    var curElem = sub_arr[i];
  
    if((num & (1 << i)) > 0) {
      curSet.push(curElem);
    }
  
  }
  return curSet.join('');
    

}


var generateSets = function(sub_arr) {
  
  
  if(sub_arr === null) {
    return [];
  }
  
  
  var answer_len = power2(sub_arr.length);
  var answer = [];
  
  for(var i = 0; i < answer_len; i++) {
   
    var curSet = generateSet(i, sub_arr);
    answer.push(curSet);
  
  }
  
  return answer;

  
}


console.log(generateSets("abc".split('')));





