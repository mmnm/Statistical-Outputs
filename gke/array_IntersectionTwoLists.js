// intersection of two lists
  // i         k
//[2,3,4               ]   [3, 4]    --- [3,4]

// [2,2,3]     [2,2,3] 





var createHash = function(list) {

//Create list1 hash
var hashMap = {};
for(var i = 0; i < list.length; i++) {
 var cur = list[i];
 if(cur in hashMap) {
  hashMap[cur]++;
} else {
  hashMap[cur] = 1;
}
}

return hashMap;
}   


var formList = function(list, hashMap) {

  var output_list = []; 
  var output_list_hash = {};


  if(list === null || hashMap === null) {
    return output_list;
  }

  for(var i = 0; i < list.length; i++) {

   var cur = list[i];
   if(cur in hashMap) {
     if(!(cur in output_list_hash)) {
       output_list.push(cur);
       output_list_hash[cur] = 1;
     }
      
   } 

 }

 return output_list;
 
}

var intersectionList = function(list1, list2) {


  if(list1 === (undefined || null) && list2 === (undefined || null)) {
    return null;
  } else if(list1 === (undefined || null)) {
    return list2;
  } else if(list2 === (undefined || null)) {
    return list1;
  }

  var hashMap = {};
  var compareList1 = false;
 //Create Hash table for smaller one
 if(list1.length < list2.length) {

   hashMap = createHash(list1);
   compareList1 = true;

 } else {
   hashMap = createHash(list2);
 }
 
 if(compareList1 === true) {
   return formList(list2, hashMap);
 } else {

   return formList(list1,hashMap);

 }
 
 
}




// Test cases
console.log(intersectionList([2,3,4], [3,4]));
console.log(intersectionList([2,3,4], [3,4,4,4]));
console.log(intersectionList([2,3,4,4], [3,4,4,4]));
console.log(intersectionList([2], [2]));
console.log(intersectionList([2], [4]));
console.log(intersectionList([], []));













