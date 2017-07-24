/* 
    CONVERT TO ROMAN :: METHOD 1 ASSUMTION 
    MCMXCVI = 1996

  

*/


/**
 * @param {string} s
 * @return {number}
 */

var valueConvert = function(curRoman) {
    
    if(curRoman === null) {
        return null;
    }
    
    var retVal = 0;
    
    switch(curRoman) {
            
        case "I": 
            retVal = 1;
            break;
            
        case "V":
            retVal = 5;
            break;
            
        case "X": 
            retVal = 10;
            break;
            
        case "L":
            retVal = 50;
            break;
            
         case "C":
            retVal = 100;
            break;
            
        case "D": 
            retVal = 500;
            break;
            
        case "M":
            retVal = 1000;
            break;    
            
    };
    
    return retVal;
    
    
};

var isPrecedenceLow = function(cur, next) {
    
    var valueCur = valueConvert(cur);
    var valueNext = valueConvert(next);
    
    if(valueCur < valueNext) {
        return true;
    } else {
        return false;
    }
       
};

var romanToInt = function(s) {
  
    var totalVal = 0;
    
    
    for(var i = 0; i < s.length;) {
        
        var curVal = s[i];
        
        //Check for last case
        if(i === s.length - 1) {
            totalVal += valueConvert(curVal);
            break;
        }
        
        var nextVal = s[i + 1];
        
        if(isPrecedenceLow(curVal, nextVal)) {
            totalVal -= valueConvert(curVal);
            totalVal += valueConvert(nextVal);
            i += 2;
            
        } else {
            
            totalVal += valueConvert(curVal);
            i += 1;
        }
    

    }
    
    return totalVal;
    
};


