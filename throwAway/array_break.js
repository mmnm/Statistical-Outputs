var hash_dict = {};
var hash_answer = {};
var count = 0;

var initDict = function(dict_arr) {
  
  hash_dict = {};
  
  for(var i = 0; i < dict_arr.length; i++) {
    
    var curElem = dict_arr[i];
    
    hash_dict[curElem] = true;
  };
  
};

var isInDict = function(word) {
  
  
  if(word in hash_dict) {
    return true;
  }
  
  return false;
};


var word_break = function(words_str, dict_arr) {
  

  
  count = 0;
  
  if(words_str === null || words_str.length <= 0) {
    return [];
  }
  
  initDict(dict_arr);
  hash_answer = {};
  
  
  return word_break_util(words_str);
  
};


var word_break_util = function(words_str) {
  
  
  if(words_str in hash_answer) {
    return hash_answer[words_str];
  }
    
  count++;
  console.log("Word break Util called for: ", words_str, " and count: ", count);
  
  
 //Error checks
  
  //i + likesamsung
  var output = [];
  
  if(words_str === null || words_str.length === 0) {
    return output;
  }
  
  for(var i = 0; i < words_str.length; i++) {
    
    // 0...i
    var prefix = words_str.substr(0, i + 1);
    
    if(isInDict(prefix)) {
      
      //i + 1 to end
      var suffix = words_str.substr(i + 1);
      
      if(suffix.length === 0) {
        
        output.push(prefix);
        hash_answer[words_str] = output;
        return output;
      
      }
      
      var ret_arr = word_break_util(suffix);
      
      if(ret_arr.length !== 0) {
        
        //Found a valid word break
        output.push(prefix);
        output = output.concat(ret_arr);
        hash_answer[words_str] = output;
        return output;
      }
      
    }
  }
  
  hash_answer[words_str] = output;
  return output;

};

console.log(word_break("ilikesamsungilikesamsung", ["i", "like", "sam", "sung", "samsung", "mobile", "ice", 
  "cream", "icecream", "man", "go", "mango"]));



