/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * function NestedInteger() {
 *
 *     Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     @return {boolean}
 *     this.isInteger = function() {
 *         ...
 *     };
 *
 *     Return the single integer that this NestedInteger holds, if it holds a single integer
 *     Return null if this NestedInteger holds a nested list
 *     @return {integer}
 *     this.getInteger = function() {
 *         ...
 *     };
 *
 *     Return the nested list that this NestedInteger holds, if it holds a nested list
 *     Return null if this NestedInteger holds a single integer
 *     @return {NestedInteger[]}
 *     this.getList = function() {
 *         ...
 *     };
 * };
 */
/**
 * @param {NestedInteger[]} nestedList
 * @return {number}
 */
 
 var totalSumLevel = function(levels) {
     if(levels === undefined) {
         return 0;
     }
     var sum = 0;
     for(var key in levels) {
         sum += parseInt(key * levels[key]);
     }
     return sum;
     
     
 };
 
 
 var depthSumUtil = function(levelSum, curLevel, nestedList) {
     
     if(nestedList === null) {
         return;
     }
     
     for(var i = 0; i < nestedList.length; i++) {
         var curElem = nestedList[i];
         if(Array.isArray(curElem)) {
             depthSumUtil(levelSum, curLevel + 1, curElem);
         } else {
            if(curLevel in levelSum) {
             levelSum[curLevel] += curElem;
            } else {
                levelSum[curLevel] = curElem;
            }
         }
     }
     
 }
 
 
var depthSum = function(nestedList) {
    
    if(nestedList === null || nestedList === undefined) {
        return 0;
    }
    
    var levelSum = {};
    var curLevel = 1;
    
    depthSumUtil(levelSum, curLevel, nestedList);

    return totalSumLevel(levelSum);
    
};

console.log(depthSum([[1,1],2,[1,1]]));
console.log(depthSum([1,[4,[6]]]));



