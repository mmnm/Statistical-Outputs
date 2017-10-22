/**
 * @param {string} s
 * @param {string} p
 * @return {number[]}
 */


/* 
1. Idea is keep a rolling hash of size p.length; 
2. For each new i ... n , check if all elems in p are in rolling hash
    If yes, put the index in result list
    
    "cbaebabacd"
        rollhash
        c b a
        
        b a e
        
        abab
        
        a b  a
        1 1
        
        0 0 
        
        copyrollhash
        
    
    TC = O(n * 1(ammorized))
    
*/

var sameHashCount = function(s_hash, p_hash) {
    
    for(var key in p_hash) {
        if(p_hash[key] !== s_hash[key]) {
            return false;
        }
    }
    
    return true;
}


var findAnagrams = function(s, p) {
    
    var countHash_s = {};
    var countHash_p = {};
    var output = [];
    
    if(p.length > s.length) {
        return output;
    }
    
    //Assume 256 chars max - ascii unicode encoding - 1 byte
    
    //Create hash for p
    for(var i = 0; i < p.length; i++) {
        var curElem = p[i];
        
        if(curElem in countHash_p) {
            countHash_p[curElem] += 1;
        } else {
            countHash_p[curElem] = 1;
        }
    }
    
    //Create init s_hash of length p.length
     //Create hash for s
    for(var i = 0; i < p.length; i++) {
        var curElem = s[i];
        
        if(curElem in countHash_s) {
            countHash_s[curElem] += 1;
        } else {
            countHash_s[curElem] = 1;
        }
    }
    
    //Now check remaining in rolling fashion
    var max_len = s.length - p.length + 1;
    
    for(var i = 0; i < max_len; i++) {
        
        if(sameHashCount(countHash_s, countHash_p)) {
            output.push(i);
        }
        
        // Break out for last entry
        if(i === max_len - 1) {
            break;
        }
        
        //Update hash for next entry
        var next_elem = s[i + p.length];
        
        //Substact ith entry from hash and add next_elem
        countHash_s[s[i]] -= 1;
        
        if(next_elem in countHash_s) {
            countHash_s[next_elem] += 1;
        } else {
            countHash_s[next_elem] = 1;
        }
           
    }

    return output;
};


console.log(findAnagrams("cbaebabacd", "abc"));

