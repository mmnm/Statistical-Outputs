const _ = require('lodash');
var max = Number.MIN_VALUE;

var maxValue = function(array1) {

  maxValueHelper(array1);
  // console.log("Max: ", max);
  return max;

}

var maxValueHelper = function(array1) {
 
  
  for(var i = 0; i < array1.length; i++) {

    var curElem = array1[i];

    if(Array.isArray(curElem)) {
      maxValueHelper(curElem);
    } else {
     //It is a Number
     if(!(Number.isInteger(curElem))) {
       console.log("Something wrong: Debug");
       return;
     }
     if(max < curElem) {
       max = curElem;
     }
    }

  }



}
//Test cases
console.log(maxValue([1,2,3]));
console.log(maxValue([1,[2,3,9],5]));
console.log(maxValue([1, 2, [3, 7, [11, 22], 13], 19, 20]));

