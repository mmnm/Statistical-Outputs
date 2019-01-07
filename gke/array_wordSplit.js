
/* 

Consider the following dictionary 
{ i, like, sam, sung, samsung, mobile, ice, 
cream, icecream, man, go, mango}

Input:  ilike
Output: Yes 
The string can be segmented as "i like".

Input:  ilikesamsung
Output: Yes
The string can be segmented as "i like samsung" or "i like sam sung".
*/



var isInDictionary = function(word) {

  if(word === null) {
    return false;
  }

  var dictionary = {};
  dictionary["i"] = true;
  
  dictionary["like"] = true;
  dictionary["sam"] = true;
  dictionary["sung"] = true;
  dictionary["samsung"] = true;
  dictionary["mobile"] = true;
  dictionary["ice"] = true;

  if(word in dictionary) {
    return true;
  } else {
    return false;
  }

};

/*

"start" and "end", not including "end" itself.
var str = "Hello world!";
var res = str.substring(1, 4);

o/p : ell

At position 2, add the new items, and remove 1 item:

var fruits = ["Banana", "Orange", "Apple", "Mango"];
fruits.splice(2, 1, "Lemon", "Kiwi");

Banana,Orange,Lemon,Kiwi,Mango
*/

var breakValidWords = function(sub_str) {


  if(sub_str === null) {
    return [];
  }

  if(isInDictionary(sub_str)) {
    return [sub_str];
  }

  for(var i = 0; i < sub_str.length; i++) {
    var prefix = sub_str.substring(0, i + 1);
    var suffix = sub_str.substring(i + 1, sub_str.length);

    if(isInDictionary(prefix)) {



      var suffixOutputArray = breakValidWords(suffix);
      if(suffixOutputArray.length !== 0) {
//Append the prefix and return the result
suffixOutputArray.splice(0, 0, prefix);
return suffixOutputArray;

}

}

}


return [];


}


console.log(breakValidWords("ilike"));

console.log(breakValidWords("ilikesamsung"));

console.log(breakValidWords("ilikesyou"));




