/**
 * @param {number} num
 * @return {string}
 */
var numberToWords = function(num) {
    
    var singles = ["Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"];
    var doubles = 
    ["Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"];
    var doubles_plus = ["Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"];
    var triples = ["", "Hundred", "Thousand", "Million", "Billion"];
    
    var output = [];
    
    if(num < 10 && num >= 0) {
        return singles[num];
    } else if(num >= 10 && num < 20) {
        return doubles[num - 10];
    }
    var trip_dig = 0;
    
    while(num !== 0) {
    
  
    if(trip_dig !== 0) {
       
        var curElem = triples[trip_dig + 1];
        
        if(curElem !== "") {
           output.unshift(curElem);
        }
    }
    trip_dig++;
  
     //Process in triplets form 
     
     var curNum = parseInt(num % 10);
     num = parseInt(num / 10);
     var nextDigit = -1;
     
     if(num !== 0) {
         nextDigit = parseInt(num % 10);
         num = parseInt(num / 10);
     }
   
     var doubleElem = "";
     //Process doubles
     if(nextDigit !== -1) {
         if(nextDigit === 0) {
             if(curNum === 0) {
                doublesElem = ""; 
             } else {
                doubleElem = singles[curNum]; 
             }
             
         } else if(nextDigit === 1) {
             doubleElem = doubles[curNum];
         } else {
             if(curNum === 0) {
                 doubleElem = doubles_plus[nextDigit - 2];
             } else {
             doubleElem = doubles_plus[nextDigit - 2] + " " + singles[curNum];
             }
         }
     } else {
         doubleElem = singles[curNum];
     }
     var tripletDigit = -1;
     //Work on triplet digit 
     if(num !== 0) {
         tripletDigit = parseInt(num % 10);
         num = parseInt(num / 10);
     } 
     if(doubleElem !== "") {
       output.unshift(doubleElem);  
     }
     if(tripletDigit !== -1) {
        if(tripletDigit === 0) {
            var triplet = "";
        } else {
         triplet = singles[tripletDigit] + " " + triples[1];
        }
         if(triplet !== "") {
         output.unshift(triplet);
         }
     }

     if(trip_dig !== 0) {
        if((num !== 0) && (curNum === 0) &&
           (nextDigit === 0) && (tripletDigit === 0)) {
            output.splice(0, 1);
        }
     }
        
    }
     
   console.log(output);
    
    return output.join(' ');
    
};