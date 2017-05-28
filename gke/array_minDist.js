/**
 * @param {string[]} words
 * @param {string} word1
 * @param {string} word2
 * @return {number}
 */
var shortestDistance = function(words, word1, word2) {
    
    var min_Dist = Number.MAX_SAFE_INTEGER;
    var nextSearch = 0; // -1 search for both word1, word2, 
                        // 1 search for word1, 2 search for word2
                        
    var curIndex = -1;
    
    for(var i = 0; i < words.length; i++) {
        var curElem = words[i];
        var curDis = 0;
        if(curElem === word1) {
            if(nextSearch === 0) {
                
                nextSearch = 2;
                curIndex = i;
                
            } else if(nextSearch === 1) { //word2 already found before
                curDis = Math.abs(curIndex - i);
                if(min_Dist > curDis) {
 
                    min_Dist = curDis;
                }
                nextSearch = 2; //Search for word1
                curIndex = i;
            } else if(nextSearch === 2) { //word1 found again
                curIndex = i;
            }
        } else if(curElem === word2) {
           if(nextSearch === 0) {
                curIndex = i;
                nextSearch = 1;
            
            } else if(nextSearch === 2) { 
                curDis = Math.abs(curIndex - i);
                if(min_Dist > curDis) {
                    min_Dist = curDis;
                }
                nextSearch = 1; //Search for word1
                curIndex = i;
            } else if(nextSearch === 1) { //word1 found again
                curIndex = i;
            }
        }
    
        
    }
    return min_Dist;
    
    
    
};

console.log(shortestDistance(["a","c","b","a"],"a","b"));
