
/* Write a program to find all distint sets of an input

E.g abc = a, b, c, ab, bc, ac, '', abc 

000
001
010
011
111


*/

var power2 = function(str_len) {
  
  if(str_len === null) {
    return 0;
  }
  var answer = 1;
  for(var i = 0; i < str_len; i++) {
    answer *= 2;
  }
  
  return answer;
  
}

// 0101  & 1

var generateSet = function(num, str) {
  
 var output = [];
  
  for(var i = 0; i < str.length; i++) {
   
    //Extract ith bit of number
    var curBit = num & (1 << i);
    
    if(curBit > 0) {
      output.push(str.charAt(i));
    }
  }
  
  return output.join('');
  
}
  
var allUniqueSets = function(string1) {
  
 if(string1 === null) {
   return null;
 }

  var str_len = string1.length;
  
  var output = [];
  var output_len = power2(str_len);
  
  //Traverse from  0 to output_len - 1
  for(var i = 0; i < output_len; i++) {
   
    var cur_output = generateSet(i, string1);
    output.push(cur_output);
  
  }
  
  return output;
}



console.log(allUniqueSets("abc"));
console.log(allUniqueSets(""));
console.log(allUniqueSets("a"));



/* 

Split words into valid words from dictionary. If no such combination possible,
then return false; 

*/




var isValidWord = function(sub_str) {
  
  if(sub_str.length === 0) {
    return false;
  }
  
 var dictionary = {

"i":true, "like":true, "sam":true, "sung":true, "samsung":true, "mobile":true, 
"ice":true, "cream":true, "icecream":true, "man":true, "go":true, "mango":true
};

  if(sub_str in dictionary) {
    return true;
  } else {
    return false;
  }
  
  
}



var splitValidWords = function(sub_str) {
  
  console.log(sub_str, sub_str.length);
  if(sub_str === null) {
    return null;
  }
  if(sub_str === "") {
    return [];
  }
  

  
  var output = [];
  
  for(var i = 0; i < sub_str.length; i++) {
    //console.log("i", sub_str.length);
    var prefix = sub_str.substr(0, i + 1);

  
    if(isValidWord(prefix)) {
  
      var suffix = 
          sub_str.substr(i + 1, sub_str.length - 1);
      console.log("Suffix: ", suffix);
      
      var suffix_output = splitValidWords(suffix);
      
      if(suffix_output === null) {
        continue;
      } else {
        
        suffix_output.unshift(prefix);
        return suffix_output;
      }
 
  }
    
 }

  return null;
  
}

  
console.log(splitValidWords("ilikesamsungmobile"));






